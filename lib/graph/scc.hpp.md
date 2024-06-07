---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 2 \"\
    lib/graph/scc.hpp\"\n\nstruct scc_graph\n{\n  int n;\n  std::vector<std::vector<int>>\
    \ adj;\n\n  scc_graph(int n) : n(n), adj(n) {}\n\n  void add_edge(int u, int v)\
    \ { adj[u].emplace_back(v); }\n\n  std::pair<int, std::vector<int>> solve()\n\
    \  {\n    std::vector<int> dfn(n, -1), low(n, -1), stk;\n    std::vector<bool>\
    \ vis(n);\n    std::vector<int> belong(n, -1);\n    int scc_cnt = 0;\n    int\
    \ cnt = 0;\n    auto dfs = [&](auto &&self, int u) -> void\n    {\n      dfn[u]\
    \ = low[u] = cnt++;\n      stk.emplace_back(u);\n      vis[u] = true;\n      for\
    \ (auto v : adj[u]) {\n        if (dfn[v] == -1) {\n          self(self, v);\n\
    \          low[u] = std::min(low[u], low[v]);\n        } else if (vis[v]) {\n\
    \          low[u] = std::min(low[u], dfn[v]);\n        }\n      }\n      if (low[u]\
    \ == dfn[u]) {\n        while (true) {\n          int x = stk.back();\n      \
    \    stk.pop_back();\n          vis[x] = false;\n          belong[x] = scc_cnt;\n\
    \          if (x == u) break;\n        }\n        scc_cnt++;\n      }\n    };\n\
    \    for (int i = 0; i < n; i++) {\n      if (belong[i] == -1) dfs(dfs, i);\n\
    \    }\n    return {scc_cnt, belong};\n  }\n};\n"
  code: "#include \"lib/internal.hpp\"\n\nstruct scc_graph\n{\n  int n;\n  std::vector<std::vector<int>>\
    \ adj;\n\n  scc_graph(int n) : n(n), adj(n) {}\n\n  void add_edge(int u, int v)\
    \ { adj[u].emplace_back(v); }\n\n  std::pair<int, std::vector<int>> solve()\n\
    \  {\n    std::vector<int> dfn(n, -1), low(n, -1), stk;\n    std::vector<bool>\
    \ vis(n);\n    std::vector<int> belong(n, -1);\n    int scc_cnt = 0;\n    int\
    \ cnt = 0;\n    auto dfs = [&](auto &&self, int u) -> void\n    {\n      dfn[u]\
    \ = low[u] = cnt++;\n      stk.emplace_back(u);\n      vis[u] = true;\n      for\
    \ (auto v : adj[u]) {\n        if (dfn[v] == -1) {\n          self(self, v);\n\
    \          low[u] = std::min(low[u], low[v]);\n        } else if (vis[v]) {\n\
    \          low[u] = std::min(low[u], dfn[v]);\n        }\n      }\n      if (low[u]\
    \ == dfn[u]) {\n        while (true) {\n          int x = stk.back();\n      \
    \    stk.pop_back();\n          vis[x] = false;\n          belong[x] = scc_cnt;\n\
    \          if (x == u) break;\n        }\n        scc_cnt++;\n      }\n    };\n\
    \    for (int i = 0; i < n; i++) {\n      if (belong[i] == -1) dfs(dfs, i);\n\
    \    }\n    return {scc_cnt, belong};\n  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/graph/scc.hpp
  requiredBy: []
  timestamp: '2024-06-07 15:38:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/scc.hpp
- /library/lib/graph/scc.hpp.html
title: lib/graph/scc.hpp
---