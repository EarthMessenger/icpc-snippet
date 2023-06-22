constexpr int P = 2;

int binom(int n, int m);

int lucas(long long n, long long m) {
	if (m == 0) return 1;
	return (long long)binom(n % P, m % P) * lucas(n / P, m / P) % P;
}
