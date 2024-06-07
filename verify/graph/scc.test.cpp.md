---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: lib/graph/scc.hpp
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/graph/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n#include\
    \ <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\nusing\
    \ i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T>\
    \ using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"lib/graph/scc.hpp\"\
    \n\nstruct scc_graph\n{\n  int n;\n  std::vector<std::vector<int>> adj;\n\n  scc_graph(int\
    \ n) : n(n), adj(n) {}\n\n  void add_edge(int u, int v) { adj[u].emplace_back(v);\
    \ }\n\n  std::pair<int, std::vector<int>> solve()\n  {\n    std::vector<int> dfn(n,\
    \ -1), low(n, -1), stk;\n    std::vector<bool> vis(n);\n    std::vector<int> belong(n,\
    \ -1);\n    int scc_cnt = 0;\n    int cnt = 0;\n    auto dfs = [&](auto &&self,\
    \ int u) -> void\n    {\n      dfn[u] = low[u] = cnt++;\n      stk.emplace_back(u);\n\
    \      vis[u] = true;\n      for (auto v : adj[u]) {\n        if (dfn[v] == -1)\
    \ {\n          self(self, v);\n          low[u] = std::min(low[u], low[v]);\n\
    \        } else if (vis[v]) {\n          low[u] = std::min(low[u], dfn[v]);\n\
    \        }\n      }\n      if (low[u] == dfn[u]) {\n        while (true) {\n \
    \         int x = stk.back();\n          stk.pop_back();\n          vis[x] = false;\n\
    \          belong[x] = scc_cnt;\n          if (x == u) break;\n        }\n   \
    \     scc_cnt++;\n      }\n    };\n    for (int i = 0; i < n; i++) {\n      if\
    \ (belong[i] == -1) dfs(dfs, i);\n    }\n    return {scc_cnt, belong};\n  }\n\
    };\n#line 5 \"verify/graph/scc.test.cpp\"\n\nint main()\n{\n  int n, m;\n  std::cin\
    \ >> n >> m;\n  scc_graph g(n);\n\n  for (int i = 0; i < m; i++) {\n    int u,\
    \ v;\n    std::cin >> u >> v;\n    g.add_edge(u, v);\n  }\n\n  auto [scc_cnt,\
    \ belongs] = g.solve();\n\n  std::vector<std::vector<int>> groups(scc_cnt);\n\
    \  for (int i = 0; i < n; i++) {\n    groups[belongs[i]].emplace_back(i);\n  }\n\
    \  std::reverse(groups.begin(), groups.end());\n\n  std::cout << groups.size()\
    \ << std::endl;\n  for (auto i : groups) {\n    std::cout << i.size() << \" \"\
    ;\n    for (auto j : i) {\n      std::cout << j << \" \";\n    }\n    std::cout\
    \ << std::endl;\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"lib/graph/scc.hpp\"\
    \n#include \"lib/internal.hpp\"\n\nint main()\n{\n  int n, m;\n  std::cin >> n\
    \ >> m;\n  scc_graph g(n);\n\n  for (int i = 0; i < m; i++) {\n    int u, v;\n\
    \    std::cin >> u >> v;\n    g.add_edge(u, v);\n  }\n\n  auto [scc_cnt, belongs]\
    \ = g.solve();\n\n  std::vector<std::vector<int>> groups(scc_cnt);\n  for (int\
    \ i = 0; i < n; i++) {\n    groups[belongs[i]].emplace_back(i);\n  }\n  std::reverse(groups.begin(),\
    \ groups.end());\n\n  std::cout << groups.size() << std::endl;\n  for (auto i\
    \ : groups) {\n    std::cout << i.size() << \" \";\n    for (auto j : i) {\n \
    \     std::cout << j << \" \";\n    }\n    std::cout << std::endl;\n  }\n}\n"
  dependsOn:
  - lib/graph/scc.hpp
  - lib/internal.hpp
  isVerificationFile: true
  path: verify/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/scc.test.cpp
- /verify/verify/graph/scc.test.cpp.html
title: verify/graph/scc.test.cpp
---
