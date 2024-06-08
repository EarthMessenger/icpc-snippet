#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "lib/math/convolution.hpp"
#include "lib/math/static_modint.hpp"

signed main() 
{
    using namespace std;
    ios::sync_with_stdio(false); 
    cin.tie(0), cout.tie(0);
    u32 n;
    cin >> n;
    using mint = static_modint<998244353>;
    vec<mint> a(1 << n), b(1 << n);
    auto read_int = [x = int()]() mutable { return cin >> x, x; };
    for (auto &i: a) i = read_int();
    for (auto &i: b) i = read_int();
    poly::bit::compliment(n, a);
    poly::bit::compliment(n, b);
    poly::bit::sosdp<0>(n, a);
    poly::bit::sosdp<0>(n, b);
    for (u32 i = 0; i < (1u << n); i++) a[i] *= b[i];
    poly::bit::sosdp<1>(n, a);
    poly::bit::compliment(n, a);
    for (auto i: a) cout << i.val() << ' ';
    return 0;
}