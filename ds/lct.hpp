template <typename T>
struct LinkCutTree
{
  struct Splay
  {
    using ptr = Splay *;

    u32 size;
    bool reversed;
    T val, prod;
    ptr fa, ch[2];

    Splay() : size(0), reversed(false), val(), prod(), fa(nullptr), ch{nullptr, nullptr} {}
    Splay(const T &val) : size(1), reversed(false), val(val), prod(val), fa(nullptr), ch{nullptr, nullptr} {}

    void update()
    {
      size = 1;
      prod = val;
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

    void set(const T &v)
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

    u32 which_child() const
    {
      assert(fa != nullptr);
      return fa->ch[1] == this;
    }

    bool is_root() const
    {
      return fa == nullptr || (fa->ch[0] != this && fa->ch[1] != this);
    }

    void rotate()
    {
      auto x = this;
      assert(!is_root());

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

  template <typename F>
    LinkCutTree(int n, F &&f) : ptrs(n)
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
    assert(xp->fa == yp);
    yp->ch[0] = xp->fa = nullptr;
  }

  T prod(int x, int y)
  {
    auto xp = ptrs[x], yp = ptrs[y];
    xp->make_root();
    yp->access();
    return yp->prod;
  }

  void set(int x, const T &v)
  {
    auto xp = ptrs[x];
    xp->splay();
    xp->set(v);
  }

  void multiply(int x, const T &v)
  {
    auto xp = ptrs[x];
    xp->splay();
    xp->set(xp->val * v);
  }

  T get(int x)
  {
    return ptrs[x]->val;
  }
};
