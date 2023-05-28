struct dynamic_modint
{
	using mint = dynamic_modint;

	static unsigned int P;

	unsigned int _v;

	dynamic_modint() : _v(0) {}

	dynamic_modint(long long v)
	{
		long long x = v % mod();
		if (x < 0) x += mod();
		_v = x;
	}

	unsigned int val() const { return _v; }
	static unsigned int mod() { return P; }
	static void set_mod(int x) { P = x; }

	mint operator-() const { return mint(-_v); }
	mint &operator+=(const mint &a)
	{
		_v += a._v;
		if (_v >= mod()) _v -= mod();
		return *this;
	}
	mint &operator-=(const mint &a)
	{
		_v += mod() - a._v;
		if (_v >= mod()) _v -= mod();
		return *this;
	}
	mint &operator*=(const mint &a)
	{
		_v = (long long)_v * a._v % mod();
		return *this;
	}
	mint operator+(const mint &a) const { return mint(*this) += a; }
	mint operator-(const mint &a) const { return mint(*this) -= a; }
	mint operator*(const mint &a) const { return mint(*this) *= a; }

	mint pow(long long n) const
	{
		mint x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}

	mint inv() const { return pow(mod() - 2); }

	mint &operator/=(const mint &a) { return *this *= a.inv(); }
	mint operator/(const mint &a) const { return mint(*this) /= a; }
};
unsigned int dynamic_modint::P = 998244353;
