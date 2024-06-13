#pragma once
#include "lib/internal.hpp"

/**
 * @brief Strongly Connected Components
 * 
 */
struct scc_graph
{
  int n;
  std::vector<std::vector<int>> adj;

  scc_graph(int n) : n(n), adj(n) {}

  void add_edge(int u, int v) { adj[u].emplace_back(v); }

  std::pair<int, std::vector<int>> solve()
  {
    std::vector<int> dfn(n, -1), low(n, -1), stk;
    std::vector<bool> vis(n);
    std::vector<int> belong(n, -1);
    int scc_cnt = 0;
    int cnt = 0;
    auto dfs = [&](auto &&self, int u) -> void {
      dfn[u] = low[u] = cnt++;
      stk.emplace_back(u);
      vis[u] = true;
      for (auto v : adj[u]) {
        if (dfn[v] == -1) {
          self(self, v);
          low[u] = std::min(low[u], low[v]);
        } else if (vis[v]) {
          low[u] = std::min(low[u], dfn[v]);
        }
      }
      if (low[u] == dfn[u]) {
        while (true) {
          int x = stk.back();
          stk.pop_back();
          vis[x] = false;
          belong[x] = scc_cnt;
          if (x == u) break;
        }
        scc_cnt++;
      }
    };
    for (int i = 0; i < n; i++) {
      if (belong[i] == -1) dfs(dfs, i);
    }
    return {scc_cnt, belong};
  }
};
