#pragma once
#include "lib/internal.hpp"
#include <array>

template<typename S, typename F, int id = 0>
class DynamicSegmentTree
{
public:
    const S e;
    const F op;

    struct Node
    {
        S val;
        u32 ls, rs;
        Node(S v): val(v), ls(), rs() { }
    };

    u32 n, root;
    static vec<Node> t;

    DynamicSegmentTree(u32 _n, const S &_e, const F &_op): n(_n), e(_e), op(_op) { }

    void update(u32 x) { t[x].val = op(t[t[x].ls].val, t[t[x].rs].val); }

    static u32 new_node() 
    {
        t.emplace_back(e);
        return t.size() - 1u;
    }

    void set(u32 x, const S &v)
    {
        if (x == 0) x = new_node();
    }

private:

    void set_rec(const S &v, u32 l, u32 r, u32 x)
    {
        if (x == 0) x = new_node();
    }
};