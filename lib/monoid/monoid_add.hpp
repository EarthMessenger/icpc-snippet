#pragma once
#include "lib/internal.hpp"
#include "lib/monoid/monoid_trait.hpp"

namespace mono {

template <typename T>
struct MonoidAdd : MonoidTrait<T, true, ftf<std::plus<T>, const T, const T>>
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
  static constexpr bool cm = true;
};

} // namespace mono