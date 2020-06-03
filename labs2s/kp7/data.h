ifndef DATA_H
#define DATA_H
#include <malloc.h>

#define create(tmp)                       
    tmp = (cell *)malloc(sizeof(cell)); 
    if (!tmp)                           
    {                                   
        printf("Didn't created\n");      
    }

typedef struct cell
{
    int index;
    struct cell *last;
    struct cell *next;
    float value;
} cell;

cell *enter(cell *);
void output(cell *);
float *conversion(cell *);

#endif
