#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"

#include "func.h"

int *concatenation(int *stack1, int count1, int *stack2, int count2)
{
    stack1 = (int *)realloc(stack1, sizeof(stack1)+count2*sizeof(int));
    int j = 0;
    while (j <= count2)
    {
        stack1[count1 + j] = stack2[j];
        j++;
    }
    return stack1;
}

void output(int *stack, int count)
{
    for (int i = 0; i < count; i++)
        printf("%d\n", stack[i]);
}

int *push(int add, int *stack, int count)
{
    if (!stack[count])
        stack = (int *)realloc(stack, count * sizeof(int));
    stack[count] = add;
    return stack;
}

int *pop(int *stack, int count)
{
    stack[count] = 0;
    return stack;
}

void sort(int *stack, int first, int count)
{
    int *stnew;
    int i = first;
    int j = count;
    int o;
    int x = stack[(first + j) / 2];
    do
    {
        while (stack[i] < x)
            i++;
        while (stack[j] > x)
            j--;
        if (i <= j)
        {
            if (stack[i] > stack[j])
                change(stack, i, j);
            i++;
            j--;
        }
    } while (i <= j);

    if (i < count)
        sort(stack, i, count);
    if (first < j)
        sort(stack, first, j);
}

void change(int *stack, int i, int j)
{
    int c = stack[i];
    stack[i] = stack[j];
    stack[j] = c;
}
