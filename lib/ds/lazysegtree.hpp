#pragma once

#include "lib/internal.hpp"
#include "lib/misc/bitop.hpp"

template <typename M> struct LazySegtree
{
  using MS = typename M::MS;
  using MA = typename M::MA;
  using S = typename M::S;
  using A = typename M::A;

  u32 n, size, log;

  std::vector<S> s;
  std::vector<A> t;

  void update(u32 p) { s[p] = MS::op(s[p * 2], s[p * 2 + 1]); }

  void apply_at(u32 p, const A &a)
  {
    u32 len = size >> lg2(p);
    s[p] = M::act(a, s[p], len);
    if (p < size) t[p] = MA::op(t[p], a);
  }

  void push(u32 p)
  {
    apply_at(p * 2, t[p]);
    apply_at(p * 2 + 1, t[p]);
    t[p] = MA::un();
  }

  template <typename F>
  LazySegtree(u32 n, F &&f)
      : n(n), size(btc(n)), log(ctz(size)), s(size * 2, MS::un()), t(size, MA::un())
  {
    for (u32 i = 0; i < n; i++) s[i + size] = f(i);
    for (u32 i = size; i--;) update(i);
  }

  LazySegtree(u32 n) : LazySegtree(n, [](u32) { return MS::un(); }) {}
  LazySegtree(u32 n, const std::vector<S> &a)
      : LazySegtree(n, [&](u32 i) { return a[i]; })
  {
  }

  S prod(u32 l, u32 r)
  {
    l += size;
    r += size;

    for (u32 i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != l) push((r - 1) >> i);
    }

    auto ls = MS::unit(), rs = MS::unit();
    while (l < r) {
      if (l & 1) ls = MS::op(ls, s[l++]);
      if (r & 1) rs = MS::op(s[--r], rs);
      l >>= 1;
      r >>= 1;
    }

    return MS::op(ls, rs);
  }

  S prod_all() const { return s[1]; }

  void apply(u32 l, u32 r, const A &a)
  {
    l += size;
    r += size;

    for (u32 i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) push(l >> i);
      if (((r >> i) << i) != r) push((r - 1) >> i);
    }

    {
      auto l2 = l, r2 = r;
      while (l < r) {
        if (l & 1) apply_at(l++, a);
        if (r & 1) apply_at(--r, a);
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (u32 i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) update(l >> i);
      if (((r >> i) << i) != r) update((r - 1) >> i);
    }
  }

  void set(u32 p, const S &v)
  {
    p += size;
    for (u32 i = log; i >= 1; i--) push(p >> i);
    t[p] = v;
    for (u32 i = 1; i <= log; i++) update(p >> i);
  }

  S get(u32 p)
  {
    p += size;
    for (u32 i = log; i >= 1; i--) push(p >> i);
    return t[p];
  }
};
