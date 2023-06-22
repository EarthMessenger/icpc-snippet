template <int P> struct static_modint
{
	using mint = static_modint;
	unsigned int _v;

	static_modint() : _v(0) {}

	static_modint(long long v)
	{
		long long x = v % mod();
		if (x < 0) x += mod();
		_v = x;
	}

	unsigned int val() const { return _v; }
	static constexpr unsigned int mod() { return P; }

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
