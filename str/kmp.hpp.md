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
  bundledCode: "#line 1 \"str/kmp.hpp\"\nstd::vector<int> prefix_function(const std::string\
    \ &s)\n{\n  int n = s.size();\n  std::vector<int> p(n + 1);\n  p[0] = p[1] = 0;\n\
    \  for (int i = 1; i < n; i++) {\n    int t = p[i];\n    while (t > 0 && s[t]\
    \ != s[i]) t = p[t];\n    if (s[t] == s[i]) t++;\n    p[i + 1] = t;\n  }\n  return\
    \ p;\n}\n"
  code: "std::vector<int> prefix_function(const std::string &s)\n{\n  int n = s.size();\n\
    \  std::vector<int> p(n + 1);\n  p[0] = p[1] = 0;\n  for (int i = 1; i < n; i++)\
    \ {\n    int t = p[i];\n    while (t > 0 && s[t] != s[i]) t = p[t];\n    if (s[t]\
    \ == s[i]) t++;\n    p[i + 1] = t;\n  }\n  return p;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: str/kmp.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: str/kmp.hpp
layout: document
redirect_from:
- /library/str/kmp.hpp
- /library/str/kmp.hpp.html
title: str/kmp.hpp
---
