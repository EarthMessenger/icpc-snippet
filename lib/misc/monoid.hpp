#pragma once
#include "lib/internal.hpp"
#include <functional>

namespace mono {

// Transfer functor into function to avoid errors under c++20.
template <typename Functor, class... Args> auto ftf(const Args &&...args)
{
  static Functor f;
  return f(std::forward<const Args>(args)...);
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
constexpr T dpwf(T &&x, u64 y)
{
  T r = U();
  for (; y; y /= 2) {
    if (y & 1) r = O(std::forward<const T>(r), std::forward<const T>(x));
    x = O(std::forward<const T>(x), std::forward<const T>(x));
  }
  return r;
}
// const integer function
template <i64 V> constexpr i64 cintf() { return V; }

#if __cplusplus >= 202000U

template <typename T, auto O = std::multiplies(), auto E = dunf<T>,
          auto P = dpwf<T, O, E>, auto I = nullptr, bool C = false>

#else

template <typename T,
          T (*O)(const T &&, const T &&) = ftf<std::multiplies<T>, T, T>,
          const T (*E)() = dunf<T>, T (*P)(T &&, u64) = dpwf<T, O, E>,
          T (*I)(const T &&) = nullptr, bool C = false>
#endif
struct GroupTrait
{
  using S = T;
  static constexpr S op(const S &x, const S &y)
  {
    return O(std::forward<const S>(x), std::forward<const S>(y));
  }
  static constexpr const S un() { return E(); }
  static constexpr S iv(const S &x) { return I(std::forward<const S>(x)); }
  static constexpr S pw(S x, u64 y) { return P(std::forward<S>(x), y); }
  static constexpr bool cm = C;
};

template <typename T> struct MonoidAdd : GroupTrait<T, ftf<std::plus<T>, T, T>>
{};

template <typename T1, typename T2> struct MonoidAdd<std::pair<T1, T2>>
{
  using S = std::pair<T1, T2>;
  static constexpr S op(const S &x, const S &y)
  {
    return S{x.first + y.first, x.second + y.second};
  }
  static constexpr const S un() { return S{T1(), T2()}; }
  static constexpr S iv(const S &x) { return S{-x.first, -x.second}; }
  static constexpr S pw(S &&x, u64 y) { return S{x.first * y, x.second * y}; }
  static constexpr bool cm = false;
};

template <typename T, auto None = cintf<-1ll>> struct MonoidAssign
{
  using S = T;
  static constexpr S s_none = S(None);
  static constexpr S op(const S &x, const S &y) { return y == s_none ? x : y; }
  static constexpr const S un() { return s_none; }
  static constexpr bool cm = false;
};
// default act funcion (similar to std::invoke)
template <typename A, typename B> B dactf(const A &&a, const B &&b, u64 len)
{
  return a(std::forward<const B>(b), len);
}

#if __cplusplus >= 202000U
template <typename _GS, typename _GA, auto _AP = dactf<_GA, _GS>>
#else
template <typename _GS, typename _GA,
          _GS (*_AP)(const _GS &, const _GA &, u64) = dactf<_GA, _GS>>
#endif
struct ActedGroupTrait
{
  using GS = _GS;
  using GA = _GA;
  using S = typename GS::S;
  using A = typename GA::A;
  static constexpr S act(const A &a, const S &s, u64 len)
  {
    return _AP(std::forward<const A>(a), std::forward<const S>(s), len);
  }
};

} // namespace mono