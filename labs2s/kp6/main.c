#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "filefunc.h"
#include "varfunc.c"


void input(student *student)
{
  printf("Base data");
  printf("\n");
  printf("Surnname: ");
  scanf("%s", student -> name);
  printf("\n");
  printf("Initials: ");
  scanf("%s", student -> initials);
  printf("\n");
  printf("Group: ");
  scanf("%s", student -> group);
  printf("\n");
  printf("Sex: ");
  char try;
  scanf("%s", &try);
  if(try == 'F'){
      student -> SEX = SEX_F;
  } else {
      student -> SEX = SEX_M;
  }
  printf("Marks");
  printf("\n");
  printf("Disk: ");
  scanf("%d", &student -> m.disk);
  printf("\n");
  printf("Hist: ");
  scanf("%d", &student -> m.hist);
  printf("\n");
  printf("Mat: ");
  scanf("%d", &student -> m.mat);
  printf("\n");
  printf("IT: ");
  scanf("%d", &student -> m.it);
  printf("\n");
  printf("Offsets");
  printf("\n");
  printf("LIN: ");
  scanf("%s", &try);
  if(try == 'Y'){
      student -> of.OFF_SET_LIN = YES_LIN;
  } else {
      student -> of.OFF_SET_LIN = NO_LIN;
  }
  printf("\n");
  printf("PHY: ");
  scanf("%s", &try);
  if(try == 'Y'){
      student -> of.OFF_SET_PHY = YES_PHY;
  } else {
      student -> of.OFF_SET_PHY = NO_PHY;
  }
  printf("\n");
  printf("ENG: ");
  scanf("%s", &try);
  if(try == 'Y'){
      student -> of.OFF_SET_ENG = YES_ENG;
  } else {
      student -> of.OFF_SET_ENG = NO_ENG;
  }
  printf("\n");
  printf("LAB: ");
  scanf("%s", &try);
  if(try == 'Y'){
      student -> of.OFF_SET_LAB = YES_LAB;
  } else {
      student -> of.OFF_SET_LAB = NO_LAB;
  }
}
int main()
{
  student *st;
  int choice = 0;
  while (choice != 4)
  {
    printf("Choose your option\n");
    printf("1) Add\n");
    printf("2) Print data\n");
    printf("3) Function\n");
    printf("4) Exit\n");
    scanf("%d", &choice);
    if (choice == 1) {
      printf("\n");
      input(st);
      insert(st);
    }
    if (choice == 2) {
      printf("\n");
      printHead();
      load();
    }
    if(choice = 3) {
      check("base.db");
    }
  }
  return 0;
}
