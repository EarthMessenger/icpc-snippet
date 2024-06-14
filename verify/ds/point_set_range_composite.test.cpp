#include "lib/ds/segtree.hpp"
#include "lib/math/static_modint.hpp"
#include <functional>

#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

struct LinearFunc
{
    using mint = static_modint<998244353>;
    mint k, b;
    LinearFunc(mint _k = 1, mint _b = 0): k(_k), b(_b) { }
    LinearFunc operator*(const LinearFunc &t) const 
    { 
        return {k * t.k, b * t.k + t.b}; 
    }
    mint apply(mint x) { return k * x + b; }
};

signed main()
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    auto read_int = [x = int()]() mutable { return cin >> x, x; };
    u32 n = read_int(), q = read_int();
    vec<LinearFunc> a(n);
    for (auto &[k, b]: a) k = read_int(), b = read_int();
    SegmentTree<mono::MonoidTrait<LinearFunc>> s(n, [&a](u32 i){return a[i];});
    while (q--) {
        u32 op, x, y, z;
        cin >> op >> x >> y >> z;
        if (op == 0) s.set(x, {y, z});
        else cout << s.prod(x, y).apply(z).val() << '\n';
    }
}