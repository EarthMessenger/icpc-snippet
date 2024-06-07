---
data:
  _extendedDependsOn:
  - icon: ':warning:'
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
    lib/math/prime.hpp\"\n\nstd::vector<int> get_prime(const int n)\n{\n  std::vector<int>\
    \ res;\n  std::vector<bool> vis(n + 1);\n  for (int i = 2; i <= n; i++) {\n  \
    \  if (!vis[i]) { res.emplace_back(i); }\n    for (auto j : res) {\n      if ((long\
    \ long)i * j > n) break;\n      vis[i * j] = true;\n      if (i % j == 0) break;\n\
    \    }\n  }\n  return res;\n}\n"
  code: "#include \"lib/internal.hpp\"\n\nstd::vector<int> get_prime(const int n)\n\
    {\n  std::vector<int> res;\n  std::vector<bool> vis(n + 1);\n  for (int i = 2;\
    \ i <= n; i++) {\n    if (!vis[i]) { res.emplace_back(i); }\n    for (auto j :\
    \ res) {\n      if ((long long)i * j > n) break;\n      vis[i * j] = true;\n \
    \     if (i % j == 0) break;\n    }\n  }\n  return res;\n}\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/prime.hpp
  requiredBy: []
  timestamp: '2024-06-07 15:38:59+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/prime.hpp
layout: document
redirect_from:
- /library/lib/math/prime.hpp
- /library/lib/math/prime.hpp.html
title: lib/math/prime.hpp
---
