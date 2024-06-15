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

#include "lib/ds/splay.hpp"
#include "lib/math/static_modint.hpp"
#include "lib/monoid/monoid_add.hpp"
#include "lib/monoid/monoid_linear_function.hpp"

using mint = static_modint<998'244'353>;

mint act(const std::pair<mint, mint> &&a, const mint &&b, u64 &&c) { return a.first * b + a.second * c; }

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

  Splay<mono::BidirActedMonoidTrait<mono::ActedMonoidTrait<
      mono::MonoidLinearFunc<mint>, mono::MonoidAdd<mint>, act>>>
      t(n, [&a](u32 x) { return a[x]; });

  for (int i = 0; i < Q; i++) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int i, x;
      std::cin >> i >> x;
      t.insert(i, x);
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
      t.apply(l, r, {b, c});
    } else if (op == 4) {
      int l, r;
      std::cin >> l >> r;
      std::cout << t.prod(l, r).val() << "\n";
    }
  }
}
