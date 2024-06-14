---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/graph/scc.hpp
    title: Strongly Connected Components
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
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
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/graph/scc.test.cpp
- /verify/verify/graph/scc.test.cpp.html
title: verify/graph/scc.test.cpp
---
