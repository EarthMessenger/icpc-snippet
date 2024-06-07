#pragma once
#include <tuple>

// 给定 $a$ 和 $b$，返回三元组 $(d, x, y)$ 使得 $d = \gcd(a, b)$，$ax + by = d$
std::tuple<int, int, int> ex_euclid(int a, int b)
{
  if (b == 0) return {a, 1, 0};
  auto [d, x, y] = ex_euclid(b, a % b);
  return {d, y, x - (a / b) * y};
}

// https://robinyqc.cn/blogs/blogrepo/exgcd%20%E9%9D%9E%E9%80%92%E5%BD%92
std::tuple<int, int, int> iterative_ex_euclid(int a, int b)
{
  int x = 1, y = 0, n = 0, m = 1, t;
  while (b) {
    t = n, n = x - a / b * n, x = t;
    t = m, m = y - a / b * m, y = t;
    t = b, b = a % b, a = t;
  }
  return {a, x, y};
}