#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "symbol.h"
#include "stack.h"
#include "tree.h"
#include "19varfunc.h"

void unt(TN *root)
{
  root = root -> r;
}

void un(TN *root)
{
   if ((root -> l -> t.data.op == OP_UNARY_MINUS) && (root -> r -> t.data.op == OP_UNARY_MINUS))
	{
	  unt(root -> l);
	  unt(root -> r);
	}
      else if (root -> l -> t.data.op == OP_UNARY_MINUS)
	{
	  TN *a = (TN *)malloc(sizeof(TN));
	  unt(root -> l);
	  a = root;
	  root -> t.data.op = OP_UNARY_MINUS;
	  free(root -> l);
	  root -> l = NULL;
	  root -> r = a;
	  free(a);
	}
      else if (root -> r -> t.data.op == OP_UNARY_MINUS)
	{
	  TN *a = (TN *)malloc(sizeof(TN));
	  unt(root -> r);
	  a = root;
	  root -> t.data.op = OP_UNARY_MINUS;
	  free(root -> l);
	  root -> l = NULL;
	  root -> r = a;
	  free(a);
	}
}

void unmult(TN *root)
{
  if (root -> t.data.op == OP_MULT)
    {
      unmult(root -> l);
      unmult(root -> r);
      un(root);
    }
}

void udivide(TN *root)
{
  if (root -> l != NULL)
    {
      undivide(root -> l);
    }
  if (root -> r != NULL)
    {
      undivide(root -> r);
    }
  if (root -> t.data.op == OP_DIVIDE)
    {
      unmult(root -> l);
      unmult(root -> r);
      un(root);
    }
}
      
      
