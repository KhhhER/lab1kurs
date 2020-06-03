#include <stdio.h>
#include "data.h"


struct cell *enter(struct cell *tmp)
{
    int index;
    float value;
    while (1)
    {
        printf("Enter index and value: ");
        scanf("%d", &index);
        if (index != -1)
        {
            scanf("%f", &value);
            if (!tmp)
            {
                create(tmp);
                tmp->last = NULL;
                tmp->next = NULL;
                tmp->index = index;
                tmp->value = value;
            }
            else
            {
                create(tmp->next);
                tmp->next->last = tmp;
                tmp->next->next = NULL;
                tmp->next->index = index;
                tmp->next->value = value;
                tmp = tmp->next;
            }
        }
        else
        {
            break;
        }
    }
    while (tmp && tmp->last)
    {
        tmp = tmp->last;
    }
    return tmp;
}


float *conversion(cell *tmp)
{
    int width = 0;
    int height = 0;
    while (tmp)
    {
        if (tmp->index / 10 > height)
        {
            height = tmp->index / 10;
        }
        if (tmp->index % 10 > width)
        {
            width = tmp->index % 10;
        }
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    float *matrix = (float *)realloc(NULL, height * width * sizeof(float));
    for (int i = 0; i < height * width; i++)
    {
        matrix[i] = 0;
    }
    while (tmp)
    {
        matrix[((tmp->index / 10)-1) * width + (tmp->index % 10) - 1] = tmp->value;
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    
    for (int i = 0; i < height * width; i++)
    {
        if(i%width == 0){
            printf("\n");
        }
        printf("%3.3f ",matrix[i]);
        
    }
    
    printf("\n");
return matrix;
}

void output(struct cell *tmp)
{
    while (tmp->last)
    {
        tmp = tmp->last;
    }
    printf("\nIndex -> value\n");
    while (tmp)
    {
        printf("%5d -> %5f\n", tmp->index, tmp->value);
        if (tmp->next)
        {
            tmp = tmp->next;
        }
        else
        {
            break;
        }
    }
    while (tmp->last)
    {
        tmp = tmp->last;
    }
}

void *mult(cell *a, cell *b)
{
  int awidth = 0;
  int bheight = 0;
  int bwidth = 0;
  int aheight = 0;
  while (a)
    {
        if (a->index / 10 > aheight)
        {
            aheight = a->index / 10;
        }
        if (a->index % 10 > awidth)
        {
            awidth = a->index % 10;
        }
        if (a->next)
        {
            a = a->next;
        }
        else
        {
            break;
        }
    }
  while (a->last)
    {
      a = a->last;
    }
  while (b)
    {
        if (b->index / 10 > bheight)
        {
            bheight = b->index / 10;
        }
        if (b->index % 10 > bwidth)
        {
            bwidth = b->index % 10;
        }
        if (b->next)
        {
            b = b->next;
        }
        else
        {
            break;
        }
    }
  while (b->last)
    {
      b = b->last;
    }
  if (awidth == bheight)
    {
      int i, k;
      int ai = 0;
      float *mata = conversion(a);
      float *matb = conversion(b);
      float *matrix = (float *)realloc(NULL, aheight * bwidth * sizeof(float));
      for (i = 1; i = (aheight * bwidth); i++)
	{
	  matrix[i] = 0;
	}
      for (i = 1; i = (aheight * bwidth); i++)
	{
	  for (k = 1; k = awidth; k++)
	    {
	      matrix[i] = matrix[i] + (mata[ai + k] * matb[(i % bwidth) + (bwith * (k - 1))]);
	      printf("%5f  ", matrix[i]);
	    }
	  ai += awidth;
	  printf("\n");
	}
    } else
    {
      printf("Didn't multiplied\n");
    }
}
	      
