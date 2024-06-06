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
  bundledCode: "#line 1 \"misc/next_hamming.hpp\"\nint lowbit(int x);\n\nint next_hamming(int\
    \ x)\n{\n\tint t = x + lowbit(x);\n\treturn t | ((lowbit(t) / lowbit(x) / 2) -\
    \ 1);\n}\n"
  code: "int lowbit(int x);\n\nint next_hamming(int x)\n{\n\tint t = x + lowbit(x);\n\
    \treturn t | ((lowbit(t) / lowbit(x) / 2) - 1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/next_hamming.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/next_hamming.hpp
layout: document
redirect_from:
- /library/misc/next_hamming.hpp
- /library/misc/next_hamming.hpp.html
title: misc/next_hamming.hpp
---
