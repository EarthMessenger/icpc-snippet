#define PROBLEM "https://judge.yosupo.jp/problem/suffixarray"

#include "lib/internal.hpp"
#include "lib/str/sa.hpp"

int main()
{
  std::string s;
  std::cin >> s;

  auto [sa, rk] = suffix_array(s);

  for (auto i : sa) std::cout << i << " ";
  std::cout << std::endl;
}
