---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 2 \"\
    lib/math/inv.hpp\"\n\nconstexpr int M = 998'244'353;\n\nstd::vector<int> get_inv(const\
    \ int n)\n{\n  std::vector<int> res(n + 1);\n  res[1] = 1;\n  for (int i = 2;\
    \ i <= n; i++) {\n    res[i] = (long long)(M - M / i) * res[M % i] % M;\n  }\n\
    \  return res;\n}\n"
  code: "#include \"lib/internal.hpp\"\n\nconstexpr int M = 998'244'353;\n\nstd::vector<int>\
    \ get_inv(const int n)\n{\n  std::vector<int> res(n + 1);\n  res[1] = 1;\n  for\
    \ (int i = 2; i <= n; i++) {\n    res[i] = (long long)(M - M / i) * res[M % i]\
    \ % M;\n  }\n  return res;\n}\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/inv.hpp
  requiredBy: []
  timestamp: '2024-06-07 16:37:49+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/inv.hpp
layout: document
redirect_from:
- /library/lib/math/inv.hpp
- /library/lib/math/inv.hpp.html
title: lib/math/inv.hpp
---
