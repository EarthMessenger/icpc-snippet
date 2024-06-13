/**
 * @brief Bit Manipulation
 */
#pragma once
#include "lib/internal.hpp"

int clz(u64 x) { return __builtin_clzll(x); }
int ctz(u64 x) { return __builtin_ctzll(x); }
// floor(log2(x))
int lg2(u64 x) { return 63 ^ clz(x); }
// bit width
int btw(u64 x) { return lg2(x) + 1; }
// bit ceil
u64 btc(u64 x) { return (x <= 1 ? 1 : 1ull << btw(x - 1)); }
// bit floor
u64 btf(u64 x) { return 1ull << lg2(x); }
// popcount
__attribute__((target("popcnt"))) int ppc(u64 x)
{
  return __builtin_popcountll(x);
}