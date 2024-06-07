#define PROBLEM                                                                \
  "https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum"

#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using i64 = long long;
using i128 = __int128_t;
using u32 = unsigned int;
using u64 = unsigned long long;
using u128 = __uint128_t;

#include "ds/rbst.hpp"
#include "math/static_modint.hpp"

using mint = static_modint<998'244'353>;

struct SumMonoid
{
  mint sum;
  SumMonoid() : sum(0) {}
  SumMonoid(mint sum) : sum(sum) {}

  SumMonoid operator*(const SumMonoid &s) const { return sum + s.sum; };
};

struct AddTimesMonoid
{
  mint k, b;
  AddTimesMonoid() : k(1), b(0) {}
  AddTimesMonoid(mint k, mint b) : k(k), b(b) {}

  AddTimesMonoid operator*(const AddTimesMonoid &a) const
  {
    return {k * a.k, b * a.k + a.b};
  };

  SumMonoid operator()(const SumMonoid &s, u32 size) const
  {
    return {s.sum * k + b * size};
  }

  bool is_unit() const { return k.val() == 1 && b.val() == 0; }
};

int main()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n, Q;
  std::cin >> n >> Q;
  std::vector<mint> a(n);
  for (auto &i : a) {
    int v;
    std::cin >> v;
    i = v;
  }

  RBST<SumMonoid, AddTimesMonoid> t(n, [&a](u32 x) { return a[x]; });

  for (int i = 0; i < Q; i++) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int i, x;
      std::cin >> i >> x;
      t.insert(i, SumMonoid(x));
    } else if (op == 1) {
      int i;
      std::cin >> i;
      t.remove(i);
    } else if (op == 2) {
      int l, r;
      std::cin >> l >> r;
      t.reverse(l, r);
    } else if (op == 3) {
      int l, r, b, c;
      std::cin >> l >> r >> b >> c;
      t.apply(l, r, AddTimesMonoid(b, c));
    } else if (op == 4) {
      int l, r;
      std::cin >> l >> r;
      std::cout << t.prod(l, r).sum.val() << "\n";
    }
  }
}
