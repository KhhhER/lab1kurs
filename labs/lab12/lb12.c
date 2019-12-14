#include <stdio.h>

long absd(long c)
{
  return (c > 0) ? c : -c;
}

long func(long a)
{
   a /= 10;
  if ((a > 9) | (a < -9)){
      long b = 1;
      while (b <= absd(a)) {
	  b *=10;
	}
      b /= 10;
      a %= b;
    } else {
    a = 0;
  }
  return a;
}

int main()
{
  long a;
  while(scanf("%ld", &a) != EOF){
    printf("%ld\n", func(a));
  }
  return 0;
}

