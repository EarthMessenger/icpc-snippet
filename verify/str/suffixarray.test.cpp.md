---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/str/sa.hpp
    title: lib/str/sa.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/suffixarray
    links:
    - https://judge.yosupo.jp/problem/suffixarray
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/suffixarray\"\n\n#include\
    \ \"lib/internal.hpp\"\n#include \"lib/str/sa.hpp\"\n\nint main()\n{\n  std::string\
    \ s;\n  std::cin >> s;\n\n  auto [sa, rk] = suffix_array(s);\n\n  for (auto i\
    \ : sa) std::cout << i << \" \";\n  std::cout << std::endl;\n}\n"
  dependsOn:
  - lib/internal.hpp
  - lib/str/sa.hpp
  isVerificationFile: true
  path: verify/str/suffixarray.test.cpp
  requiredBy: []
  timestamp: '2024-06-14 10:22:24+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/str/suffixarray.test.cpp
layout: document
redirect_from:
- /verify/verify/str/suffixarray.test.cpp
- /verify/verify/str/suffixarray.test.cpp.html
title: verify/str/suffixarray.test.cpp
---
