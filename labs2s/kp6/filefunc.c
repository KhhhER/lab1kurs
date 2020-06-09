#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

 
#include "struct.h"
#include "filefunc.h"

int space = 16;
char RAW_NAME[] = "base.db";
char stringFormatter[] = "%-*s";
char intFormatter[] = "%-*d";
char sizeTFormatter[] = "%-*d";

void printRecord(student * r){ 
    
	printf(intFormatter, space, " ");	
	printf(stringFormatter, space, r -> name);
	printf(stringFormatter, space, r -> initials);
	printf(stringFormatter, space, r -> group);
	char s;
	s  = (r -> SEX == SEX_F) ? 'F':'M';
	printf(stringFormatter, space, s);
	printf(intFormatter, space, r -> m.disk);
	printf(stringFormatter, space, r -> m.hist);
	printf(stringFormatter, space, r -> m.mat);
	printf(stringFormatter, space, r -> m.it);
	s  = (r -> of.OFF_SET_LIN == YES_LIN) ? 'Y' : 'N';
	printf(stringFormatter, space, s);
	s  = (r -> of.OFF_SET_PHY == YES_PHY) ? 'Y' : 'N';
	printf(stringFormatter, space, s);
	s  = (r -> of.OFF_SET_ENG == YES_ENG) ? 'Y' : 'N';
	printf(stringFormatter, space, s);
	s  = (r -> of.OFF_SET_LAB == YES_LAB) ? 'Y' : 'N';
	printf(stringFormatter, space, s);
	printf("\n\n");
}
void printHead(){
	printf(stringFormatter, space, "PRIMARY_KEY");
	printf(stringFormatter, space, "NAME");
	printf(stringFormatter, space, "INITIALS");
	printf(stringFormatter, space, "GROUP");
	printf(stringFormatter, space, "SEX");
	printf(stringFormatter, space, "DISK");
	printf(stringFormatter, space, "HISTORY");
	printf(stringFormatter, space, "MATAN");
	printf(stringFormatter, space, "IT");
	printf(stringFormatter, space, "LIN");
	printf(stringFormatter, space, "PHY");
	printf(stringFormatter, space, "ENG");
	printf(stringFormatter, space, "LAB");
	printf("\n\n");
}

void randomString(char * str, int size){
	for (int i = 0; i < size; ++i){
		str[i] = 'A' + rand() % ('z' - 'A');
	}
}

student randomData(){
	student r;
    srand ( time(NULL) );
	char tmp[20];
	randomString(tmp, 7);
	strcpy(r.name, tmp);
	randomString(tmp, 15);
	strcpy(r.group, tmp);
	randomString(tmp, 2);
	strcpy(r.initials, tmp);
	if(rand() % 2 == 0){
		r.SEX = SEX_M;
	} else {
		r.SEX = SEX_F;
	}
	r.m.disk = rand() % 6;
	r.m.it = rand() % 6;
	r.m.hist = rand() % 6;
	r.m.mat = rand() % 6;
	if(rand() % 2 == 0){
		r.of.OFF_SET_ENG = NO_ENG;
	} else {
		r.of.OFF_SET_ENG = YES_ENG;
	}
	if(rand() % 2 == 0){
		r.of.OFF_SET_LAB = NO_LAB;
	} else {
		r.of.OFF_SET_LAB = YES_LAB;
	}
	if(rand() % 2 == 0){
		r.of.OFF_SET_LIN = NO_LIN;
	} else {
		r.of.OFF_SET_LIN = YES_LIN;
	}
	if(rand() % 2 == 0){
		r.of.OFF_SET_PHY = NO_PHY;
	} else {
		r.of.OFF_SET_PHY = YES_PHY;
	}
	return r;
}

void next() {
    FILE *file;
    file = fopen(RAW_NAME, "r");
    if(file) {
        fseek(file, sizeof(student), SEEK_CUR);
    }
    fclose(file);  
}
void prev() {
    FILE *file;
    file = fopen(RAW_NAME, "r");
    if(file) {
        fseek(file, -sizeof(student), SEEK_CUR);
    }
    fclose(file);
}
void start() {
    FILE *file;
    file = fopen(RAW_NAME, "r");
    if(file){
        fseek(file, 0, SEEK_SET);
    }
    fclose(file);
}
void end() {
    FILE *file;
    file = fopen(RAW_NAME, "r");
    if(file){
        fseek(file, 0, SEEK_END);
    }
    fclose(file);
}

void load()
{
    int counter = 0;
    FILE *file;
    file = fopen(RAW_NAME, "r");
    student *p;
    if (file == NULL) {
        printf("Error!!!");
    } else {
        while (!feof(file))
        {
            printf("!!!\n");
            p = malloc(sizeof(p));
            fread(&p, sizeof(p), 1, file);
             printRecord(p);
             printf("\n");
        }
    }
    fclose(file);
}

void insert(student *pc)
{				 
    FILE *base = fopen(RAW_NAME, "w");
    if (!base)
    {
        perror("Can't open file");
	return;
    }
	    fwrite(&pc, sizeof(pc), 1, base);
    fclose(base);
    return;
}
