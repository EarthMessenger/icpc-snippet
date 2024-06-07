#define PROBLEM "https://judge.yosupo.jp/problem/subset_convolution"

#include "lib/math/convolution.hpp"
#include "lib/math/static_modint.hpp"

signed main() 
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    using mint = static_modint<998244353>;
    auto read_int = [x = int()]() mutable { cin >> x; return x; };
    u32 n = read_int(), q = 1 << n;
    vec<vec<mint>> a(n + 1, vec<mint>(q)), b(a), c(a);
    for (u32 i = 0; i < q; i++) a[__builtin_popcount(i)][i] = read_int();
    for (u32 i = 0; i < q; i++) b[__builtin_popcount(i)][i] = read_int();
    for (auto &i: a) poly::bit::sosdp<0>(n, i);
    for (auto &i: b) poly::bit::sosdp<0>(n, i);
    for (u32 i = 0; i <= n; i++) {
        for (u32 j = 0; j <= i; j++) {
            for (u32 k = 0; k < q; k++) {
                c[i][k] += a[j][k] * b[i - j][k];
            }
        }
    }
    for (auto &i: c) poly::bit::sosdp<1>(n, i);
    for (u32 i = 0; i < q; i++) {
        cout << c[__builtin_popcount(i)][i].val() << ' ';
    }
    return 0;
}