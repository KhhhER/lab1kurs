#ifndef FUNC_H
#define FUNC_H
#include <stdio.h>

int *stack1;
int *stack2;

void output(int *stack, int count);
int *concatenation(int *stack1, int count1, int *stack2, int count2);
int *push(int add, int *stack, int count);
int *pop(int *stack, int count);
void sort(int *stack, int first, int last);
void change(int *stack, int i, int j);

#endif
