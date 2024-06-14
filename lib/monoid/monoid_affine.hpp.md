---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':question:'
    path: lib/monoid/monoid_trait.hpp
    title: lib/monoid/monoid_trait.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ lib/internal.hpp: line 4: #pragma once found in a non-first line\n"
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include \"lib/monoid/monoid_trait.hpp\"\
    \n\nnamespace mono {\n\n#if __cplusplus >= 202000U\ntemplate <typename T, auto\
    \ None = cintf<-1ll>> struct MonoidAssign\n#else\ntemplate <typename T, T (*None)()\
    \ = cintf<-1ll>> struct MonoidAssign\n#endif\n{\n  using S = T;\n  static constexpr\
    \ S s_none = S(None());\n  static constexpr S op(const S &x, const S &y) { return\
    \ y == s_none ? x : y; }\n  static constexpr const S un() { return s_none; }\n\
    \  static constexpr bool cm = false;\n};\n\n} // namespace mono"
  dependsOn:
  - lib/internal.hpp
  - lib/monoid/monoid_trait.hpp
  isVerificationFile: false
  path: lib/monoid/monoid_affine.hpp
  requiredBy: []
  timestamp: '2024-06-14 21:22:57+08:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: lib/monoid/monoid_affine.hpp
layout: document
redirect_from:
- /library/lib/monoid/monoid_affine.hpp
- /library/lib/monoid/monoid_affine.hpp.html
title: lib/monoid/monoid_affine.hpp
---
