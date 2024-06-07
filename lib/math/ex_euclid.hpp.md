---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/math/ex_euclid.hpp\"\n#include <tuple>\n\n// \u7ED9\u5B9A\
    \ $a$ \u548C $b$\uFF0C\u8FD4\u56DE\u4E09\u5143\u7EC4 $(d, x, y)$ \u4F7F\u5F97\
    \ $d = \\gcd(a, b)$\uFF0C$ax + by = d$\nstd::tuple<int, int, int> ex_euclid(int\
    \ a, int b)\n{\n  if (b == 0) return {a, 1, 0};\n  auto [d, x, y] = ex_euclid(b,\
    \ a % b);\n  return {d, y, x - (a / b) * y};\n}\n"
  code: "#include <tuple>\n\n// \u7ED9\u5B9A $a$ \u548C $b$\uFF0C\u8FD4\u56DE\u4E09\
    \u5143\u7EC4 $(d, x, y)$ \u4F7F\u5F97 $d = \\gcd(a, b)$\uFF0C$ax + by = d$\nstd::tuple<int,\
    \ int, int> ex_euclid(int a, int b)\n{\n  if (b == 0) return {a, 1, 0};\n  auto\
    \ [d, x, y] = ex_euclid(b, a % b);\n  return {d, y, x - (a / b) * y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/ex_euclid.hpp
  requiredBy: []
  timestamp: '2024-06-07 15:38:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/ex_euclid.hpp
layout: document
redirect_from:
- /library/lib/math/ex_euclid.hpp
- /library/lib/math/ex_euclid.hpp.html
title: lib/math/ex_euclid.hpp
---
