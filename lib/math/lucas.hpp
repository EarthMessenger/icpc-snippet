/**
 * @brief Lucas Theorem
 * @todo exLucas
 */
#pragma once
#include "lib/internal.hpp"

template <typename T, typename M> M lucas(long long n, long long m, T binom)
{
  if (m == 0) return M::raw(1);
  return binom(n % P, m % P) * lucas(n / P, m / P);
}
