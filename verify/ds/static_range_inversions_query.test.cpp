#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "lib/internal.hpp"
#include "lib/misc/mo.hpp"

struct fenwicktree
{
  int n;
  int all;
  std::vector<int> f;
  fenwicktree(int n) : n(n), all(0), f(n) {}

  void add(int x, int v)
  {
    all += v;
    for (x++; x <= n; x += x & -x)
      f[x - 1] += v;
  }

  int prod_prev(int x) const
  {
    int res = 0;
    for (; x > 0; x -= x & -x)
      res += f[x - 1];
    return res;
  }

  int prod_all() const { return all; }
};

struct SqrtDecomposition
{
  int n;
  int block_size, block_cnt;
  int all;
  std::vector<int> b;
  std::vector<int> bs;
  SqrtDecomposition(int n)
      : n(n), block_size((int)std::sqrt(n)),
        block_cnt((n + block_size - 1) / block_size), all(0), b(n + 1),
        bs(block_cnt + 1)
  {
  }

  void add(int x, int v)
  {
    all += v;
    int bx = x / block_size;
    for (int i = x, j = x % block_size; i < n && j + 1 < block_size; i++, j++)
      b[i + 1] += v;
    for (int i = bx; i < block_cnt; i++)
      bs[i + 1] += v;
  }

  int sum(int x) const
  {
    int bx = x / block_size;
    int res = bs[bx];
    if (bx < block_cnt) res += b[x];
    return res;
  }

  int sum_all() const { return all; }
};

int main()
{
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto &i : a)
    std::cin >> i;
  auto cc = a;
  std::sort(cc.begin(), cc.end());
  cc.erase(std::unique(cc.begin(), cc.end()), cc.end());
  for (auto &i : a)
    i = std::lower_bound(cc.begin(), cc.end(), i) - cc.begin();
  int nc = cc.size();

  mo_algorithm mo;
  for (int i = 0; i < m; i++) {
    int l, r;
    std::cin >> l >> r;
    mo.add_query(l, r);
  }

  std::vector<i64> sf(n + 1), sg(n + 1);
  {
    fenwicktree f(nc);
    for (int i = 0; i < n; i++) {
      f.add(a[i], 1);
      sf[i + 1] = sf[i] + f.prod_all() - f.prod_prev(a[i] + 1);
    }
    fenwicktree g(nc);
    for (int i = n; i > 0; i--) {
      g.add(a[i - 1], 1);
      sg[i - 1] = sg[i] + g.prod_prev(a[i - 1]);
    }
  }

  std::vector<i64> diff(m);

  std::vector<std::vector<std::tuple<int, int, int>>> query_pl(n + 1),
      query_pr(n + 1), query_nl(n + 1), query_nr(n + 1);
  auto ord = mo.only_move(
      [&](int p, int l, int r, int i) {
        diff[i] += sg[p] - sg[l];
        query_nr[r].emplace_back(i, p, l);
      },
      [&](int l, int r, int p, int i) {
        diff[i] += sf[p] - sf[r];
        query_nl[l].emplace_back(i, r, p);
      },
      [&](int l, int p, int r, int i) {
        diff[i] -= sg[l] - sg[p];
        query_pr[r].emplace_back(i, l, p);
      },
      [&](int l, int p, int r, int i) {
        diff[i] -= sf[r] - sf[p];
        query_pl[l].emplace_back(i, p, r);
      });

  {
    SqrtDecomposition s(nc);
    for (int i = 0; i <= n; i++) {
      for (auto [p, l, r] : query_pl[i]) {
        for (int j = l; j < r; j++) {
          diff[p] += s.sum_all() - s.sum(a[j] + 1);
        }
      }
      for (auto [p, l, r] : query_nl[i]) {
        for (int j = l; j < r; j++) {
          diff[p] -= s.sum_all() - s.sum(a[j] + 1);
        }
      }
      if (i < n) s.add(a[i], 1);
    }
  }

  {
    SqrtDecomposition s(nc);
    for (int i = n; i >= 0; i--) {
      for (auto [p, l, r] : query_pr[i]) {
        for (int j = l; j < r; j++) {
          diff[p] += s.sum(a[j]);
        }
      }
      for (auto [p, l, r] : query_nr[i]) {
        for (int j = l; j < r; j++) {
          diff[p] -= s.sum(a[j]);
        }
      }
      if (i > 0) s.add(a[i - 1], 1);
    }
  }

  std::vector<i64> ans(m);
  ans[ord[0]] = diff[ord[0]];
  for (int i = 1; i < m; i++) {
    int oi = ord[i], oj = ord[i - 1];
    ans[oi] = ans[oj] + diff[oi];
  }

  for (auto i : ans)
    std::cout << i << "\n";
}
