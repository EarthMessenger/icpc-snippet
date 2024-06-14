---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Max Flow
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\n/**\n * @brief Max Flow\n\
    \ *\n * @tparam Cap type of capacity.\n */\ntemplate <typename Cap> struct maxflow\n\
    {\n  struct edge_t\n  {\n    int u, v;\n    Cap cap, flow;\n\n    Cap remain()\
    \ const { return cap - flow; }\n    bool exist() const { return remain() > 0;\
    \ }\n\n    edge_t(int u, int v, Cap cap, Cap flow = 0)\n        : u(u), v(v),\
    \ cap(cap), flow(flow)\n    {\n    }\n  };\n\n  int N;\n  std::vector<edge_t>\
    \ edges;\n  std::vector<std::vector<int>> adj;\n\n  std::vector<int> ord, ptr;\n\
    \n  maxflow(int N) : N(N), adj(N), ord(N), ptr(N) {}\n\n  void add_edge(int u,\
    \ int v, Cap cap)\n  {\n    adj[u].emplace_back(edges.size());\n    edges.emplace_back(u,\
    \ v, cap);\n    adj[v].emplace_back(edges.size());\n    edges.emplace_back(v,\
    \ u, 0);\n  }\n\n  bool bfs(int s, int t)\n  {\n    std::queue<int> q;\n    std::fill(ord.begin(),\
    \ ord.end(), -1);\n    q.emplace(s);\n    ord[s] = 0;\n    while (!q.empty())\
    \ {\n      auto u = q.front();\n      q.pop();\n      for (auto ei : adj[u]) {\n\
    \        const auto &e = edges[ei];\n        if (!e.exist() || ord[e.v] != -1)\
    \ continue;\n        ord[e.v] = ord[u] + 1;\n        q.emplace(e.v);\n      }\n\
    \    }\n    return ord[t] != -1;\n  }\n\n  Cap dfs(int u, Cap flow, int t)\n \
    \ {\n    if (flow == 0 || u == t) return flow;\n    Cap res = 0;\n    for (int\
    \ &p = ptr[u]; p < (int)adj[u].size(); p++) {\n      auto ei = adj[u][p];\n  \
    \    auto &e = edges[ei];\n      auto &ie = edges[ei ^ 1];\n      if (!e.exist())\
    \ continue;\n      if (ord[e.v] <= ord[u]) continue;\n      Cap w = dfs(e.v, std::min(flow\
    \ - res, e.remain()), t);\n      if (!w) continue;\n      res += w;\n      e.flow\
    \ += w;\n      ie.flow -= w;\n      if (res == flow) return res;\n    }\n    return\
    \ res;\n  }\n\n  Cap flow(int s, int t, Cap lim = std::numeric_limits<Cap>::max())\n\
    \  {\n    Cap res = 0;\n    while (res < lim) {\n      bool flag = bfs(s, t);\n\
    \      if (!flag) break;\n      std::fill(ptr.begin(), ptr.end(), 0);\n      while\
    \ (true) {\n        Cap w = dfs(s, lim - res, t);\n        if (w == 0) break;\n\
    \        res += w;\n      }\n    }\n    return res;\n  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/graph/maxflow.hpp
  requiredBy: []
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/graph/maxflow.hpp
layout: document
redirect_from:
- /library/lib/graph/maxflow.hpp
- /library/lib/graph/maxflow.hpp.html
title: Max Flow
---
