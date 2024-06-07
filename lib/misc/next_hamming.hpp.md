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
  bundledCode: "#line 2 \"lib/misc/next_hamming.hpp\"\nint next_hamming(int x)\n{\n\
    \  int t = x + (x & -x);\n  return t | (((t & -t) / (x & -x) / 2) - 1);\n}\n"
  code: "#pragma once\nint next_hamming(int x)\n{\n  int t = x + (x & -x);\n  return\
    \ t | (((t & -t) / (x & -x) / 2) - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: lib/misc/next_hamming.hpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/misc/next_hamming.hpp
layout: document
redirect_from:
- /library/lib/misc/next_hamming.hpp
- /library/lib/misc/next_hamming.hpp.html
title: lib/misc/next_hamming.hpp
---
