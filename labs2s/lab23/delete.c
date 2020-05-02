#include <stdio.h>
#include <malloc.h>

#include "treestr.c"

void elimination(btree *tmp)
{
    free(tmp);
    printf("Tree has been deleted\n");
    tmp = NULL;
}


void delete (btree *tmp, btree *tmp2, int curVa)
{
    if (tmp == NULL) {
        printf("No tree yet!\n");
        return;
    } else {
        if (curVa > (*tmp).value && (*tmp).right) {
            delete ((*tmp).right, tmp, curVa);
            return;
        }
        if (curVa < (*tmp).value && (*tmp).left) {
            delete ((*tmp).left, tmp, curVa);
            return;
        }
        if (curVa > (*tmp).value && !(*tmp).right) {
            printf("ERROR!\n");
            return;
        }
        if (curVa < (*tmp).value && !(*tmp).left) {
            printf("ERROR!\n");
            return;
        }
        if (curVa == (*tmp).value) {
            if ((*tmp).left && (*tmp).right) {
                btree *oldTmp, *oldTmp2;
                if (tmp->left->right) {
                    oldTmp = (*tmp).left;
                    while ((*oldTmp).right) {
                        oldTmp2 = oldTmp;
                        oldTmp = (*oldTmp).right;
                    }
                    (*tmp).value = (*oldTmp).value;
                    delete (oldTmp, oldTmp2, (*oldTmp).value);
                    return;
                }
                if (tmp->right->left) {
                    oldTmp = (*tmp).right;
                    while ((*oldTmp).left) {
                        oldTmp2 = oldTmp;
                        oldTmp = (*oldTmp).left;
                    }
                    (*tmp).value = (*oldTmp).value;
                    delete (oldTmp, oldTmp2, (*oldTmp).value);
                    return;
                }
            }
            if ((*tmp).right || (*tmp).left) {
                if (tmp->left) {
                    tmp->value = tmp->left->value;
                    if (!tmp->left->right && !tmp->left->left) {
                        free(tmp->left);
                        tmp->left = NULL;
                        return;
                    }
                    delete (tmp->left, tmp, tmp->left->value);
                    return;
                }
                if (tmp->right) {
                    tmp->value = tmp->right->value;
                    if (!tmp->right->right && !tmp->right->left) {
                        free(tmp->right);
                        tmp->right = NULL;
                        return;
                    }
                    delete (tmp->right, tmp, tmp->right->value);
                    return;
                }
            }
            if (tmp->value > tmp2->value) {
                tmp2->right = NULL;
            }
            else {
                tmp2->left = NULL;
            }
            free(tmp);
	    printf("DELETED\n");
            return;
        }
    }
}
