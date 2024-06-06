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
  bundledCode: "#line 1 \"math/inv.hpp\"\n#include <vector>\n\nconstexpr int M = 998'244'353;\n\
    \nstd::vector<int> get_inv(const int n)\n{\n    std::vector<int> res(n + 1);\n\
    \    res[1] = 1;\n    for (int i = 2; i <= n; i++) {\n        res[i] = (long long)(M\
    \ - M / i) * res[M % i] % M;\n    }\n    return res;\n}\n"
  code: "#include <vector>\n\nconstexpr int M = 998'244'353;\n\nstd::vector<int> get_inv(const\
    \ int n)\n{\n    std::vector<int> res(n + 1);\n    res[1] = 1;\n    for (int i\
    \ = 2; i <= n; i++) {\n        res[i] = (long long)(M - M / i) * res[M % i] %\
    \ M;\n    }\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv.hpp
layout: document
redirect_from:
- /library/math/inv.hpp
- /library/math/inv.hpp.html
title: math/inv.hpp
---
