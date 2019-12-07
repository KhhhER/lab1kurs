#include <stdio.h>

long max(long a, long b)
{
 return (a > b) ? a : b;
}

long min(long a, long b)
{
 return (a < b) ? a : b;
}

long mod(long a, long b)
{
  long c;
  c = (a - (a / b) * b);
  return (c < 0) ? c + b : c;
}

int main()
{
  long i, l, j, ik, lk, jk, k;
  i = -22;
  j = 14;
  l = -14;
  k = 0;
  while (((i + j + 10 > 0) | (i + j + 20 < 0)) && (k < 51)) {
      k += 1;
      ik = mod(i * min(j, l) + j * min(i, l) + k * k, 20);
      jk = mod((mod(i, 10) - k) * (mod(j, 10) + k) * (mod(l, 10) - k), 25);
      lk = max(mod(min(i + j, i + l), 25), mod(max(i + l, j + k), 20)) + 10;
      i = ik;
      j = jk;
      l = lk;
    }
    (k == 51) ? printf("Missed\n") : printf("Coordinates: i = %ld, j = %ld, step number %ld, l = %ld\n", i, j, k, l);
}
