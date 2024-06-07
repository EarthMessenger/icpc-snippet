---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#include <vector>\n\
    #include <cstring>\n#include <iostream>\n#include <algorithm>\n\nusing i32 = int;\n\
    using i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename\
    \ T> using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 2 \"\
    lib/ds/rbst.hpp\"\n\ntemplate <typename S, typename T>\nstruct RBST\n{\n  struct\
    \ node_t\n  {\n    bool reverse;\n    T tag;\n    u32 size;\n    S prod;\n   \
    \ S m;\n    node_t *lc, *rc;\n\n    node_t() : reverse(false), tag(), size(0),\
    \ prod(), m(), lc(nullptr), rc(nullptr) {}\n    node_t(S m) : reverse(false),\
    \ tag(), size(1), prod(m), m(m), lc(nullptr), rc(nullptr) {}\n\n    void update()\n\
    \    {\n      size = 1;\n      prod = m;\n      if (lc) {\n        size = size\
    \ + lc->size;\n        prod = prod * lc->prod;\n      }\n      if (rc) {\n   \
    \     size = size + rc->size;\n        prod = prod * rc->prod;\n      }\n    }\n\
    \n    void toggle_reverse()\n    {\n      reverse = !reverse;\n      std::swap(lc,\
    \ rc);\n    }\n\n    void apply(const T &t)\n    {\n      prod = t(prod, size);\n\
    \      m = t(m, 1);\n      tag = tag * t;\n    }\n\n    void push()\n    {\n \
    \     if (reverse) {\n        if (lc) lc->toggle_reverse();\n        if (rc) rc->toggle_reverse();\n\
    \        reverse = false;\n      }\n      if (!tag.is_unit()) {\n        if (lc)\
    \ lc->apply(tag);\n        if (rc) rc->apply(tag);\n        tag = T{};\n     \
    \ }\n    }\n  };\n\n  node_t *root;\n\n  // \u53EF\u7528 std::mt19937 \u4E4B\u985E\
    \u4EE3\u66FF\n  static u32 get_random()\n  {\n    static u32 x = 123456789;\n\
    \    static u32 y = 362436069;\n    static u32 z = 521288629;\n    static u32\
    \ w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n\
    \    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  };\n\n  static bool choice(u32\
    \ ls, u32 rs)\n  {\n    return get_random() % (ls + rs) < ls;\n  }\n\n  RBST()\
    \ : root(nullptr) {}\n  template <typename F>\n  RBST(u32 n, F &&f) : root(build_tree(0,\
    \ n, f)) {}\n\n  template <typename F>\n  static node_t *build_tree(u32 l, u32\
    \ r, F &&f)\n  {\n    if (r - l == 0) return nullptr;\n    u32 mid = l + (r -\
    \ l) / 2;\n    auto p = new node_t(f(mid));\n    p->lc = build_tree(l, mid, f);\n\
    \    p->rc = build_tree(mid + 1, r, f);\n    p->update();\n    return p;\n  }\n\
    \n  static std::pair<node_t *, node_t *> split(u32 k, node_t *p)\n  {\n    if\
    \ (p == nullptr) return {nullptr, nullptr};\n\n    p->push();\n    u32 ls = p->lc\
    \ ? p->lc->size : 0;\n    if (ls < k) {\n      node_t *r;\n      std::tie(p->rc,\
    \ r) = split(k - ls - 1, p->rc);\n      p->update();\n      return {p, r};\n \
    \   } else {\n      node_t *l;\n      std::tie(l, p->lc) = split(k, p->lc);\n\
    \      p->update();\n      return {l, p};\n    }\n  }\n\n  static node_t *join(node_t\
    \ *p, node_t *q)\n  {\n    if (p == nullptr) return q;\n    if (q == nullptr)\
    \ return p;\n\n    if (choice(p->size, q->size)) {\n      p->push();\n      p->rc\
    \ = join(p->rc, q);\n      p->update();\n      return p;\n    } else {\n     \
    \ q->push();\n      q->lc = join(p, q->lc);\n      q->update();\n      return\
    \ q;\n    }\n  }\n\n  static node_t *join3(node_t *p1, node_t *p2, node_t *p3)\n\
    \  {\n    return join(p1, join(p2, p3));\n  }\n\n  void insert(u32 i, S m)\n \
    \ {\n    auto [lp, rp] = split(i, root);\n    root = join3(lp, new node_t(m),\
    \ rp);\n  }\n\n  void remove(u32 i)\n  {\n    auto [lp, irp] = split(i, root);\n\
    \    auto [ip, rp] = split(1, irp);\n    root = join(lp, rp);\n  }\n\n  void reverse(u32\
    \ l, u32 r)\n  {\n    auto [lp, mrp] = split(l, root);\n    auto [mp, rp] = split(r\
    \ - l, mrp);\n    if (mp) mp->toggle_reverse();\n    root = join3(lp, mp, rp);\n\
    \  }\n\n  void apply(u32 l, u32 r, const T &m)\n  {\n    auto [lp, mrp] = split(l,\
    \ root);\n    auto [mp, rp] = split(r - l, mrp);\n    if (mp) mp->apply(m);\n\
    \    root = join3(lp, mp, rp);\n  }\n\n  static S prod(u32 l, u32 r, u32 ll, u32\
    \ rr, node_t *p)\n  {\n    if (p == nullptr) return {};\n\n    if (l <= ll &&\
    \ rr <= r) {\n      return p->prod;\n    } else {\n      p->push();\n\n      u32\
    \ mid = ll + (p->lc ? p->lc->size : 0);\n      S res;\n      if (l < mid) res\
    \ = res * prod(l, r, ll, mid, p->lc);\n      if (l <= mid && mid < r) res = res\
    \ * p->m;\n      if (mid + 1 < r) res = res * prod(l, r, mid + 1, rr, p->rc);\n\
    \      return res;\n    }\n  }\n\n  S prod(u32 l, u32 r) const\n  {\n    if (root\
    \ == nullptr) return {};\n    return prod(l, r, 0, root->size, root);\n  }\n};\n"
  code: "#include \"lib/internal.hpp\"\n\ntemplate <typename S, typename T>\nstruct\
    \ RBST\n{\n  struct node_t\n  {\n    bool reverse;\n    T tag;\n    u32 size;\n\
    \    S prod;\n    S m;\n    node_t *lc, *rc;\n\n    node_t() : reverse(false),\
    \ tag(), size(0), prod(), m(), lc(nullptr), rc(nullptr) {}\n    node_t(S m) :\
    \ reverse(false), tag(), size(1), prod(m), m(m), lc(nullptr), rc(nullptr) {}\n\
    \n    void update()\n    {\n      size = 1;\n      prod = m;\n      if (lc) {\n\
    \        size = size + lc->size;\n        prod = prod * lc->prod;\n      }\n \
    \     if (rc) {\n        size = size + rc->size;\n        prod = prod * rc->prod;\n\
    \      }\n    }\n\n    void toggle_reverse()\n    {\n      reverse = !reverse;\n\
    \      std::swap(lc, rc);\n    }\n\n    void apply(const T &t)\n    {\n      prod\
    \ = t(prod, size);\n      m = t(m, 1);\n      tag = tag * t;\n    }\n\n    void\
    \ push()\n    {\n      if (reverse) {\n        if (lc) lc->toggle_reverse();\n\
    \        if (rc) rc->toggle_reverse();\n        reverse = false;\n      }\n  \
    \    if (!tag.is_unit()) {\n        if (lc) lc->apply(tag);\n        if (rc) rc->apply(tag);\n\
    \        tag = T{};\n      }\n    }\n  };\n\n  node_t *root;\n\n  // \u53EF\u7528\
    \ std::mt19937 \u4E4B\u985E\u4EE3\u66FF\n  static u32 get_random()\n  {\n    static\
    \ u32 x = 123456789;\n    static u32 y = 362436069;\n    static u32 z = 521288629;\n\
    \    static u32 w = 88675123;\n    u32 t = x ^ (x << 11);\n    x = y;\n    y =\
    \ z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n  };\n\n \
    \ static bool choice(u32 ls, u32 rs)\n  {\n    return get_random() % (ls + rs)\
    \ < ls;\n  }\n\n  RBST() : root(nullptr) {}\n  template <typename F>\n  RBST(u32\
    \ n, F &&f) : root(build_tree(0, n, f)) {}\n\n  template <typename F>\n  static\
    \ node_t *build_tree(u32 l, u32 r, F &&f)\n  {\n    if (r - l == 0) return nullptr;\n\
    \    u32 mid = l + (r - l) / 2;\n    auto p = new node_t(f(mid));\n    p->lc =\
    \ build_tree(l, mid, f);\n    p->rc = build_tree(mid + 1, r, f);\n    p->update();\n\
    \    return p;\n  }\n\n  static std::pair<node_t *, node_t *> split(u32 k, node_t\
    \ *p)\n  {\n    if (p == nullptr) return {nullptr, nullptr};\n\n    p->push();\n\
    \    u32 ls = p->lc ? p->lc->size : 0;\n    if (ls < k) {\n      node_t *r;\n\
    \      std::tie(p->rc, r) = split(k - ls - 1, p->rc);\n      p->update();\n  \
    \    return {p, r};\n    } else {\n      node_t *l;\n      std::tie(l, p->lc)\
    \ = split(k, p->lc);\n      p->update();\n      return {l, p};\n    }\n  }\n\n\
    \  static node_t *join(node_t *p, node_t *q)\n  {\n    if (p == nullptr) return\
    \ q;\n    if (q == nullptr) return p;\n\n    if (choice(p->size, q->size)) {\n\
    \      p->push();\n      p->rc = join(p->rc, q);\n      p->update();\n      return\
    \ p;\n    } else {\n      q->push();\n      q->lc = join(p, q->lc);\n      q->update();\n\
    \      return q;\n    }\n  }\n\n  static node_t *join3(node_t *p1, node_t *p2,\
    \ node_t *p3)\n  {\n    return join(p1, join(p2, p3));\n  }\n\n  void insert(u32\
    \ i, S m)\n  {\n    auto [lp, rp] = split(i, root);\n    root = join3(lp, new\
    \ node_t(m), rp);\n  }\n\n  void remove(u32 i)\n  {\n    auto [lp, irp] = split(i,\
    \ root);\n    auto [ip, rp] = split(1, irp);\n    root = join(lp, rp);\n  }\n\n\
    \  void reverse(u32 l, u32 r)\n  {\n    auto [lp, mrp] = split(l, root);\n   \
    \ auto [mp, rp] = split(r - l, mrp);\n    if (mp) mp->toggle_reverse();\n    root\
    \ = join3(lp, mp, rp);\n  }\n\n  void apply(u32 l, u32 r, const T &m)\n  {\n \
    \   auto [lp, mrp] = split(l, root);\n    auto [mp, rp] = split(r - l, mrp);\n\
    \    if (mp) mp->apply(m);\n    root = join3(lp, mp, rp);\n  }\n\n  static S prod(u32\
    \ l, u32 r, u32 ll, u32 rr, node_t *p)\n  {\n    if (p == nullptr) return {};\n\
    \n    if (l <= ll && rr <= r) {\n      return p->prod;\n    } else {\n      p->push();\n\
    \n      u32 mid = ll + (p->lc ? p->lc->size : 0);\n      S res;\n      if (l <\
    \ mid) res = res * prod(l, r, ll, mid, p->lc);\n      if (l <= mid && mid < r)\
    \ res = res * p->m;\n      if (mid + 1 < r) res = res * prod(l, r, mid + 1, rr,\
    \ p->rc);\n      return res;\n    }\n  }\n\n  S prod(u32 l, u32 r) const\n  {\n\
    \    if (root == nullptr) return {};\n    return prod(l, r, 0, root->size, root);\n\
    \  }\n};\n"
  dependsOn:
  - lib/internal.hpp
  isVerificationFile: false
  path: lib/ds/rbst.hpp
  requiredBy: []
  timestamp: '2024-06-07 16:37:49+08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
documentation_of: lib/ds/rbst.hpp
layout: document
redirect_from:
- /library/lib/ds/rbst.hpp
- /library/lib/ds/rbst.hpp.html
title: lib/ds/rbst.hpp
---
