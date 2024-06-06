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
  bundledCode: "#line 1 \"math/lucas.hpp\"\nconstexpr int P = 2;\n\nint binom(int\
    \ n, int m);\n\nint lucas(long long n, long long m) {\n\tif (m == 0) return 1;\n\
    \treturn (long long)binom(n % P, m % P) * lucas(n / P, m / P) % P;\n}\n"
  code: "constexpr int P = 2;\n\nint binom(int n, int m);\n\nint lucas(long long n,\
    \ long long m) {\n\tif (m == 0) return 1;\n\treturn (long long)binom(n % P, m\
    \ % P) * lucas(n / P, m / P) % P;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/lucas.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/lucas.hpp
layout: document
redirect_from:
- /library/math/lucas.hpp
- /library/math/lucas.hpp.html
title: math/lucas.hpp
---
