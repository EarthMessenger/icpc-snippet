---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lucas Theorem
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/math/lucas.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Lucas Theorem\n * @todo exLucas\n */\n#pragma once\n#include\
    \ \"lib/internal.hpp\"\n\ntemplate <typename T, typename M> M lucas(long long\
    \ n, long long m, T binom)\n{\n  if (m == 0) return M::raw(1);\n  return binom(n\
    \ % P, m % P) * lucas(n / P, m / P);\n}\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/math/lucas.hpp
  requiredBy: []
  timestamp: '2024-06-13 09:43:47+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/math/lucas.hpp
layout: document
redirect_from:
- /library/lib/math/lucas.hpp
- /library/lib/math/lucas.hpp.html
title: Lucas Theorem
---
