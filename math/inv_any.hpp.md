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
  bundledCode: "#line 1 \"math/inv_any.hpp\"\n#include <vector>\n\nconstexpr int M\
    \ = 998'244'353;\nint inv(int x);\n\nstd::vector<int> get_inv(const std::vector<int>\
    \ &a)\n{\n\tconst int n = a.size();\n\tstd::vector<int> s(n + 1), sv(n + 1), res(n);\n\
    \ts[0] = 1;\n\tfor (int i = 0; i < n; i++) {\n\t\ts[i + 1] = (long long)s[i] *\
    \ a[i] % M;\n\t}\n\tsv[n] = inv(s[n]);\n\tfor (int i = n; i > 0; ) {\n\t\ti--;\n\
    \t\tsv[i] = (long long)sv[i + 1] * a[i] % M;\n\t}\n\tfor (int i = 0; i < n; i++)\
    \ {\n\t\tres[i] = (long long)sv[i + 1] * s[i] % M;\n\t}\n\treturn res;\n}\n"
  code: "#include <vector>\n\nconstexpr int M = 998'244'353;\nint inv(int x);\n\n\
    std::vector<int> get_inv(const std::vector<int> &a)\n{\n\tconst int n = a.size();\n\
    \tstd::vector<int> s(n + 1), sv(n + 1), res(n);\n\ts[0] = 1;\n\tfor (int i = 0;\
    \ i < n; i++) {\n\t\ts[i + 1] = (long long)s[i] * a[i] % M;\n\t}\n\tsv[n] = inv(s[n]);\n\
    \tfor (int i = n; i > 0; ) {\n\t\ti--;\n\t\tsv[i] = (long long)sv[i + 1] * a[i]\
    \ % M;\n\t}\n\tfor (int i = 0; i < n; i++) {\n\t\tres[i] = (long long)sv[i + 1]\
    \ * s[i] % M;\n\t}\n\treturn res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/inv_any.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/inv_any.hpp
layout: document
redirect_from:
- /library/math/inv_any.hpp
- /library/math/inv_any.hpp.html
title: math/inv_any.hpp
---
