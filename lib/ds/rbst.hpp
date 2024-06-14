#pragma once
#include "lib/internal.hpp"

/**
 * @brief Random Binary Search Tree
 *
 * @tparam BAM bidirected_acted_monoid
 */
template <typename BAM> struct RBST
{
  using S = typename BAM::S;
  using A = typename BAM::A;
  struct node_t
  {
    bool reverse;
    A tag;
    u32 size;
    S prod;
    S m;
    node_t *lc, *rc;

    node_t()
        : reverse(false), tag(BAM::MA::un()), size(0), prod(BAM::un()),
          m(BAM::un()), lc(nullptr), rc(nullptr)
    {
    }
    node_t(S _m)
        : reverse(false), tag(BAM::MA::un()), size(1), prod(_m), m(_m),
          lc(nullptr), rc(nullptr)
    {
    }

    void update()
    {
      size = 1;
      prod = m;
      if (lc) {
        size = size + lc->size;
        prod = BAM::op(prod, lc->prod);
      }
      if (rc) {
        size = size + rc->size;
        prod = BAM::op(prod, rc->prod);
      }
    }

    void toggle_reverse()
    {
      reverse = !reverse;
      std::swap(lc, rc);
      prod = BAM::ts(prod);
    }

    void apply(const A &t)
    {
      prod = BAM::act(t, prod, size);
      m = BAM::act(t, m, 1);
      tag = BAM::MA::op(tag, t);
    }

    void push()
    {
      if (reverse) {
        if (lc) lc->toggle_reverse();
        if (rc) rc->toggle_reverse();
        reverse = false;
      }
      if (tag != BAM::MA::un()) {
        if (lc) lc->apply(tag);
        if (rc) rc->apply(tag);
        tag = BAM::MA::un();
      }
    }
  };

  node_t *root;

  // 可用 std::mt19937 之類代替
  static u32 get_random()
  {
    static u32 x = 123456789;
    static u32 y = 362436069;
    static u32 z = 521288629;
    static u32 w = 88675123;
    u32 t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
  };

  static bool choice(u32 ls, u32 rs) { return get_random() % (ls + rs) < ls; }

  RBST() : root(nullptr) {}
  template <typename F> RBST(u32 n, F &&f) : root(build_tree(0, n, f)) {}

  template <typename F> static node_t *build_tree(u32 l, u32 r, F &&f)
  {
    if (r - l == 0) return nullptr;
    u32 mid = l + (r - l) / 2;
    auto p = new node_t(f(mid));
    p->lc = build_tree(l, mid, f);
    p->rc = build_tree(mid + 1, r, f);
    p->update();
    return p;
  }

  static std::pair<node_t *, node_t *> split(u32 k, node_t *p)
  {
    if (p == nullptr) return {nullptr, nullptr};

    p->push();
    u32 ls = p->lc ? p->lc->size : 0;
    if (ls < k) {
      node_t *r;
      std::tie(p->rc, r) = split(k - ls - 1, p->rc);
      p->update();
      return {p, r};
    } else {
      node_t *l;
      std::tie(l, p->lc) = split(k, p->lc);
      p->update();
      return {l, p};
    }
  }

  static node_t *join(node_t *p, node_t *q)
  {
    if (p == nullptr) return q;
    if (q == nullptr) return p;

    if (choice(p->size, q->size)) {
      p->push();
      p->rc = join(p->rc, q);
      p->update();
      return p;
    } else {
      q->push();
      q->lc = join(p, q->lc);
      q->update();
      return q;
    }
  }

  static node_t *join3(node_t *p1, node_t *p2, node_t *p3)
  {
    return join(p1, join(p2, p3));
  }

  void insert(u32 i, S m)
  {
    auto [lp, rp] = split(i, root);
    root = join3(lp, new node_t(m), rp);
  }

  void remove(u32 i)
  {
    auto [lp, irp] = split(i, root);
    auto [ip, rp] = split(1, irp);
    root = join(lp, rp);
  }

  void reverse(u32 l, u32 r)
  {
    auto [lp, mrp] = split(l, root);
    auto [mp, rp] = split(r - l, mrp);
    if (mp) mp->toggle_reverse();
    root = join3(lp, mp, rp);
  }

  void apply(u32 l, u32 r, const A &m)
  {
    auto [lp, mrp] = split(l, root);
    auto [mp, rp] = split(r - l, mrp);
    if (mp) mp->apply(m);
    root = join3(lp, mp, rp);
  }

  static S prod(u32 l, u32 r, u32 ll, u32 rr, node_t *p)
  {
    if (p == nullptr) return {};

    if (l <= ll && rr <= r) {
      return p->prod;
    } else {
      p->push();

      u32 mid = ll + (p->lc ? p->lc->size : 0);
      S res = BAM::un();
      if (l < mid) res = BAM::op(res, prod(l, r, ll, mid, p->lc));
      if (l <= mid && mid < r) res = BAM::op(res, p->m);
      if (mid + 1 < r) res = BAM::op(res, prod(l, r, mid + 1, rr, p->rc));
      return res;
    }
  }

  S prod(u32 l, u32 r) const
  {
    if (root == nullptr) return BAM::un();
    return prod(l, r, 0, root->size, root);
  }
};
