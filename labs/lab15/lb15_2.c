#include <stdio.h>

void getmat(int n, int *a)
{
  int i;
  for (i = 1; i <= n * n; i++)
    {
      scanf("%d", &a[i]);
    }
}
int main()
{
  int n, i, c, b, j, max, k;
  int a[100];
  while(scanf("%d", &n) != EOF)
    {
      getmat(n, a);
      c = n;
      k = n - 1;
      b = 1;
      for (i = 1; i <= n; i++)
	{
	  max = a[b];
	  for (j = b; j < b + n; j++)
	    {
	      if (max < a[j])
		{
		  max = a[j];
		}
	    }
	  a[c - k] = max;
	  for (j = b; j < b + n; j++)
	    {
	      printf("%d ", a[j]);
	    }
	  k -= 1;
	  c += n;
	  b += n;
	  printf("\n");
	}
      printf("\n");
    }
  return 0;
}
