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
    path: verify/ds/area_of_union_of_rectangles.test.cpp
    title: verify/ds/area_of_union_of_rectangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  code: "#pragma once\n\n#include \"lib/internal.hpp\"\n#include \"lib/misc/bitop.hpp\"\
    \n\ntemplate <typename M> struct LazySegtree\n{\n  using MS = typename M::MS;\n\
    \  using MA = typename M::MA;\n  using S = typename M::S;\n  using A = typename\
    \ M::A;\n\n  u32 n, size, log;\n\n  std::vector<S> s;\n  std::vector<A> t;\n\n\
    \  void update(u32 p) { s[p] = MS::op(s[p * 2], s[p * 2 + 1]); }\n\n  void apply_at(u32\
    \ p, const A &a)\n  {\n    u32 len = size >> lg2(p);\n    s[p] = M::act(a, s[p],\
    \ len);\n    if (p < size) t[p] = MA::op(t[p], a);\n  }\n\n  void push(u32 p)\n\
    \  {\n    apply_at(p * 2, t[p]);\n    apply_at(p * 2 + 1, t[p]);\n    t[p] = MA::un();\n\
    \  }\n\n  template <typename F>\n  LazySegtree(u32 n, F &&f)\n      : n(n), size(btc(n)),\
    \ log(ctz(size)), s(size * 2, MS::un()), t(size, MA::un())\n  {\n    for (u32\
    \ i = 0; i < n; i++) s[i + size] = f(i);\n    for (u32 i = size; i--;) update(i);\n\
    \  }\n\n  LazySegtree(u32 n) : LazySegtree(n, [](u32) { return MS::un(); }) {}\n\
    \  LazySegtree(u32 n, const std::vector<S> &a)\n      : LazySegtree(n, [&](u32\
    \ i) { return a[i]; })\n  {\n  }\n\n  S prod(u32 l, u32 r)\n  {\n    l += size;\n\
    \    r += size;\n\n    for (u32 i = log; i >= 1; i--) {\n      if (((l >> i) <<\
    \ i) != l) push(l >> i);\n      if (((r >> i) << i) != l) push((r - 1) >> i);\n\
    \    }\n\n    auto ls = MS::unit(), rs = MS::unit();\n    while (l < r) {\n  \
    \    if (l & 1) ls = MS::op(ls, s[l++]);\n      if (r & 1) rs = MS::op(s[--r],\
    \ rs);\n      l >>= 1;\n      r >>= 1;\n    }\n\n    return MS::op(ls, rs);\n\
    \  }\n\n  S prod_all() const { return s[1]; }\n\n  void apply(u32 l, u32 r, const\
    \ A &a)\n  {\n    l += size;\n    r += size;\n\n    for (u32 i = log; i >= 1;\
    \ i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) <<\
    \ i) != r) push((r - 1) >> i);\n    }\n\n    {\n      auto l2 = l, r2 = r;\n \
    \     while (l < r) {\n        if (l & 1) apply_at(l++, a);\n        if (r & 1)\
    \ apply_at(--r, a);\n        l >>= 1;\n        r >>= 1;\n      }\n      l = l2;\n\
    \      r = r2;\n    }\n\n    for (u32 i = 1; i <= log; i++) {\n      if (((l >>\
    \ i) << i) != l) update(l >> i);\n      if (((r >> i) << i) != r) update((r -\
    \ 1) >> i);\n    }\n  }\n\n  void set(u32 p, const S &v)\n  {\n    p += size;\n\
    \    for (u32 i = log; i >= 1; i--) push(p >> i);\n    t[p] = v;\n    for (u32\
    \ i = 1; i <= log; i++) update(p >> i);\n  }\n\n  S get(u32 p)\n  {\n    p +=\
    \ size;\n    for (u32 i = log; i >= 1; i--) push(p >> i);\n    return t[p];\n\
    \  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  - lib/misc/bitop.hpp
  isVerificationFile: false
  path: lib/ds/lazysegtree.hpp
  requiredBy: []
  timestamp: '2024-06-14 21:22:57+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/area_of_union_of_rectangles.test.cpp
documentation_of: lib/ds/lazysegtree.hpp
layout: document
redirect_from:
- /library/lib/ds/lazysegtree.hpp
- /library/lib/ds/lazysegtree.hpp.html
title: lib/ds/lazysegtree.hpp
---
