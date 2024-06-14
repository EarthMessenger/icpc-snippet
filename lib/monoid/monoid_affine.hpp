#pragma once
#include "lib/internal.hpp"
#include "lib/monoid/monoid_trait.hpp"

namespace mono {

#if __cplusplus >= 202000U
template <typename T, auto None = cintf<-1ll>> struct MonoidAssign
#else
template <typename T, T (*None)() = cintf<-1ll>> struct MonoidAssign
#endif
{
  using S = T;
  static constexpr S s_none = S(None());
  static constexpr S op(const S &x, const S &y) { return y == s_none ? x : y; }
  static constexpr const S un() { return s_none; }
  static constexpr bool cm = false;
};

} // namespace mono