std::vector<int> prefix_function(const std::string &s)
{
  int n = s.size();
  std::vector<int> p(n + 1);
  p[0] = p[1] = 0;
  for (int i = 1; i < n; i++) {
    int t = p[i];
    while (t > 0 && s[t] != s[i]) t = p[t];
    if (s[t] == s[i]) t++;
    p[i + 1] = t;
  }
  return p;
}
