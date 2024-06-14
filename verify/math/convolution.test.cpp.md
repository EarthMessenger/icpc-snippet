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
  - icon: ':question:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/misc/bitop.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"lib/misc/bitop.hpp\"\n#include \"lib/math/convolution.hpp\"\n#include \"lib/math/static_modint.hpp\"\
    \n\nsigned main() \n{\n    using namespace std;\n    ios::sync_with_stdio(false);\
    \ cin.tie(0), cout.tie(0);\n    using mint = static_modint<998244353>;\n    auto\
    \ read_int = [x = int()]() mutable { return cin >> x, x; };\n    u32 n = read_int(),\
    \ m = read_int();\n    u32 p = lg2(max(btc(n), btc(m))) + 1, q = 1 << p;\n   \
    \ vec<mint> a(q), b(q);\n    for (u32 i = 0; i < n; i++) a[i] = read_int();\n\
    \    for (u32 i = 0; i < m; i++) b[i] = read_int();\n    auto base = [](u32 h)\
    \ { return mint::raw(3).pow(998244352 / h); };\n    auto inv = [iv2 = mint(q).inv()](mint\
    \ &x,[[maybe_unused]] u32 y){x *= iv2;};\n    poly::fourier_transform<0>(p, a,\
    \ base, inv, mint::raw(1));\n    poly::fourier_transform<0>(p, b, base, inv, mint::raw(1));\n\
    \    for (u32 i = 0; i < q; i++) a[i] *= b[i];\n    poly::fourier_transform<1>(p,\
    \ a, base, inv, mint::raw(1));\n    reverse(a.begin() + 1, a.end());\n    for\
    \ (u32 i = 0; i < n + m - 1; i++) cout << a[i].val() << ' ';\n    cout << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - lib/misc/bitop.hpp
  - lib/internal.hpp
  - lib/math/convolution.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/math/convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 19:20:52+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/math/convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/math/convolution.test.cpp
- /verify/verify/math/convolution.test.cpp.html
title: verify/math/convolution.test.cpp
---
