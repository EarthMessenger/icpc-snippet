---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/graph/scc.test.cpp
    title: verify/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Strongly Connected Components
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\n/**\n * @brief Strongly Connected\
    \ Components\n * \n */\nstruct scc_graph\n{\n  int n;\n  std::vector<std::vector<int>>\
    \ adj;\n\n  scc_graph(int n) : n(n), adj(n) {}\n\n  void add_edge(int u, int v)\
    \ { adj[u].emplace_back(v); }\n\n  std::pair<int, std::vector<int>> solve()\n\
    \  {\n    std::vector<int> dfn(n, -1), low(n, -1), stk;\n    std::vector<bool>\
    \ vis(n);\n    std::vector<int> belong(n, -1);\n    int scc_cnt = 0;\n    int\
    \ cnt = 0;\n    auto dfs = [&](auto &&self, int u) -> void {\n      dfn[u] = low[u]\
    \ = cnt++;\n      stk.emplace_back(u);\n      vis[u] = true;\n      for (auto\
    \ v : adj[u]) {\n        if (dfn[v] == -1) {\n          self(self, v);\n     \
    \     low[u] = std::min(low[u], low[v]);\n        } else if (vis[v]) {\n     \
    \     low[u] = std::min(low[u], dfn[v]);\n        }\n      }\n      if (low[u]\
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
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/graph/scc.test.cpp
documentation_of: lib/graph/scc.hpp
layout: document
redirect_from:
- /library/lib/graph/scc.hpp
- /library/lib/graph/scc.hpp.html
title: Strongly Connected Components
---
