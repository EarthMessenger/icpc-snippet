---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"\
    lib/graph/maxflow.hpp\"\n\ntemplate <typename Cap>\nstruct maxflow\n{\n  struct\
    \ edge_t\n  {\n    int u, v;\n    Cap cap, flow;\n\n    Cap remain() const { return\
    \ cap - flow; }\n    bool exist() const { return remain() > 0; }\n\n    edge_t(int\
    \ u, int v, Cap cap, Cap flow = 0) : u(u), v(v), cap(cap), flow(flow) {}\n  };\n\
    \n  int N;\n  std::vector<edge_t> edges;\n  std::vector<std::vector<int> > adj;\n\
    \n  std::vector<int> ord, ptr;\n\n  maxflow(int N) : N(N), adj(N), ord(N), ptr(N)\
    \ {}\n\n  void add_edge(int u, int v, Cap cap)\n  {\n    adj[u].emplace_back(edges.size());\n\
    \    edges.emplace_back(u, v, cap);\n    adj[v].emplace_back(edges.size());\n\
    \    edges.emplace_back(v, u, 0);\n  }\n\n  bool bfs(int s, int t)\n  {\n    std::queue<int>\
    \ q;\n    std::fill(ord.begin(), ord.end(), -1);\n    q.emplace(s);\n    ord[s]\
    \ = 0;\n    while (!q.empty()) {\n      auto u = q.front();\n      q.pop();\n\
    \      for (auto ei : adj[u]) {\n        const auto &e = edges[ei];\n        if\
    \ (!e.exist() || ord[e.v] != -1) continue;\n        ord[e.v] = ord[u] + 1;\n \
    \       q.emplace(e.v);\n      }\n    }\n    return ord[t] != -1;\n  }\n\n  Cap\
    \ dfs(int u, Cap flow, int t)\n  {\n    if (flow == 0 || u == t) return flow;\n\
    \    Cap res = 0;\n    for (int &p = ptr[u]; p < (int)adj[u].size(); p++) {\n\
    \      auto ei = adj[u][p];\n      auto &e = edges[ei];\n      auto &ie = edges[ei\
    \ ^ 1];\n      if (!e.exist()) continue;\n      if (ord[e.v] <= ord[u]) continue;\n\
    \      Cap w = dfs(e.v, std::min(flow - res, e.remain()), t);\n      if (!w) continue;\n\
    \      res += w;\n      e.flow += w;\n      ie.flow -= w;\n      if (res == flow)\
    \ return res;\n    }\n    return res;\n  }\n\n  Cap flow(int s, int t, Cap lim\
    \ = std::numeric_limits<Cap>::max())\n  {\n    Cap res = 0;\n    while (res <\
    \ lim) {\n      bool flag = bfs(s, t);\n      if (!flag) break;\n      std::fill(ptr.begin(),\
    \ ptr.end(), 0);\n      while (true) {\n        Cap w = dfs(s, lim - res, t);\n\
    \        if (w == 0) break;\n        res += w;\n      }\n    }\n    return res;\n\
    \  }\n};\n\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\ntemplate <typename Cap>\n\
    struct maxflow\n{\n  struct edge_t\n  {\n    int u, v;\n    Cap cap, flow;\n\n\
    \    Cap remain() const { return cap - flow; }\n    bool exist() const { return\
    \ remain() > 0; }\n\n    edge_t(int u, int v, Cap cap, Cap flow = 0) : u(u), v(v),\
    \ cap(cap), flow(flow) {}\n  };\n\n  int N;\n  std::vector<edge_t> edges;\n  std::vector<std::vector<int>\
    \ > adj;\n\n  std::vector<int> ord, ptr;\n\n  maxflow(int N) : N(N), adj(N), ord(N),\
    \ ptr(N) {}\n\n  void add_edge(int u, int v, Cap cap)\n  {\n    adj[u].emplace_back(edges.size());\n\
    \    edges.emplace_back(u, v, cap);\n    adj[v].emplace_back(edges.size());\n\
    \    edges.emplace_back(v, u, 0);\n  }\n\n  bool bfs(int s, int t)\n  {\n    std::queue<int>\
    \ q;\n    std::fill(ord.begin(), ord.end(), -1);\n    q.emplace(s);\n    ord[s]\
    \ = 0;\n    while (!q.empty()) {\n      auto u = q.front();\n      q.pop();\n\
    \      for (auto ei : adj[u]) {\n        const auto &e = edges[ei];\n        if\
    \ (!e.exist() || ord[e.v] != -1) continue;\n        ord[e.v] = ord[u] + 1;\n \
    \       q.emplace(e.v);\n      }\n    }\n    return ord[t] != -1;\n  }\n\n  Cap\
    \ dfs(int u, Cap flow, int t)\n  {\n    if (flow == 0 || u == t) return flow;\n\
    \    Cap res = 0;\n    for (int &p = ptr[u]; p < (int)adj[u].size(); p++) {\n\
    \      auto ei = adj[u][p];\n      auto &e = edges[ei];\n      auto &ie = edges[ei\
    \ ^ 1];\n      if (!e.exist()) continue;\n      if (ord[e.v] <= ord[u]) continue;\n\
    \      Cap w = dfs(e.v, std::min(flow - res, e.remain()), t);\n      if (!w) continue;\n\
    \      res += w;\n      e.flow += w;\n      ie.flow -= w;\n      if (res == flow)\
    \ return res;\n    }\n    return res;\n  }\n\n  Cap flow(int s, int t, Cap lim\
    \ = std::numeric_limits<Cap>::max())\n  {\n    Cap res = 0;\n    while (res <\
    \ lim) {\n      bool flag = bfs(s, t);\n      if (!flag) break;\n      std::fill(ptr.begin(),\
    \ ptr.end(), 0);\n      while (true) {\n        Cap w = dfs(s, lim - res, t);\n\
    \        if (w == 0) break;\n        res += w;\n      }\n    }\n    return res;\n\
    \  }\n};\n\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/graph/maxflow.hpp
  requiredBy: []
  timestamp: '2024-06-07 19:00:54+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/maxflow.hpp
layout: document
redirect_from:
- /library/lib/graph/maxflow.hpp
- /library/lib/graph/maxflow.hpp.html
title: lib/graph/maxflow.hpp
---
