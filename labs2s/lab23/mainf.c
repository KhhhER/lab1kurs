#include <stdio.h>
#include <malloc.h>
#include <time.h>

#include "treestr.c"
#include "part1.c"
#include "19varfunc.c"
#include "delete.c"

int main()
{
    printf("Choose the command and print the number\n");
    printf("1. Add node\n");
    printf("2. Delete node\n");
    printf("3. Print tree\n");
    printf("4. Width check\n");
    printf("5. Random filling\n");
    printf("6. Exit\n");
    btree *tree = NULL;
    int k = 0;

    while (k != 6)
    {
        int ans;
        scanf("%d", &ans);
        k = ans;
        switch (k)
        {
        case 1: {
            char value;
            getchar();
            printf("Print value ");
            scanf("%c", &value);
            int val = value;
            if (!tree) {
                tree = create(val);
                printf("Created\n");
            } else {
                add(tree, val, 1);
                printf("Added\n");
            }
            printf("\n");
        }
        break;
        case 2:
        {
            char value;
            getchar();
            printf("Print value ");
            scanf("%c", &value);
            int val = value;
            if (tree) {
                if (!tree -> left && !tree -> right && val == tree -> value) {
                    elimination(tree);
                }
                else {
                    if (!tree -> left && !tree -> right && val != tree -> value) {
                        printf("NO SUCH VALUE!\n");
                    } else {
                        delete(tree, tree, val);
                    }
                }
                delete(tree, tree, val);
            }
            else {
                printf("Tree is empty\n");
            }
        }
        break;
        case 3: {
            getchar();
            print(tree);
        }
        break;
        case 4: {
            if(tree != NULL){
	      int a = treelvl(tree);
	      printf("%d\n", trwidth(tree, a));
            } else {
                printf("Tree is empty!\n");
            }
            
            
        }
        break;
        case 5: {
            srand(time(NULL));
            if (!tree)
            {
                tree = create((rand() % 95 + 32));
            }
            for (int i = 0; i < 10; i++)
            {
                add(tree, (rand() % 95 + 32), 1);
            }
            printf("Just filled the tree\n");
        }
        break;
        case 6:
            break;
        default:
            printf("No input!\n");
            break;
        }
    }
}
