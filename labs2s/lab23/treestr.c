#include <stdio.h>

#define btree struct btree

typedef btree
{
    btree *left;
    btree *right;
    int level;
    int value; 
} this_btree;

btree *create(int val)
{
    btree *root = (btree *)malloc(sizeof(btree));
    root -> left = NULL;
    root -> right = NULL;
    root -> value = val;
    return root;
}
