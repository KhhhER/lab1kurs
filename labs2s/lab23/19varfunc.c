#include <stdio.h>
#include <malloc.h>

#include "treestr.c"

int max(int a, int b){
    if(a >= b){
        return a;
    }
    return b;
}

int treelvl(btree *p){
  int l = 0;
  int r = 0;
  if(p != NULL){
    if(p -> left != NULL){
      l = treelvl(p -> left);
    }else{
      l = p -> level;
    }
    if(p -> right != NULL){
      r = treelvl(p -> right);
    }else{
      r = p -> level;
    }
  }
  return max(l, r);
}

  
int slevel(btree *p, int i){
  int k = 0;
  if(p != NULL){
    if(p -> level < i){
      k = slevel(p -> left, i) + slevel(p -> right, i);
    } else {
      k = 1;
    }
  }
  return k;
}
 
int trwidth(btree *p, int lvl){
  int i = 0;
  int a = 0;
  int k = 0;
  for (i = 1; i <= lvl; i++){
    k = slevel(p, i);
    a = max(a, k);
  }
  return a;
}
