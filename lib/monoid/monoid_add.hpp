#pragma once
#include "lib/internal.hpp"
#include "monoid_trait.hpp"

namespace mono {

template <typename T>
struct MonoidAdd : MonoidTrait<T, ftf<std::plus<T>, const T, const T>>
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
  static constexpr S pw(const S &x, u64 y)
  {
    return S{x.first * y, x.second * y};
  }
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

} // namespace mono