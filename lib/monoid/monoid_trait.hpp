#pragma once

#include "lib/internal.hpp"

// Transfer functor into function to avoid errors under c++20.
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
  return a(std::forward<const B>(b), std::forward<u64>(len));
}

//////////////////////////////////////////////////////////////////////////

namespace mono {

#if __cplusplus >= 202000U

template <typename T, auto O = std::multiplies(), auto E = dunf<T>,
          auto P = dpwf<T, O, E>, auto I = nullptr, bool C = false>

#else

template <typename T,
          T (*O)(const T &&, const T &&) =
              ftf<std::multiplies<T>, const T, const T>,
          const T (*E)() = dunf<T>, T (*P)(const T &&, u64 &&) = dpwf<T, O, E>,
          T (*I)(const T &&) = nullptr, bool C = false>
#endif
struct MonoidTrait
{
  using S = T;
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
template <typename _MA, typename _MS, auto _AP = dactf<_MA, _MS>>
#else
template <typename _MA, typename _MS,
          typename _MS::S (*_AP)(const typename _MA::S &&,
                                 const typename _MS::S &&, u64 &&) =
              dactf<_MA, _MS>>
#endif
struct ActedMonoidTrait
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

template <typename _M, bool _cm = _M::cm> struct BidirMonoidTrait {};

template <typename _M> struct BidirMonoidTrait<_M, true>
{
  using M = _M;
  using BS = typename M::S;
  using S = BS;
  static constexpr S ts(const S &x) { return x; }
  static constexpr S op(const S &x, const S &y)
  {
    return M::op(std::forward<const S>(x), std::forward<const S>(y));
  }
  static constexpr const S un() { return M::un(); }
  static constexpr S iv(const S &x)
  {
    return M::iv(std::forward<const S>(x));
  }
  static constexpr S pw(const S &x, u64 y)
  {
    return M::pw(std::forward<const S>(x), std::forward<u64>(y));
  }
  static constexpr bool cm = true;
};

template <typename _M> struct BidirMonoidTrait<_M, false>
{
  using M = _M;
  using BS = typename M::S;
  using S = std::pair<BS, BS>;
  static constexpr S ts(const S &x) { return S(x.second, x.first); }
  static constexpr S op(const S &x, const S &y)
  {
    return S{
        M::op(std::forward<const S>(x.first), std::forward<const S>(y.first)),
        M::op(std::forward<const S>(y.second),
              std::forward<const S>(x.second))};
  }
  static constexpr const S un() { return S{M::un(), M::un()}; }
  static constexpr S iv(const S &x)
  {
    return S{M::iv(std::forward<const S>(x.first)),
             M::iv(std::forward<const S>(x.second))};
  }
  static constexpr S pw(const S &x, u64 y)
  {
    return S{M::pw(std::forward<const S>(x.first), std::forward<u64>(y)),
    M::pw(std::forward<const S>(x.first), std::forward<u64>(y))};
  }
  static constexpr bool cm = false;
};

template<typename _M, bool _cm = _M::cm> struct BidirActedMonoidTrait { };
template<typename _M> struct BidirActedMonoidTrait<_M, true> : BidirMonoidTrait<_M, true>
{
  using A = typename M::A;
  static constexpr S act(const A &a, const S &s, u64 len)
  {
    return M::act(std::forward<const A>(a), std::forward<const S>(s),
               std::forward<u64>(len));
  }

};

} // namespace mono