#pragma once

#include "lib/internal.hpp"

// Transfer functor into function to avoid errors under c++20 above c++11.
template <typename Functor, class... Args> auto ftf(Args &&...args)
{
  static Functor f;
  return f(std::forward<Args>(args)...);
}

// default unit function
template <typename T> constexpr const T dunf() { return T(); }

// default inverse function
template <typename T, const T (*U)() = dunf<T>,
          T (*D)(const T &&, const T &&) = ftf<std::divides<T>, T, T>>
constexpr T divf(const T &&x)
{
  return D(std::forward<const T>(U()), std::forward<const T>(x));
}

// default power function
template <typename T, T (*O)(const T &&, const T &&), const T (*U)() = dunf<T>>
constexpr T dpwf(const T &&x, u64 &&y)
{
  T r = U(), v = x;
  for (; y; y /= 2) {
    if (y & 1) r = O(std::forward<const T>(r), std::forward<const T>(v));
    v = O(std::forward<const T>(v), std::forward<const T>(v));
  }
  return r;
}

// const integer function
template <i64 V> constexpr i64 cintf() { return V; }

// default act funcion (similar to std::invoke)
template <typename A, typename B> B dactf(const A &&a, const B &&b, u64 &&len)
{
  return a * b;
}

//////////////////////////////////////////////////////////////////////////

namespace mono {

#if __cplusplus >= 202000U

template <typename _S, bool C = false, auto O = std::multiplies(),
          auto E = dunf<_S>, auto P = dpwf<_S, O, E>, auto I = divf<_S>>

#else

template <typename _S, bool C = false,
          _S (*O)(const _S &&, const _S &&) =
              ftf<std::multiplies<_S>, const _S, const _S>,
          const _S (*E)() = dunf<_S>,
          _S (*P)(const _S &&, u64 &&) = dpwf<_S, O, E>,
          _S (*I)(const _S &&) = divf<_S>>
#endif
struct GroupTrait
{
  using S = _S;
  using MS = GroupTrait;
  static constexpr S op(const S &x, const S &y)
  {
    return O(std::forward<const S>(x), std::forward<const S>(y));
  }
  static constexpr const S un() { return E(); }
  static constexpr S iv(const S &x) { return I(std::forward<const S>(x)); }
  static constexpr S pw(const S &x, u64 y)
  {
    return P(std::forward<const S>(x), std::forward<u64>(y));
  }
  static constexpr bool cm = C;
};

#if __cplusplus >= 202000U

template <typename _S, bool C = false, auto O = std::multiplies(),
          auto E = dunf<_S>, auto P = dpwf<_S, O, E>>

#else

template <typename _S, bool C = false,
          _S (*O)(const _S &&, const _S &&) =
              ftf<std::multiplies<_S>, const _S, const _S>,
          const _S (*E)() = dunf<_S>,
          _S (*P)(const _S &&, u64 &&) = dpwf<_S, O, E>>
#endif
struct MonoidTrait: GroupTrait<_S, C, O, E, P, nullptr>
{
  using S = _S;
  using MS = MonoidTrait;
};

#if __cplusplus >= 202000U
template <typename _MA, typename _MS,
          auto _AP = dactf<typename _MA::S, typename _MS::S>>
#else
template <typename _MA, typename _MS,
          typename _MS::S (*_AP)(const typename _MA::S &&,
                                 const typename _MS::S &&, u64 &&) =
              dactf<typename _MA::S, typename _MS::S>>
#endif
struct ActedMonoidTrait : _MS
{
  using MA = _MA;
  using MS = _MS;
  using A = typename MA::S;
  using S = typename MS::S;
  static constexpr S act(const A &a, const S &s, u64 len)
  {
    return _AP(std::forward<const A>(a), std::forward<const S>(s),
               std::forward<u64>(len));
  }
};

template <typename _M, bool _cm = _M::cm> struct BidirMonoidTrait
{};

template <typename _M> struct BidirMonoidTrait<_M, true>
{
  using MS = typename _M::MS;
  using BS = typename MS::S;
  using S = BS;
  static constexpr S ts(const S &x) { return x; }
  static constexpr S op(const S &x, const S &y) { return MS::op(x, y); }
  static constexpr const S un() { return MS::un(); }
  static constexpr S iv(const S &x) { return MS::iv(x); }
  static constexpr S pw(const S &x, u64 y) { return MS::pw(x, y); }
  static constexpr bool cm = true;
};

template <typename _M> struct BidirMonoidTrait<_M, false>
{
  using MS = typename _M::MS;
  using BS = typename MS::S;
  using S = std::pair<BS, BS>;
  static constexpr S ts(const S &x) { return S(x.second, x.first); }
  static constexpr S op(const S &x, const S &y)
  {
    return S{MS::op(x.first, y.first), MS::op(y.second, x.second)};
  }
  static constexpr const S un() { return S{MS::un(), MS::un()}; }
  static constexpr S iv(const S &x)
  {
    return S{MS::iv(x.first), MS::iv(x.second)};
  }
  static constexpr S pw(const S &x, u64 y)
  {
    return S{MS::pw(x.first, y), MS::pw(x.second, y)};
  }
  static constexpr bool cm = false;
};

template <typename _M, bool _cm = _M::cm> struct BidirActedMonoidTrait
{};
template <typename _M>
struct BidirActedMonoidTrait<_M, true> : BidirMonoidTrait<_M, true>
{
  using MA = typename _M::MA;
  using A = typename MA::S;
  using MS = typename BidirMonoidTrait<_M, true>::MS;
  using BS = typename BidirMonoidTrait<_M, true>::BS;
  using S = typename BidirMonoidTrait<_M, true>::S;
  static constexpr S act(const A &a, const S &s, u64 len)
  {
    return _M::act(a, s, len);
  }
};
template <typename _M>
struct BidirActedMonoidTrait<_M, false> : BidirMonoidTrait<_M, false>
{
  using MA = typename _M::MA;
  using A = typename MA::S;
  using MS = typename BidirMonoidTrait<_M, false>::MS;
  using BS = typename BidirMonoidTrait<_M, false>::BS;
  using S = typename BidirMonoidTrait<_M, false>::S;
  static constexpr S act(const A &a, const S &s, u64 len)
  {
    return S{_M::act(a, s.first, len), _M::act(a, s.second, len)};
  }
};

} // namespace mono