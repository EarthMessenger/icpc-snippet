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
  bundledCode: "#line 1 \"math/prime.hpp\"\n#include <vector>\n\nstd::vector<int>\
    \ get_prime(const int n)\n{\n\tstd::vector<int> res;\n\tstd::vector<bool> vis(n\
    \ + 1);\n\tfor (int i = 2; i <= n; i++) {\n\t\tif (!vis[i]) {\n\t\t\tres.emplace_back(i);\n\
    \t\t}\n\t\tfor (auto j : res) {\n\t\t\tif ((long long)i * j > n) break;\n\t\t\t\
    vis[i * j] = true;\n\t\t\tif (i % j == 0) break;\n\t\t}\n\t}\n\treturn res;\n\
    }\n"
  code: "#include <vector>\n\nstd::vector<int> get_prime(const int n)\n{\n\tstd::vector<int>\
    \ res;\n\tstd::vector<bool> vis(n + 1);\n\tfor (int i = 2; i <= n; i++) {\n\t\t\
    if (!vis[i]) {\n\t\t\tres.emplace_back(i);\n\t\t}\n\t\tfor (auto j : res) {\n\t\
    \t\tif ((long long)i * j > n) break;\n\t\t\tvis[i * j] = true;\n\t\t\tif (i %\
    \ j == 0) break;\n\t\t}\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/prime.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/prime.hpp
layout: document
redirect_from:
- /library/math/prime.hpp
- /library/math/prime.hpp.html
title: math/prime.hpp
---
