---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/lct.hpp
    title: Link Cut Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
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
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n\n#include \"lib/ds/lct.hpp\"\n#include \"lib/internal.hpp\"\n\nstruct SumMonoid\n\
    {\n  i64 s;\n  SumMonoid() : s(0) {}\n  SumMonoid(i64 s) : s(s) {}\n  friend SumMonoid\
    \ operator*(SumMonoid a, SumMonoid b) { return a.s + b.s; }\n};\n\nint main()\n\
    {\n  std::cin.tie(nullptr);\n  std::ios::sync_with_stdio(false);\n  std::clog\
    \ << std::boolalpha;\n\n  int n, q;\n  std::cin >> n >> q;\n\n  std::vector<int>\
    \ a(n);\n  for (int i = 0; i < n; i++)\n    std::cin >> a[i];\n\n  LinkCutTree<SumMonoid>\
    \ lct(n, [&a](int x) { return SumMonoid(a[x]); });\n  for (int i = 1; i < n; i++)\
    \ {\n    int u, v;\n    std::cin >> u >> v;\n    lct.link(u, v);\n  }\n\n  for\
    \ (int i = 0; i < q; i++) {\n    int op;\n    std::cin >> op;\n    if (op == 0)\
    \ {\n      int u, v, w, x;\n      std::cin >> u >> v >> w >> x;\n      lct.cut(u,\
    \ v);\n      lct.link(w, x);\n    } else if (op == 1) {\n      int p, x;\n   \
    \   std::cin >> p >> x;\n      lct.multiply(p, x);\n    } else if (op == 2) {\n\
    \      int u, v;\n      std::cin >> u >> v;\n      std::cout << lct.prod(u, v).s\
    \ << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - lib/ds/lct.hpp
  - lib/internal.hpp
  isVerificationFile: true
  path: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2024-06-13 09:43:47+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: verify/ds/dynamic_tree_vertex_add_path_sum.test.cpp
---
