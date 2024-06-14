#define PROBLEM "https://judge.yosupo.jp/problem/longest_common_substring"

#include <array>

#include "lib/internal.hpp"
#include "lib/str/sa.hpp"

int main()
{
  std::string s, t;
  std::cin >> s >> t;

  auto st = s + "|" + t;
  auto [sa, rk] = suffix_array(st);
  auto h = calc_height(st, sa, rk);

  int n = st.size(), m = s.size();

  int len = 0;
  std::array<int, 4> ans{0, 0, m + 1, m + 1};
  for (int i = 0; i < n - 1; i++) {
    int p = sa[i], q = sa[i + 1];
    if (p > q) std::swap(p, q);
    if (p < m && q > m) {
      if (len < h[i]) {
        len = h[i];
        ans = {p, p + len, q, q + len};
      }
    }
  }

  std::cout << ans[0] << " " << ans[1] << " " << ans[2] - m - 1 << " "
            << ans[3] - m - 1 << std::endl;
}
