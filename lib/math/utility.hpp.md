---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Usual Math Algorithm
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/math/utility.hpp: line 4: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Usual Math Algorithm\n */\n#pragma once\n#include \"lib/internal.hpp\"\
    \n\nstd::vector<int> get_prime(const int n)\n{\n  std::vector<int> res;\n  std::vector<bool>\
    \ vis(n + 1);\n  for (int i = 2; i <= n; i++) {\n    if (!vis[i]) { res.emplace_back(i);\
    \ }\n    for (auto j : res) {\n      if ((long long)i * j > n) break;\n      vis[i\
    \ * j] = true;\n      if (i % j == 0) break;\n    }\n  }\n  return res;\n}\n\n\
    // \u7ED9\u5B9A $a$ \u548C $b$\uFF0C\u8FD4\u56DE\u4E09\u5143\u7EC4 $(d, x, y)$\
    \ \u4F7F\u5F97 $d = \\gcd(a, b)$\uFF0C$ax + by = d$\nstd::tuple<int, int, int>\
    \ ex_euclid(int a, int b)\n{\n  if (b == 0) return {a, 1, 0};\n  auto [d, x, y]\
    \ = ex_euclid(b, a % b);\n  return {d, y, x - (a / b) * y};\n}\n\nstd::tuple<int,\
    \ int, int> iterative_ex_euclid(int a, int b)\n{\n  int x = 1, y = 0, n = 0, m\
    \ = 1, t;\n  while (b) {\n    t = n, n = x - a / b * n, x = t;\n    t = m, m =\
    \ y - a / b * m, y = t;\n    t = b, b = a % b, a = t;\n  }\n  return {a, x, y};\n\
    }\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/utility.hpp
  requiredBy: []
  timestamp: '2024-06-14 09:23:51+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/utility.hpp
layout: document
redirect_from:
- /library/lib/math/utility.hpp
- /library/lib/math/utility.hpp.html
title: Usual Math Algorithm
---
