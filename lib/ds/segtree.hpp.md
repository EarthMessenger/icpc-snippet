---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  - icon: ':heavy_check_mark:'
    path: lib/misc/bitop.hpp
    title: Bit Manipulation
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_add_range_sum.test.cpp
    title: verify/ds/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/ds/point_set_range_composite.test.cpp
    title: verify/ds/point_set_range_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Segment Tree
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n#include \"lib/misc/bitop.hpp\"\
    \n/**\n * @brief Segment Tree\n *\n * @tparam S info: monoid\n * @tparam F merge:\
    \ F: f(a: S, b: S) -> S\n */\ntemplate <typename S, typename F> struct SegmentTree\n\
    {\n  u32 m;\n  vec<S> t;\n\n  const S e;\n  const F op;\n\n  SegmentTree() {}\n\
    \  SegmentTree(u32 n, const S &_e, const F &_op)\n      : m(btc(n)), t(m * 2,\
    \ _e), e(_e), op(_op)\n  {\n  }\n  template <typename I>\n  SegmentTree(u32 n,\
    \ const I &f, const S &_e, const F &_op)\n      : m(btc(n)), t(m * 2, _e), e(_e),\
    \ op(_op)\n  {\n    for (u32 i = 0; i < n; i++) t[i + m] = f(i);\n    for (u32\
    \ i = m - 1; ~i; i--) t[i] = op(t[i * 2], t[i * 2 + 1]);\n  }\n\n  void set(u32\
    \ p, const S &v)\n  {\n    t[p += m] = v;\n    for (p /= 2; p; p /= 2) t[p] =\
    \ op(t[p * 2], t[p * 2 + 1]);\n  }\n\n  S get(u32 p) { return t[p + m]; }\n  S\
    \ prod(u32 l, u32 r)\n  {\n    S lans = e, rans = e;\n    for (l += m, r += m;\
    \ l < r; l /= 2, r /= 2) {\n      if (l & 1) lans = op(lans, t[l++]);\n      if\
    \ (r & 1) rans = op(t[--r], rans);\n    }\n    return op(lans, rans);\n  }\n \
    \ S all_prod() { return t[1]; }\n};"
  dependsOn:
  - lib/internal.hpp
  - lib/misc/bitop.hpp
  isVerificationFile: false
  path: lib/ds/segtree.hpp
  requiredBy: []
  timestamp: '2024-06-13 09:43:47+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/point_add_range_sum.test.cpp
  - verify/ds/point_set_range_composite.test.cpp
documentation_of: lib/ds/segtree.hpp
layout: document
redirect_from:
- /library/lib/ds/segtree.hpp
- /library/lib/ds/segtree.hpp.html
title: Segment Tree
---
