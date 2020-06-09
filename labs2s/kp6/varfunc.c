#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "struct.h"
#include "filefunc.h"

void stips(char RAW_NAME[])
{
    int counter = 0;
    int number = 0;
    FILE *file;
    file = fopen(RAW_NAME, "r");
    student *p;
    if (file == NULL) {
        printf("Error!!!");
    } else {
        while (!feof(file))
        {
            p = malloc(sizeof(p));
            fread(&p, sizeof(p), 1, file);
            if((p -> m.disk != 2) && (p -> m.mat != 2) && (p -> m.hist != 2) && (p -> m.it != 2)) {
                if(p -> m.disk == 3){
		  counter++;
		  number -= 4;
		} else if(p -> m.disk == 4){ number++; }
                if(p -> m.mat == 3){
		  counter++;
		  number -= 4;
		} else if(p -> m.mat == 4){ number++; }
                if(p -> m.hist == 3){
		  counter++;
		  number -= 4;
		} else if(p -> m.hist == 4){ number++; }
                if(p -> m.it == 3){
		  counter++;
		  number -= 4;
		} else if(p -> m.it == 4){ number++; }                
            }
            if(counter == 1) {
	      printf("Студент ");
	      for (int i = 1; i <= 15; i++)
		{
		  printf("%s", p -> name[i]);
		}
	      printf(" претендует на базовую стипендию\n");
            } else
	    if(number == 1) {
	      printf("Студент ");
	      for (int i = 1; i <= 15; i++)
		{
		  printf("%s", p -> name[i]);
		}
	      printf(" претендует на повышенную стипендию\n");
            }
	    nubmer = 0;
	    counter = 0;
        }
    }
    fclose(file);
}
