---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: lib/ds/splay.hpp
    title: Splay Tree
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':question:'
    path: lib/math/static_modint.hpp
    title: Static Modint
  - icon: ':question:'
    path: lib/monoid/monoid_add.hpp
    title: lib/monoid/monoid_add.hpp
  - icon: ':x:'
    path: lib/monoid/monoid_linear_function.hpp
    title: lib/monoid/monoid_linear_function.hpp
  - icon: ':question:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#include \"lib/ds/splay.hpp\"\n#include \"lib/math/static_modint.hpp\"\n#include\
    \ \"lib/monoid/monoid_add.hpp\"\n#include \"lib/monoid/monoid_linear_function.hpp\"\
    \n\nusing mint = static_modint<998'244'353>;\n\nmint operator*(const std::pair<mint,\
    \ mint> &a, const mint &b)\n{\n  return a.first * b + a.second;\n}\n\nint main()\n\
    {\n  std::ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\n  int n, Q;\n\
    \  std::cin >> n >> Q;\n  std::vector<mint> a(n);\n  for (auto &i : a) {\n   \
    \ int v;\n    std::cin >> v;\n    i = v;\n  }\n\n  Splay<mono::BidirActedMonoidTrait<mono::ActedMonoidTrait<\n\
    \      mono::MonoidLinearFunc<mint>, mono::MonoidAdd<mint>>>>\n      t(n, [&a](u32\
    \ x) { return a[x]; });\n\n  for (int i = 0; i < Q; i++) {\n    int op;\n    std::cin\
    \ >> op;\n    if (op == 0) {\n      int i, x;\n      std::cin >> i >> x;\n   \
    \   t.insert(i, x);\n    } else if (op == 1) {\n      int i;\n      std::cin >>\
    \ i;\n      t.remove(i);\n    } else if (op == 2) {\n      int l, r;\n      std::cin\
    \ >> l >> r;\n      t.reverse(l, r);\n    } else if (op == 3) {\n      int l,\
    \ r, b, c;\n      std::cin >> l >> r >> b >> c;\n      t.apply(l, r, {b, c});\n\
    \    } else if (op == 4) {\n      int l, r;\n      std::cin >> l >> r;\n     \
    \ std::cout << t.prod(l, r).val() << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - lib/ds/splay.hpp
  - lib/internal.hpp
  - lib/math/static_modint.hpp
  - lib/monoid/monoid_add.hpp
  - lib/monoid/monoid_trait.hpp
  - lib/monoid/monoid_linear_function.hpp
  isVerificationFile: true
  path: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 21:22:57+08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: verify/ds/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
