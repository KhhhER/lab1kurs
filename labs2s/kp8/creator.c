#include "stdio.h"
#include "struct.h"

void create(list* a)
{
  a -> head = (element *)malloc(syzeof(element));
  a -> head -> next = a -> head -> prev = a -> head;
  a -> size = 0;
}

element insert(list* a, enum shark b)
{
  element result = (element *)malloc(sizeof(element));
  if (!result)
    {
      return a -> head;
    }
  result -> t = b;
  result -> next = a -> head;
  result -> prev = a -> head -> prev;
  result -> prev -> next = result;
  a -> head -> prev = result;
  a -> size++;
  return result;
}

void delete(list* a, enum shark b)
{
  element res = a -> head -> next;
  int i;
  for (i = 0; i < a -> size; i++)
    {
      if (res -> t != b)
	{
	  res = res -> next;
	} else
	{
	  res -> next -> prev = res -> prev;
	  res -> prev -> next = res -> next;
	  a -> size -= 1;
	  free(res);
	}
    }
}

void sharkToString(enum shark value) {
    switch (value)
    {
    case BABY_SHARK:
        printf("BABY_SHARK\n");
        break;
    case MOMMY_SHARK:
        printf("MOMMY_SHARK\n");
        break;
    case DADDY_SHARK:
        printf("DADDY_SHARK\n");
        break;
    case GRANDMA_SHARK:
        printf("GRANDMA_SHARK\n");
        break;
    case GRANDPA_SHARK:
        printf("GRANDPA_SHARK\n");
        break;
    default:
        break;
    }
}

void list_print(list *l)
{
  int i;
  element res = l -> head -> next;
  for (i = 0; i < l -> size; i++)
    {
      sharkToString(res -> t);
      res = res -> next;
    }
} 
	  
void var5func(list *l)
{
  if (l -> size > 3)
    {
      enum shark a;
      element b = l -> head;
      a = b -> next -> next -> t;
      b -> next -> next -> t = b -> prev -> prev -> t;
      b -> prev -> prev -> t = a;
    }
}
