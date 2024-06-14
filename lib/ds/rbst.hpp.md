---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: lib/internal.hpp
    title: Internal Definition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Random Binary Search Tree
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
  code: "#pragma once\n#include \"lib/internal.hpp\"\n\n/**\n * @brief Random Binary\
    \ Search Tree\n *\n * @tparam BAM bidirected_acted_monoid\n */\ntemplate <typename\
    \ BAM> struct RBST\n{\n  using S = typename BAM::S;\n  using A = typename BAM::A;\n\
    \  struct node_t\n  {\n    bool reverse;\n    A tag;\n    u32 size;\n    S prod;\n\
    \    S m;\n    node_t *lc, *rc;\n\n    node_t()\n        : reverse(false), tag(BAM::MA::un()),\
    \ size(0), prod(BAM::un()),\n          m(BAM::un()), lc(nullptr), rc(nullptr)\n\
    \    {\n    }\n    node_t(S _m)\n        : reverse(false), tag(BAM::MA::un()),\
    \ size(1), prod(_m), m(_m),\n          lc(nullptr), rc(nullptr)\n    {\n    }\n\
    \n    void update()\n    {\n      size = 1;\n      prod = m;\n      if (lc) {\n\
    \        size = size + lc->size;\n        prod = BAM::op(prod, lc->prod);\n  \
    \    }\n      if (rc) {\n        size = size + rc->size;\n        prod = BAM::op(prod,\
    \ rc->prod);\n      }\n    }\n\n    void toggle_reverse()\n    {\n      reverse\
    \ = !reverse;\n      std::swap(lc, rc);\n      prod = BAM::ts(prod);\n    }\n\n\
    \    void apply(const A &t)\n    {\n      prod = BAM::act(t, prod, size);\n  \
    \    m = BAM::act(t, m, 1);\n      tag = BAM::MA::op(tag, t);\n    }\n\n    void\
    \ push()\n    {\n      if (reverse) {\n        if (lc) lc->toggle_reverse();\n\
    \        if (rc) rc->toggle_reverse();\n        reverse = false;\n      }\n  \
    \    if (tag != BAM::MA::un()) {\n        if (lc) lc->apply(tag);\n        if\
    \ (rc) rc->apply(tag);\n        tag = BAM::MA::un();\n      }\n    }\n  };\n\n\
    \  node_t *root;\n\n  // \u53EF\u7528 std::mt19937 \u4E4B\u985E\u4EE3\u66FF\n\
    \  static u32 get_random()\n  {\n    static u32 x = 123456789;\n    static u32\
    \ y = 362436069;\n    static u32 z = 521288629;\n    static u32 w = 88675123;\n\
    \    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w\
    \ = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  };\n\n  static bool choice(u32 ls, u32\
    \ rs) { return get_random() % (ls + rs) < ls; }\n\n  RBST() : root(nullptr) {}\n\
    \  template <typename F> RBST(u32 n, F &&f) : root(build_tree(0, n, f)) {}\n\n\
    \  template <typename F> static node_t *build_tree(u32 l, u32 r, F &&f)\n  {\n\
    \    if (r - l == 0) return nullptr;\n    u32 mid = l + (r - l) / 2;\n    auto\
    \ p = new node_t(f(mid));\n    p->lc = build_tree(l, mid, f);\n    p->rc = build_tree(mid\
    \ + 1, r, f);\n    p->update();\n    return p;\n  }\n\n  static std::pair<node_t\
    \ *, node_t *> split(u32 k, node_t *p)\n  {\n    if (p == nullptr) return {nullptr,\
    \ nullptr};\n\n    p->push();\n    u32 ls = p->lc ? p->lc->size : 0;\n    if (ls\
    \ < k) {\n      node_t *r;\n      std::tie(p->rc, r) = split(k - ls - 1, p->rc);\n\
    \      p->update();\n      return {p, r};\n    } else {\n      node_t *l;\n  \
    \    std::tie(l, p->lc) = split(k, p->lc);\n      p->update();\n      return {l,\
    \ p};\n    }\n  }\n\n  static node_t *join(node_t *p, node_t *q)\n  {\n    if\
    \ (p == nullptr) return q;\n    if (q == nullptr) return p;\n\n    if (choice(p->size,\
    \ q->size)) {\n      p->push();\n      p->rc = join(p->rc, q);\n      p->update();\n\
    \      return p;\n    } else {\n      q->push();\n      q->lc = join(p, q->lc);\n\
    \      q->update();\n      return q;\n    }\n  }\n\n  static node_t *join3(node_t\
    \ *p1, node_t *p2, node_t *p3)\n  {\n    return join(p1, join(p2, p3));\n  }\n\
    \n  void insert(u32 i, S m)\n  {\n    auto [lp, rp] = split(i, root);\n    root\
    \ = join3(lp, new node_t(m), rp);\n  }\n\n  void remove(u32 i)\n  {\n    auto\
    \ [lp, irp] = split(i, root);\n    auto [ip, rp] = split(1, irp);\n    root =\
    \ join(lp, rp);\n  }\n\n  void reverse(u32 l, u32 r)\n  {\n    auto [lp, mrp]\
    \ = split(l, root);\n    auto [mp, rp] = split(r - l, mrp);\n    if (mp) mp->toggle_reverse();\n\
    \    root = join3(lp, mp, rp);\n  }\n\n  void apply(u32 l, u32 r, const A &m)\n\
    \  {\n    auto [lp, mrp] = split(l, root);\n    auto [mp, rp] = split(r - l, mrp);\n\
    \    if (mp) mp->apply(m);\n    root = join3(lp, mp, rp);\n  }\n\n  static S prod(u32\
    \ l, u32 r, u32 ll, u32 rr, node_t *p)\n  {\n    if (p == nullptr) return {};\n\
    \n    if (l <= ll && rr <= r) {\n      return p->prod;\n    } else {\n      p->push();\n\
    \n      u32 mid = ll + (p->lc ? p->lc->size : 0);\n      S res = BAM::un();\n\
    \      if (l < mid) res = BAM::op(res, prod(l, r, ll, mid, p->lc));\n      if\
    \ (l <= mid && mid < r) res = BAM::op(res, p->m);\n      if (mid + 1 < r) res\
    \ = BAM::op(res, prod(l, r, mid + 1, rr, p->rc));\n      return res;\n    }\n\
    \  }\n\n  S prod(u32 l, u32 r) const\n  {\n    if (root == nullptr) return BAM::un();\n\
    \    return prod(l, r, 0, root->size, root);\n  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/rbst.hpp
  requiredBy: []
  timestamp: '2024-06-14 21:22:57+08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: lib/ds/rbst.hpp
layout: document
redirect_from:
- /library/lib/ds/rbst.hpp
- /library/lib/ds/rbst.hpp.html
title: Random Binary Search Tree
---
