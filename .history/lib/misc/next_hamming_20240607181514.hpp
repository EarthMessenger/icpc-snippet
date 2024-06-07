#pragma once
int next_hamming(int x)
{
  int t = x + (x & -x);
  return t | (((t & -t) / (x & -x) / 2) - 1);
}