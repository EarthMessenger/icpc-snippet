#pragma once
#include "lib/internal.hpp"

template <typename S, typename T> struct Splay
{
  struct node_t
  {
    bool reversed;
    u32 size;

    S prod;
    S m;
    T tag;

    using pnode_t = node_t *;
    pnode_t fa;
    pnode_t ch[2];

    node_t()
        : reversed(false), size(0), prod(), m(), tag(), fa(nullptr),
          ch{nullptr, nullptr}
    {
    }
    node_t(S m)
        : reversed(false), size(1), prod(m), m(m), tag(), fa(nullptr),
          ch{nullptr, nullptr}
    {
    }

    void update()
    {
      size = 1;
      prod = m;
      for (auto c : ch) {
        if (!c) continue;
        size += c->size;
        prod = prod * c->prod;
      }
    }

    void reverse()
    {
      reversed = !reversed;
      std::swap(ch[0], ch[1]);
    }

    void apply(const T &t)
    {
      prod = t(prod, size);
      m = t(m, 1);
      tag = tag * t;
    }

    void push()
    {
      for (auto c : ch) {
        if (!c) continue;
        if (reversed) c->reverse();
        if (!tag.is_unit()) c->apply(tag);
      }
      reversed = false;
      tag = T();
    }

    u32 which_child() const { return this->fa->ch[1] == this; }

    void rotate()
    {
      auto x = this;

      auto y = x->fa;
      auto z = y->fa;
      auto xci = x->which_child();
      y->ch[xci] = x->ch[xci ^ 1];
      if (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa = y;
      x->ch[xci ^ 1] = y;
      if (z) z->ch[y->which_child()] = x;
      y->fa = x;
      x->fa = z;

      y->update();
      x->update();
    }
  };

  using pnode_t = node_t *;
  pnode_t root;

  Splay() : root(nullptr) {}
  Splay(pnode_t root) : root(root) {}
  template <typename F> Splay(u32 n, F &&f) : root(build_tree(0, n, f, nullptr))
  {
  }

  template <typename F>
  static pnode_t build_tree(u32 l, u32 r, F &&f, pnode_t fa)
  {
    if (r - l == 0) return nullptr;
    u32 mid = l + (r - l) / 2;
    auto p = new node_t(f(mid));
    p->ch[0] = build_tree(l, mid, f, p);
    p->ch[1] = build_tree(mid + 1, r, f, p);
    p->fa = fa;
    p->update();
    return p;
  }

  void splay(pnode_t x)
  {
    x->push();
    while (x->fa) {
      auto y = x->fa;
      if (!y->fa) {
        y->push();
        x->push();
        x->rotate();
      } else {
        auto z = y->fa;
        z->push();
        y->push();
        x->push();
        if (y->which_child() == x->which_child()) y->rotate();
        else x->rotate();
        x->rotate();
      }
    }
    root = x;
  };

  void splay_kth(u32 k)
  {
    auto p = root;
    while (true) {
      auto ls = p->ch[0] ? p->ch[0]->size : 0;
      if (k == ls) break;
      p->push();
      if (k < ls) {
        p = p->ch[0];
      } else {
        k -= ls + 1;
        p = p->ch[1];
      }
    }
    splay(p);
  }

  std::pair<pnode_t, pnode_t> split(u32 k)
  {
    if (!root) return {nullptr, nullptr};
    if (k == 0) return {nullptr, root};
    if (k == root->size) return {root, nullptr};
    splay_kth(k);
    auto l = root->ch[0];
    root->ch[0] = nullptr;
    root->update();
    if (l) l->fa = nullptr;
    return {l, root};
  }

  std::tuple<pnode_t, pnode_t, pnode_t> split3(u32 l, u32 r)
  {
    pnode_t mp, rp;
    std::tie(root, rp) = split(r);
    std::tie(root, mp) = split(l);
    return {root, mp, rp};
  }

  static pnode_t join(pnode_t p, pnode_t q)
  {
    if (!p) return q;
    if (!q) return p;
    Splay sq = q;
    sq.splay_kth(0);
    q = sq.root;
    q->ch[0] = p;
    p->fa = q;
    q->update();
    return q;
  }

  static pnode_t join3(pnode_t p1, pnode_t p2, pnode_t p3)
  {
    return join(p1, join(p2, p3));
  }

  void insert(u32 x, S m)
  {
    auto [lp, rp] = split(x);
    root = join3(lp, new node_t(m), rp);
  }

  void remove(u32 x)
  {
    auto [lp, xp, rp] = split3(x, x + 1);
    delete xp;
    root = join(lp, rp);
  }

  void reverse(u32 l, u32 r)
  {
    auto [lp, mp, rp] = split3(l, r);
    if (mp) mp->reverse();
    root = join3(lp, mp, rp);
  }

  void apply(u32 l, u32 r, T m)
  {
    auto [lp, mp, rp] = split3(l, r);
    if (mp) mp->apply(m);
    root = join3(lp, mp, rp);
  }

  S prod(u32 l, u32 r)
  {
    auto [lp, mp, rp] = split3(l, r);
    S res;
    if (mp) res = mp->prod;
    root = join3(lp, mp, rp);
    return res;
  }
};
