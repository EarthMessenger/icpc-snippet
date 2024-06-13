#pragma once
#include "lib/internal.hpp"
#include "lib/misc/bitop.hpp"
/**
 * @brief Segment Tree
 *
 * @tparam S info: monoid
 * @tparam F merge: F: f(a: S, b: S) -> S
 */
template <typename S, typename F> struct SegmentTree
{
  u32 m;
  vec<S> t;

  const S e;
  const F op;

  SegmentTree() {}
  SegmentTree(u32 n, const S &_e, const F &_op)
      : m(btc(n)), t(m * 2, _e), e(_e), op(_op)
  {
  }
  template <typename I>
  SegmentTree(u32 n, const I &f, const S &_e, const F &_op)
      : m(btc(n)), t(m * 2, _e), e(_e), op(_op)
  {
    for (u32 i = 0; i < n; i++) t[i + m] = f(i);
    for (u32 i = m - 1; ~i; i--) t[i] = op(t[i * 2], t[i * 2 + 1]);
  }

  void set(u32 p, const S &v)
  {
    t[p += m] = v;
    for (p /= 2; p; p /= 2) t[p] = op(t[p * 2], t[p * 2 + 1]);
  }

  S get(u32 p) { return t[p + m]; }
  S prod(u32 l, u32 r)
  {
    S lans = e, rans = e;
    for (l += m, r += m; l < r; l /= 2, r /= 2) {
      if (l & 1) lans = op(lans, t[l++]);
      if (r & 1) rans = op(t[--r], rans);
    }
    return op(lans, rans);
  }
  S all_prod() { return t[1]; }
};