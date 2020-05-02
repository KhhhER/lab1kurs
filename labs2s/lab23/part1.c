#include <stdio.h>
#include <malloc.h>

#include "treestr.c"


btree *add(btree *root, int val, int counter)
{
    if(root == NULL) {
        root = (btree *)malloc(sizeof(btree));
        (*root).level = counter;
        (*root).value = val;
        (*root).left = NULL;
        (*root).right = NULL;
    } else {
        if((*root).value == val){
            printf("It already exists!\n");
            return root;
        } else {
            if( (*root).value > val ) {
                counter++;
                (*root).left = add((*root).left, val, counter);
            } else {
                counter++;
                (*root).right = add((*root).right, val, counter);
            }
        }
    }
    return root;
}

void print(btree *p)
{
    if(p != NULL) {
      if(p -> left != NULL){
          print(p -> left);
      }
      for(int i = 0; i < p-> level; ++i){
        printf("*****");
      }
      printf("%c\n", p -> value);
      if(p -> right != NULL){
          print(p -> right);
      }
    }
}
