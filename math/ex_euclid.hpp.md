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
  bundledCode: "#line 1 \"math/ex_euclid.hpp\"\n#include <tuple>\n\n// \u7ED9\u5B9A\
    \ $a$ \u548C $b$\uFF0C\u8FD4\u56DE\u4E09\u5143\u7EC4 $(d, x, y)$ \u4F7F\u5F97\
    \ $d = \\gcd(a, b)$\uFF0C$ax + by = d$\nstd::tuple<int, int, int> ex_euclid(int\
    \ a, int b)\n{\n\tif (b == 0) {\n\t\treturn {a, 1, 0};\n\t}\n\tauto [d, x, y]\
    \ = ex_euclid(b, a % b);\n\treturn {d, y, x - (a / b) * y};\n}\n"
  code: "#include <tuple>\n\n// \u7ED9\u5B9A $a$ \u548C $b$\uFF0C\u8FD4\u56DE\u4E09\
    \u5143\u7EC4 $(d, x, y)$ \u4F7F\u5F97 $d = \\gcd(a, b)$\uFF0C$ax + by = d$\nstd::tuple<int,\
    \ int, int> ex_euclid(int a, int b)\n{\n\tif (b == 0) {\n\t\treturn {a, 1, 0};\n\
    \t}\n\tauto [d, x, y] = ex_euclid(b, a % b);\n\treturn {d, y, x - (a / b) * y};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math/ex_euclid.hpp
  requiredBy: []
  timestamp: '2024-06-06 21:18:13+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/ex_euclid.hpp
layout: document
redirect_from:
- /library/math/ex_euclid.hpp
- /library/math/ex_euclid.hpp.html
title: math/ex_euclid.hpp
---
