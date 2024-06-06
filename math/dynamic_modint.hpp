struct barrett {
  u32 m;
  u64 im;

  barrett() {}
  barrett(u32 m) : m(m), im((u64)(-1) / m + 1) {}

  u32 mod() const { return m; }

  u32 reduce(u64 x) const 
  {
    u64 y = ((u128)x * im) >> 64;
    u32 z = x - y * m;
    if (z >= m) z += m;
    return z;
  }
};

template <int id>
struct dynamic_modint
{
  static barrett b;
  static u32 mod() { return b.m; }
  static void set_mod(u32 x) { b = barrett(x); }
  static u32 reduce(u64 x) { return b.reduce(x); }

  u32 v;

  dynamic_modint() = default; // as a trivial struct
  template <typename T>
    dynamic_modint(T x) : v((x % (T)mod() < 0) ? x + (T)mod() : x) {}

  using mint = dynamic_modint;

  static mint raw(u32 x)
  {
    mint res;
    res.v = x;
    return res;
  }

  u32 val() const { return v; }

  mint operator-() const { return dynamic_modint(mod() - v); }
  mint &operator+=(mint x)
  {
    if ((v += x.v) >= mod()) v -= mod();
    return *this;
  }
  mint &operator-=(mint x)
  {
    if ((v += mod() - x.v) >= mod()) v -= mod();
    return *this;
  }
  mint &operator*=(mint x)
  {
    v = reduce((u64)v * x.v);
    return *this;
  }
  friend mint operator+(mint x, mint y) { return x += y; }
  friend mint operator-(mint x, mint y) { return x -= y; }
  friend mint operator*(mint x, mint y) { return x *= y; }

  mint pow(long long y) const
  {
    mint res = 1;
    mint base = *this;
    while (y) {
      if (y & 1) res *= base;
      base *= base;
      y >>= 1;
    }
    return res;
  }

  mint inv() const { return pow(mod() - 2); }

  mint &operator/=(mint x) { return *this *= x.inv(); }
  friend mint operator/(mint x, mint y) { return x *= y.inv(); }
};

template <int id> barrett dynamic_modint<id>::b;
