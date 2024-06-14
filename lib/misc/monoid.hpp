#pragma once
#include "lib/internal.hpp"
#include <functional>

namespace mono {

// Transfer functor into function to solve errors in c++17.
template <typename Functor, class... Args> auto ftf(const Args &&...args)
{
  static Functor f;
  return f(std::forward<const Args>(args)...);
}
// default unit function
template <typename T> constexpr const T dunf() { return T(); }
// default inverse functino
template <typename T, auto U, auto D> constexpr T divf(const T &&x)
{
  return D(std::forward<const T>(U()), std::forward<const T>(x));
}
// default power function
template <typename T, auto O, auto U> constexpr T dpwf(T &&x, u64 y)
{
  T r = U();
  for (; y; y /= 2) {
    if (y & 1) r = O(std::forward<const T>(r), std::forward<const T>(x));
    x = O(std::forward<const T>(x), std::forward<const T>(x));
  }
  return r;
}

template <typename T, auto O = ftf<std::multiplies<T>, T, T>, auto E = dunf<T>,
          auto P = dpwf<T, O, E>, auto I = nullptr, bool C = false>
struct MonoidTrait
{
  using S = T;
  static constexpr S op(const S &x, const S &y)
  {
    return O(std::forward<const S>(x), std::forward<const S>(y));
  }
  static constexpr const S un() { return E(); }
  static constexpr S iv(const S &x) { return I(std::forward<const S>(x)); }
  static constexpr S pw(S &&x, u64 y)
  {
    return P(std::forward<S>(x), y);
  }
  static constexpr bool cm = C;
};

template <typename T> using AddMonoid = MonoidTrait<T, ftf<std::plus<T>, T, T>>;

template <typename _MS, typename _MA, auto _AP> struct ActedMonoidTrait
{
  using MS = _MS;
  using MA = _MA;
  using S = typename MS::S;
  using A = typename MA::A;
  static constexpr S act(const S &s, const A &a, u64 len) 
  { 
    return _AP(std::forward<const S>(s), std::forward<const A>(a), len); 
  }
};

} // namespace mono