#define PROBLEM "https://judge.yosupo.jp/problem/number_of_substrings"

#include "lib/internal.hpp"
#include "lib/str/sa.hpp"

int main()
{
  std::string s;
  std::cin >> s;

  auto [sa, rk] = suffix_array(s);
  auto h = calc_height(s, sa, rk);

  i64 ans = s.size() * (s.size() + 1) / 2;
  for (auto i : h) ans -= i;

  std::cout << ans << std::endl;
}
