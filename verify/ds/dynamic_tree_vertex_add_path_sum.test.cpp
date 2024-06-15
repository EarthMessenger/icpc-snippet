#define PROBLEM                                                                \
  "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "lib/ds/lct.hpp"
#include "lib/internal.hpp"
#include "lib/monoid/monoid_add.hpp"

int main()
{
  std::cin.tie(nullptr);
  std::ios::sync_with_stdio(false);
  std::clog << std::boolalpha;

  int n, q;
  std::cin >> n >> q;

  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  LinkCutTree<mono::BidirMonoidTrait<mono::MonoidAdd<i64>>> lct(n, [&a](int x) { return a[x]; });
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    lct.link(u, v);
  }

  for (int i = 0; i < q; i++) {
    int op;
    std::cin >> op;
    if (op == 0) {
      int u, v, w, x;
      std::cin >> u >> v >> w >> x;
      lct.cut(u, v);
      lct.link(w, x);
    } else if (op == 1) {
      int p, x;
      std::cin >> p >> x;
      lct.multiply(p, x);
    } else if (op == 2) {
      int u, v;
      std::cin >> u >> v;
      std::cout << lct.prod(u, v) << "\n";
    }
  }
}
