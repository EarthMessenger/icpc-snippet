#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "lib/graph/scc.hpp"
#include "lib/internal.hpp"

int main()
{
  int n, m;
  std::cin >> n >> m;
  scc_graph g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    std::cin >> u >> v;
    g.add_edge(u, v);
  }

  auto [scc_cnt, belongs] = g.solve();

  std::vector<std::vector<int>> groups(scc_cnt);
  for (int i = 0; i < n; i++) {
    groups[belongs[i]].emplace_back(i);
  }
  std::reverse(groups.begin(), groups.end());

  std::cout << groups.size() << std::endl;
  for (auto i : groups) {
    std::cout << i.size() << " ";
    for (auto j : i) {
      std::cout << j << " ";
    }
    std::cout << std::endl;
  }
}
