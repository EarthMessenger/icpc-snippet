---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/math/convolution.hpp
    title: Polynomial Convolution
  - icon: ':question:'
    path: lib/math/static_modint.hpp
    title: Static Modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/math/convolution.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"lib/math/convolution.hpp\"\n#include \"lib/math/static_modint.hpp\"\
    \n\nsigned main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ \n    cin.tie(0), cout.tie(0);\n    u32 n;\n    cin >> n;\n    using mint =\
    \ static_modint<998244353>;\n    vec<mint> a(1 << n), b(1 << n);\n    auto read_int\
    \ = [x = int()]() mutable { return cin >> x, x; };\n    for (auto &i: a) i = read_int();\n\
    \    for (auto &i: b) i = read_int();\n    poly::bit::compliment(n, a);\n    poly::bit::compliment(n,\
    \ b);\n    poly::bit::sosdp<0>(n, a);\n    poly::bit::sosdp<0>(n, b);\n    for\
    \ (u32 i = 0; i < (1u << n); i++) a[i] *= b[i];\n    poly::bit::sosdp<1>(n, a);\n\
    \    poly::bit::compliment(n, a);\n    for (auto i: a) cout << i.val() << ' ';\n\
    \    return 0;\n}"
  dependsOn:
  - lib/math/convolution.hpp
  - lib/internal.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/math/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:20:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/math/bitwise_and_convolution.test.cpp
- /verify/verify/math/bitwise_and_convolution.test.cpp.html
title: verify/math/bitwise_and_convolution.test.cpp
---