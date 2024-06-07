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
  bundledCode: "#line 1 \"lib/math/lucas.hpp\"\nconstexpr int P = 2;\n\ntemplate <typename\
    \ T> int lucas(long long n, long long m, T binom)\n{\n  if (m == 0) return 1;\n\
    \  return (long long)binom(n % P, m % P) * lucas(n / P, m / P) % P;\n}\n"
  code: "constexpr int P = 2;\n\ntemplate <typename T> int lucas(long long n, long\
    \ long m, T binom)\n{\n  if (m == 0) return 1;\n  return (long long)binom(n %\
    \ P, m % P) * lucas(n / P, m / P) % P;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/math/lucas.hpp
  requiredBy: []
  timestamp: '2024-06-07 16:37:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/lucas.hpp
layout: document
redirect_from:
- /library/lib/math/lucas.hpp
- /library/lib/math/lucas.hpp.html
title: lib/math/lucas.hpp
---
