#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "func.h"

int main()
{
    int first = 0;
    int count1 = 0;
    int count2 = 0;
    int *stack1, *stack2;
    stack1 = (int *)malloc(sizeof(int));
    stack2 = (int *)malloc(sizeof(int));
    int k = 0;
    printf("1. Push stack 1\n");
    printf("2. Push stack 2\n");
    printf("3. Pop stack 1\n");
    printf("4. Pop stack 2\n");
    printf("5. Text output stack 1\n");
    printf("6. Text output stack 2\n");
    printf("7. Sort stack 1\n");
    printf("8. Sort stack 2\n");
    printf("9. Concatenation\n");
    printf("10. Exit\n");
    while (k != 10)
    {
        scanf("%d", k);
        switch (k)
        {
        case 1:
        {
            getchar();
            int add;
            scanf("%d", &add);
            *stack1 = *push(add, stack1, count1);
            printf("\n");
            count1++;
        }
        break;
        case 2:
        {
            getchar();
            int add;
            scanf("%d", &add);
            *stack2 = *push(add, stack2, count2);
            printf("\n");
            count2++;
        }
        break;
        case 3:
        {
            getchar();
            pop(stack1, count1);
            printf("\n");
            count1--;
        }
        break;
        case 4:
        {
            getchar();
            pop(stack1, count2);
            printf("\n");
            count2--;
        }
        break;
        case 5:
        {
            getchar();
            output(stack1, count1);
            printf("\n");
        }
        break;
        case 6:
        {
            getchar();
            output(stack2, count2);
            printf("\n");
        }
        break;
        case 7:
        {
            getchar();
            count1--;
            sort(stack1, first, count1);
            count1++;
            printf("\n");
        }
        break;
        case 8:
        {
            getchar();
            count2--;
            sort(stack2, first, count2);
            count2++;
        }
        break;
        case 9:
        {
            getchar();
            stack1 = concatenation(stack1, count1, stack2, count2);
            count1 = count1 + count2;
            count2 = 0;
            free(stack2);
            printf("\n");
        }
        case 10:
            break;
        default:
            printf("Didn't understand\n");
            break;
        }
    }
    return 0;
}
