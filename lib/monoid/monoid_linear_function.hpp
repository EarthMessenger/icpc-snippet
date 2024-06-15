#pragma once
#include "lib/internal.hpp"

namespace mono {

template <typename T> struct MonoidLinearFunc
{
  using S = std::pair<T, T>;
  static constexpr S op(const S &x, const S &y)
  {
    return S{x.first * y.first, x.second * y.first + y.second};
  }
  static constexpr const S un() { return S{1, 0}; }
  static constexpr S iv(const S &x)
  {
    return S{T(1) / x.first, -x.second / x.first};
  }
  static constexpr S pw(const S &x, u64 y)
  {
    return dpwf<S, op, un>(std::forward<const S>(x), std::forward<u64>(y));
  }
  static constexpr bool cm = false;
};

} // namespace mono