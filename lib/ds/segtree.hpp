#pragma once
#include "lib/internal.hpp"
#include "lib/misc/bitop.hpp"
#include "lib/monoid/monoid_trait.hpp"
/**
 * @brief Segment Tree
 *
 * @tparam M Monoid
 */
template <typename M> struct SegmentTree
{
  using S = typename M::S;

  u32 m;
  vec<S> t;

  SegmentTree() {}
  SegmentTree(u32 n): m(btc(n)), t(m * 2, M::un()) { ; }
  template <typename I>
  SegmentTree(u32 n, const I &f): m(btc(n)), t(m * 2, M::un())
  {
    for (u32 i = 0; i < n; i++) t[i + m] = f(i);
    for (u32 i = m - 1; ~i; i--) t[i] = M::op(t[i * 2], t[i * 2 + 1]);
  }

  void set(u32 p, const S &v)
  {
    t[p += m] = v;
    for (p /= 2; p; p /= 2) t[p] = M::op(t[p * 2], t[p * 2 + 1]);
  }

  S get(u32 p) { return t[p + m]; }
  S prod(u32 l, u32 r)
  {
    S lans = M::un(), rans = M::un();
    for (l += m, r += m; l < r; l /= 2, r /= 2) {
      if (l & 1) lans = M::op(lans, t[l++]);
      if (r & 1) rans = M::op(t[--r], rans);
    }
    return M::op(lans, rans);
  }
  S all_prod() { return t[1]; }
};