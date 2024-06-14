---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/str/zalgorithm.test.cpp
    title: verify/str/zalgorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"lib/str/z.hpp\"\n#include <vector>\n#include <string>\n\n\
    std::vector<int> z_algorithm(const std::string &s)\n{\n  int n = s.size();\n \
    \ std::vector<int> z(n + 1);\n  z[0] = n;\n  int l = 0, r = 0;\n  for (int i =\
    \ 1; i <= n; i++) {\n    int t = 0;\n    if (i <= r) t = std::min(z[i - l], r\
    \ - i);\n    while (i + t < n && s[t] == s[i + t]) t++;\n    z[i] = t;\n    if\
    \ (i + z[i] > r) {\n      l = i;\n      r = i + z[i];\n    }\n  }\n  return z;\n\
    }\n"
  code: "#include <vector>\n#include <string>\n\nstd::vector<int> z_algorithm(const\
    \ std::string &s)\n{\n  int n = s.size();\n  std::vector<int> z(n + 1);\n  z[0]\
    \ = n;\n  int l = 0, r = 0;\n  for (int i = 1; i <= n; i++) {\n    int t = 0;\n\
    \    if (i <= r) t = std::min(z[i - l], r - i);\n    while (i + t < n && s[t]\
    \ == s[i + t]) t++;\n    z[i] = t;\n    if (i + z[i] > r) {\n      l = i;\n  \
    \    r = i + z[i];\n    }\n  }\n  return z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: lib/str/z.hpp
  requiredBy: []
  timestamp: '2024-06-14 20:43:15+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/str/zalgorithm.test.cpp
documentation_of: lib/str/z.hpp
layout: document
redirect_from:
- /library/lib/str/z.hpp
- /library/lib/str/z.hpp.html
title: lib/str/z.hpp
---
