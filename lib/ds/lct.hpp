#pragma once
#include "lib/internal.hpp"
#include "lib/monoid/monoid_trait.hpp"

/**
 * @brief Link Cut Tree
 *
 * @tparam BM Bidir Monoid
 */
template <typename BM> struct LinkCutTree
{
  using S = typename BM::S;
  struct Splay
  {
    using ptr = Splay *;

    u32 size;
    bool reversed;
    S val, prod;
    ptr fa, ch[2];

    Splay()
        : size(0), reversed(false), val(BM::un()), prod(BM::un()), fa(nullptr),
          ch{nullptr, nullptr}
    {
    }
    Splay(const S &_val)
        : size(1), reversed(false), val(_val), prod(val), fa(nullptr),
          ch{nullptr, nullptr}
    {
    }

    void update()
    {
      size = 1;
      prod = val;
      for (auto c : ch) {
        if (!c) continue;
        size += c->size;
        prod = BM::op(prod, c->prod);
      }
    }

    void reverse()
    {
      reversed = !reversed;
      std::swap(ch[0], ch[1]);
      prod = BM::ts(prod);
    }

    void set(const S &v)
    {
      val = v;
      update();
    }

    void push()
    {
      for (auto c : ch) {
        if (!c) continue;
        if (reversed) c->reverse();
      }
      reversed = false;
    }

    u32 which_child() const { return fa->ch[1] == this; }

    bool is_root() const
    {
      return fa == nullptr || (fa->ch[0] != this && fa->ch[1] != this);
    }

    void rotate()
    {
      auto x = this;

      auto y = x->fa;
      auto z = y->fa;
      auto xci = which_child();
      y->ch[xci] = x->ch[xci ^ 1];
      if (x->ch[xci ^ 1]) x->ch[xci ^ 1]->fa = y;
      x->ch[xci ^ 1] = y;
      if (!y->is_root()) z->ch[y->which_child()] = x;
      y->fa = x;
      x->fa = z;

      y->update();
      x->update();
    }

    void splay()
    {
      push();
      while (!is_root()) {
        auto y = fa;
        if (y->is_root()) {
          y->push();
          push();
          rotate();
        } else {
          auto z = y->fa;
          z->push();
          y->push();
          push();
          if (y->which_child() == which_child()) y->rotate();
          else rotate();
          rotate();
        }
      }
    }

    ptr access()
    {
      ptr rp = nullptr;
      ptr cur = this;
      while (cur) {
        cur->splay();
        cur->ch[1] = rp;
        cur->update();
        rp = cur;
        cur = cur->fa;
      }
      splay();
      return rp;
    }

    void make_root()
    {
      access();
      reverse();
    }
  };

  using ptr = typename Splay::ptr;

  std::vector<ptr> ptrs;

  template <typename F> LinkCutTree(int n, F &&f) : ptrs(n)
  {
    for (int i = 0; i < n; i++) ptrs[i] = new Splay(f(i));
  }

  void link(int x, int y)
  {
    auto xp = ptrs[x], yp = ptrs[y];
    xp->make_root();
    xp->fa = yp;
  }

  void cut(int x, int y)
  {
    auto xp = ptrs[x], yp = ptrs[y];
    xp->make_root();
    yp->access();
    yp->ch[0] = xp->fa = nullptr;
  }

  S prod(int x, int y)
  {
    auto xp = ptrs[x], yp = ptrs[y];
    xp->make_root();
    yp->access();
    return yp->prod;
  }

  void set(int x, const S &v)
  {
    auto xp = ptrs[x];
    xp->splay();
    xp->set(v);
  }

  void multiply(int x, const S &v)
  {
    auto xp = ptrs[x];
    xp->splay();
    xp->set(BM::op(xp->val, v));
  }

  S get(int x) { return ptrs[x]->val; }
};
