#include <stdio.h>
#define wat printf("%d ", k.a[i][j])

struct matr
{
  int a[8][8];
  int n;
};
  
void get(int n, struct matr* k)
{
  int i, j;
  k->n = n;
  for (i = 1; i <= n; i++)
    {
      for (j = 1; j <= n; j++)
	{
	  scanf("%d", &(k->a[i][j]));
	}
    }
}

int main()
{
  int i = 1;
  int j = 1;
  int n;
  struct matr k;
  
  while (scanf("%d", &n) != EOF)
     {
      get(n, &k);
      if (n == 1)
	{
	  wat;
	} else
	{
	  int b = 0;
	  while ((j < n) && (i < n))
	     {
	       if (b == 0){
		 wat; /* 1;1 */
	       }
	       j += 1;
	       while (i <= j) /*Первый столбец*/
		 {
		   wat;
		   i += 1;
		 }
	       i -= 1;
	       j -= 1;
	       while (j >= 1) /*Первая строка*/
		 {
		   wat;
		   j -= 1;
		 }
	       if (i < n) /*Наличие строк снизу*/
		 {
		   i += 1;
		   j += 1;
		   while (j <= i) /*Вторая строка*/
		     {
		       wat;
		       j += 1;
		     }
		   i -= 1;
		   j -= 1;
		   while (i > 1) /*Второй столбец*/
		     {
		       wat;
		       i -= 1;
		     }
		   wat;
		   b = 1;
		 }
	     }
	}
      printf("\n");
      i = 1;
      j = 1;
      }
  return 0;
}
