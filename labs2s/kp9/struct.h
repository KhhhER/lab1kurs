#ifndef _struct_h_
#define _struct_h_

typedef struct _Key
{
  int a;
  char _b[5];
} Key;

typedef struct _Row
{
  Key key;
  char val[81];
} Row;

#endif 
