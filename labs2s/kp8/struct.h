#ifndef _LIST_H_
#define _LIST_H_

enum shark
  {
    BABY_SHARK,
    MOMMY_SHARK,
    DADDY_SHARK,
    GRANDMA_SHARK,
    GRANDPA_SHARK
  };

typedef struct element
{
  enum shark t;
  struct element *next;
  struct element *prev;
} element;

typedef struct list
{
  element*  head;
  int size;
} list;

#endif
