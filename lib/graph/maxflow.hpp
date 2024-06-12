#pragma once
#include "lib/internal.hpp"

template <typename Cap> struct maxflow
{
  struct edge_t
  {
    int u, v;
    Cap cap, flow;

    Cap remain() const { return cap - flow; }
    bool exist() const { return remain() > 0; }

    edge_t(int u, int v, Cap cap, Cap flow = 0)
        : u(u), v(v), cap(cap), flow(flow)
    {
    }
  };

  int N;
  std::vector<edge_t> edges;
  std::vector<std::vector<int>> adj;

  std::vector<int> ord, ptr;

  maxflow(int N) : N(N), adj(N), ord(N), ptr(N) {}

  void add_edge(int u, int v, Cap cap)
  {
    adj[u].emplace_back(edges.size());
    edges.emplace_back(u, v, cap);
    adj[v].emplace_back(edges.size());
    edges.emplace_back(v, u, 0);
  }

  bool bfs(int s, int t)
  {
    std::queue<int> q;
    std::fill(ord.begin(), ord.end(), -1);
    q.emplace(s);
    ord[s] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (auto ei : adj[u]) {
        const auto &e = edges[ei];
        if (!e.exist() || ord[e.v] != -1) continue;
        ord[e.v] = ord[u] + 1;
        q.emplace(e.v);
      }
    }
    return ord[t] != -1;
  }

  Cap dfs(int u, Cap flow, int t)
  {
    if (flow == 0 || u == t) return flow;
    Cap res = 0;
    for (int &p = ptr[u]; p < (int)adj[u].size(); p++) {
      auto ei = adj[u][p];
      auto &e = edges[ei];
      auto &ie = edges[ei ^ 1];
      if (!e.exist()) continue;
      if (ord[e.v] <= ord[u]) continue;
      Cap w = dfs(e.v, std::min(flow - res, e.remain()), t);
      if (!w) continue;
      res += w;
      e.flow += w;
      ie.flow -= w;
      if (res == flow) return res;
    }
    return res;
  }

  Cap flow(int s, int t, Cap lim = std::numeric_limits<Cap>::max())
  {
    Cap res = 0;
    while (res < lim) {
      bool flag = bfs(s, t);
      if (!flag) break;
      std::fill(ptr.begin(), ptr.end(), 0);
      while (true) {
        Cap w = dfs(s, lim - res, t);
        if (w == 0) break;
        res += w;
      }
    }
    return res;
  }
};
