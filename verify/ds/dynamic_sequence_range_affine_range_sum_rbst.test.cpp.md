---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: lib/ds/rbst.hpp
    title: lib/ds/rbst.hpp
  - icon: ':question:'
    path: lib/internal.hpp
    title: lib/internal.hpp
  - icon: ':heavy_check_mark:'
    path: lib/math/static_modint.hpp
    title: lib/math/static_modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#line 2 \"lib/internal.hpp\"\n#include <cmath>\n#line 4 \"lib/internal.hpp\"\
    \n#include <cstring>\n#line 7 \"lib/internal.hpp\"\n\nusing i32 = int;\nusing\
    \ i64 = long long;\nusing i128 = __int128_t;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate<typename T>\
    \ using vec = std::vector<T>;\nusing pii = std::pair<int, int>;\n#line 3 \"lib/ds/rbst.hpp\"\
    \n\ntemplate <typename S, typename T>\nstruct RBST\n{\n  struct node_t\n  {\n\
    \    bool reverse;\n    T tag;\n    u32 size;\n    S prod;\n    S m;\n    node_t\
    \ *lc, *rc;\n\n    node_t() : reverse(false), tag(), size(0), prod(), m(), lc(nullptr),\
    \ rc(nullptr) {}\n    node_t(S m) : reverse(false), tag(), size(1), prod(m), m(m),\
    \ lc(nullptr), rc(nullptr) {}\n\n    void update()\n    {\n      size = 1;\n \
    \     prod = m;\n      if (lc) {\n        size = size + lc->size;\n        prod\
    \ = prod * lc->prod;\n      }\n      if (rc) {\n        size = size + rc->size;\n\
    \        prod = prod * rc->prod;\n      }\n    }\n\n    void toggle_reverse()\n\
    \    {\n      reverse = !reverse;\n      std::swap(lc, rc);\n    }\n\n    void\
    \ apply(const T &t)\n    {\n      prod = t(prod, size);\n      m = t(m, 1);\n\
    \      tag = tag * t;\n    }\n\n    void push()\n    {\n      if (reverse) {\n\
    \        if (lc) lc->toggle_reverse();\n        if (rc) rc->toggle_reverse();\n\
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
    \ == nullptr) return {};\n    return prod(l, r, 0, root->size, root);\n  }\n};\n\
    #line 3 \"lib/math/static_modint.hpp\"\n\ntemplate <int M>\nstruct static_modint\n\
    {\n  static constexpr u32 UM = M;\n  static_assert(UM < 0x80'00'00'00u);\n\n \
    \ u32 v;\n  constexpr static_modint() : v(0) {}\n\n  template <typename T, std::enable_if_t<std::is_signed_v<T>>*\
    \ = nullptr>\n  constexpr static_modint(T n) : v((n %= M) < 0 ? n + M : n) {}\n\
    \n  template <typename T, std::enable_if_t<std::is_unsigned_v<T>>* = nullptr>\n\
    \  constexpr static_modint(T n) : v(n %= UM) {}\n\n  using mint = static_modint;\n\
    \n  static mint raw(u32 v)\n  {\n    mint res;\n    res.v = v;\n    return res;\n\
    \  }\n\n  constexpr u32 val() const { return v; }\n\n  mint operator-() const\
    \ { return mint::raw(v == 0 ? 0u : UM - v); }\n\n  mint &operator+=(mint a)\n\
    \  {\n    if ((v += a.v) >= UM) v -= UM;\n    return *this;\n  }\n  mint &operator-=(mint\
    \ a)\n  {\n    if ((v += UM - a.v) >= UM) v -= UM;\n    return *this;\n  }\n \
    \ mint &operator*=(mint a)\n  {\n    v = (u64)v * a.v % UM;\n    return *this;\n\
    \  }\n  mint &operator/=(mint a) { return *this *= a.inv(); }\n\n  friend mint\
    \ operator+(mint a, mint b) { return a += b; }\n  friend mint operator-(mint a,\
    \ mint b) { return a -= b; }\n  friend mint operator*(mint a, mint b) { return\
    \ a *= b; }\n  friend mint operator/(mint a, mint b) { return a /= b; }\n\n  mint\
    \ pow(u64 n) const\n  {\n    mint res = 1, base = *this;\n    while (n) {\n  \
    \    if (n & 1) res *= base;\n      base *= base;\n      n >>= 1;\n    }\n   \
    \ return res;\n  }\n\n  mint inv() const { return pow(UM - 2); }\n};\n#line 18\
    \ \"verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp\"\n\nusing\
    \ mint = static_modint<998'244'353>;\n\nstruct SumMonoid\n{\n  mint sum;\n  SumMonoid()\
    \ : sum(0) {}\n  SumMonoid(mint sum) : sum(sum) {}\n\n  SumMonoid operator*(const\
    \ SumMonoid &s) const { return sum + s.sum; };\n};\n\nstruct AddTimesMonoid\n\
    {\n  mint k, b;\n  AddTimesMonoid() : k(1), b(0) {}\n  AddTimesMonoid(mint k,\
    \ mint b) : k(k), b(b) {}\n\n  AddTimesMonoid operator*(const AddTimesMonoid &a)\
    \ const\n  {\n    return {k * a.k, b * a.k + a.b};\n  };\n\n  SumMonoid operator()(const\
    \ SumMonoid &s, u32 size) const\n  {\n    return {s.sum * k + b * size};\n  }\n\
    \n  bool is_unit() const { return k.val() == 1 && b.val() == 0; }\n};\n\nint main()\n\
    {\n  std::ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\n  int n, Q;\n\
    \  std::cin >> n >> Q;\n  std::vector<mint> a(n);\n  for (auto &i : a) {\n   \
    \ int v;\n    std::cin >> v;\n    i = v;\n  }\n\n  RBST<SumMonoid, AddTimesMonoid>\
    \ t(n, [&a](u32 x) { return a[x]; });\n\n  for (int i = 0; i < Q; i++) {\n   \
    \ int op;\n    std::cin >> op;\n    if (op == 0) {\n      int i, x;\n      std::cin\
    \ >> i >> x;\n      t.insert(i, SumMonoid(x));\n    } else if (op == 1) {\n  \
    \    int i;\n      std::cin >> i;\n      t.remove(i);\n    } else if (op == 2)\
    \ {\n      int l, r;\n      std::cin >> l >> r;\n      t.reverse(l, r);\n    }\
    \ else if (op == 3) {\n      int l, r, b, c;\n      std::cin >> l >> r >> b >>\
    \ c;\n      t.apply(l, r, AddTimesMonoid(b, c));\n    } else if (op == 4) {\n\
    \      int l, r;\n      std::cin >> l >> r;\n      std::cout << t.prod(l, r).sum.val()\
    \ << \"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include <string>\n#include <tuple>\n\
    #include <vector>\n\nusing i64 = long long;\nusing i128 = __int128_t;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \n#include \"lib/ds/rbst.hpp\"\n#include \"lib/math/static_modint.hpp\"\n\nusing\
    \ mint = static_modint<998'244'353>;\n\nstruct SumMonoid\n{\n  mint sum;\n  SumMonoid()\
    \ : sum(0) {}\n  SumMonoid(mint sum) : sum(sum) {}\n\n  SumMonoid operator*(const\
    \ SumMonoid &s) const { return sum + s.sum; };\n};\n\nstruct AddTimesMonoid\n\
    {\n  mint k, b;\n  AddTimesMonoid() : k(1), b(0) {}\n  AddTimesMonoid(mint k,\
    \ mint b) : k(k), b(b) {}\n\n  AddTimesMonoid operator*(const AddTimesMonoid &a)\
    \ const\n  {\n    return {k * a.k, b * a.k + a.b};\n  };\n\n  SumMonoid operator()(const\
    \ SumMonoid &s, u32 size) const\n  {\n    return {s.sum * k + b * size};\n  }\n\
    \n  bool is_unit() const { return k.val() == 1 && b.val() == 0; }\n};\n\nint main()\n\
    {\n  std::ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\n  int n, Q;\n\
    \  std::cin >> n >> Q;\n  std::vector<mint> a(n);\n  for (auto &i : a) {\n   \
    \ int v;\n    std::cin >> v;\n    i = v;\n  }\n\n  RBST<SumMonoid, AddTimesMonoid>\
    \ t(n, [&a](u32 x) { return a[x]; });\n\n  for (int i = 0; i < Q; i++) {\n   \
    \ int op;\n    std::cin >> op;\n    if (op == 0) {\n      int i, x;\n      std::cin\
    \ >> i >> x;\n      t.insert(i, SumMonoid(x));\n    } else if (op == 1) {\n  \
    \    int i;\n      std::cin >> i;\n      t.remove(i);\n    } else if (op == 2)\
    \ {\n      int l, r;\n      std::cin >> l >> r;\n      t.reverse(l, r);\n    }\
    \ else if (op == 3) {\n      int l, r, b, c;\n      std::cin >> l >> r >> b >>\
    \ c;\n      t.apply(l, r, AddTimesMonoid(b, c));\n    } else if (op == 4) {\n\
    \      int l, r;\n      std::cin >> l >> r;\n      std::cout << t.prod(l, r).sum.val()\
    \ << \"\\n\";\n    }\n  }\n}\n"
  dependsOn:
  - lib/ds/rbst.hpp
  - lib/internal.hpp
  - lib/math/static_modint.hpp
  isVerificationFile: true
  path: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  requiredBy: []
  timestamp: '2024-06-07 18:17:19+08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
layout: document
redirect_from:
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
- /verify/verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp.html
title: verify/ds/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
---
