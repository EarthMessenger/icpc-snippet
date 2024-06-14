#include "lib/ds/segtree.hpp"
#include "lib/monoid/monoid_add.hpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"


signed main()
{
    using namespace std;
    ios::sync_with_stdio(false); cin.tie(0), cout.tie(0);
    u32 n, q;
    cin >> n >> q;
    vec<i64> a(n);
    for (auto &i: a) cin >> i;
    SegmentTree<mono::MonoidAdd<i64>> s(n, [&a](u32 i){return a[i];});
    long long op, x, y;
    while (q--) {
        cin >> op >> x >> y;
        if (op == 0) s.set(x, a[x] += y);
        else cout << s.prod(x, y) << '\n';
    }
}