#include <string>
#include <vector>

std::vector<int> prefix_function(std::string s)
{
	const int n = s.size();
	std::vector<int> p(n);
	for (int i = 1; i < n; i++) {
		int j = p[i - 1];
		while (j > 0 && s[i] != s[j]) j = p[j - 1];
		if (s[i] == s[j]) j++;
		p[i] = j;
	}
	return p;
}
