#define PROBLEM "https://judge.yosupo.jp/problem/area_of_union_of_rectangles"

#include "lib/ds/lazysegtree.hpp"

#include <limits>

constexpr int INF = std::numeric_limits<int>::max() / 2;

struct MinCnt
{
  struct S
  {
    int min, cnt;
    S() : min(INF), cnt(0) {}
    S(int min, int cnt) : min(min), cnt(cnt) {}
  };

  static S op(S x, S y)
  {
    if (x.min > y.min) return y;
    else if (x.min < y.min) return x;
    return {x.min, x.cnt + y.cnt};
  }
  static S un() { return S{}; }

  static constexpr bool cm = true;
};

struct Add
{
  using S = int;

  static S op(S x, S y) { return x + y; }
  static S un() { return 0; }
};

struct Monoid
{
  using GS = MinCnt;
  using GA = Add;
  using S = GS::S;
  using A = GA::S;
  static S act(A a, S s, u32)
  {
    return {s.min + a, s.cnt};
  }
};

struct sweepline_t
{
  int x, l, r, v;
  sweepline_t(int x, int l, int r, int v) :
    x(x), l(l), r(r), v(v) {}
  bool operator<(const sweepline_t &sl) const
  {
    return x < sl.x;
  }
};

int main()
{
  int N;
  std::cin >> N;

  std::vector<sweepline_t> sweeplines;
  std::vector<int> cc;

  for (int i = 0; i < N; i++) {
    int x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    cc.emplace_back(y1);
    cc.emplace_back(y2);
    sweeplines.emplace_back(x1, y1, y2, 1);
    sweeplines.emplace_back(x2, y1, y2, -1);
  }

  std::sort(cc.begin(), cc.end());
  cc.erase(std::unique(cc.begin(), cc.end()), cc.end());
  auto val = [&](int x)
  {
    return std::lower_bound(cc.begin(), cc.end(), x) - cc.begin();
  };

  std::sort(sweeplines.begin(), sweeplines.end());

  LazySegtree<Monoid> s(cc.size() - 1,
                        [&](u32 x)
                        {
                          return MinCnt::S(0, cc[x + 1] - cc[x]);
                        });

  int tot = cc.back() - cc[0];

  int m = sweeplines.size();
  i64 ans = 0;
  for (int i = 0; i + 1 < m; i++) {
    const auto &si = sweeplines[i];
    s.apply(val(si.l), val(si.r), si.v);
    int x = sweeplines[i + 1].x - si.x;
    if (x) {
      auto all = s.prod_all();
      if (all.min == 0) ans += (i64)x * (tot - all.cnt);
      else ans += (i64)x * tot;
    }
  }

  std::cout << ans << std::endl;
}
