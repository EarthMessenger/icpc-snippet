int lowbit(int x);

int next_hamming(int x)
{
  int t = x + lowbit(x);
  return t | ((lowbit(t) / lowbit(x) / 2) - 1);
}
