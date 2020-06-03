#include <stdio.h>
#include <stdlib.h>

#include "data.h"
#include "vector.c"

int menu(void)
{
    printf("%s\n", "1. Enter");
    printf("%s\n", "2. Output");
    printf("%s\n", "3. Multiply");
    printf("%s\n", "4. Exit");
    int ans;
    scanf("%d", &ans);
    return ans;
}

int main()
{
    struct cell *matrixa = NULL;
    struct cell *matrixb = NULL;
    int k = 0;
    while (k != 4)
    {
        k = menu();
        switch (k)
        {
        case 1: 
        {
            getchar();
            matrixa = enter(matrixa);
        }
        break;
        case 2: 
        {
            getchar();
            output(matrixa);
        }
        break;
        case 3: 
        {
	  if (matrixa == NULL)
	    {
	      printf("Enter your first matrix\n");
	      getchar();
              matrixa = enter(matrixa);
	    }
	  printf("Enter your second matrix\n");
	  getchar();
          matrixb = enter(matrixb);
	  mult(matrixa, matrixb);
        }
        break;
        default:
            printf("Can't understand!\n");
            break;
        case 4:
            break;
        }
    }
    return 0;
}
