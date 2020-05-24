#include <stdio.h>
#include <struct.h>
#include <creator.c>

enum shark chooseshark(int a)
{
  switch (a)
    {
     case 0:
        return BABY_SHARK;
        break;
     case 1:
        return MOMMY_SHARK;
        break;
     case 2:
        return DADDY_SHARK;
        break;
     case 3:
        return GRANDMA_SHARK;
        break;
     case 4:
        return GRANDPA_SHARK;
        break;
     default:
        break;
    }
}

int main()
{
  printf("Start: \n");
  printf("1. Add\n");
  printf("2. Delete\n");
  printf("3. Size\n")
  printf("4. Print\n");
  printf("5. Swap\n");
  printf("6. Finish\n");
  int point = 0;
  list *node = NULL;
  int a;
  while (point != 6)
    {
      scanf("%d", &point);
      switch (point)
	{
          case 1:
	    printf("Choose new shark:\n");
	    printf("0 - baby\n");
	    printf("1 - mommy\n");
	    printf("2 - daddy\n");
	    printf("3 - grandma\n");
	    printf("4 - grandpa\n");
	    scanf("%d", &a);
	    if(!node)
	      {
                printf("\nCreated!\n");
                create(node);
		insert(node, chooseshark(a));
                break;
              } else
	      {
                insert(node, chooseshark(a));
                printf("Added!");
              }
            break;
	  case 2:
	     printf("Choose:\n");
	     printf("0 - baby\n");
	     printf("1 - mommy\n");
	     printf("2 - daddy\n");
	     printf("3 - grandma\n");
	     printf("4 - grandpa\n");
	     scanf("%d", &a);
      	     if(!node)
	      {
                printf("Nothing!\n");
                break;
              } else
	      {
                delete(node, chooseshark(a));
                printf("Deleted!");
              }
            break;
	  case 3:
            if(node)
	      {
                printf("%d\n", node -> size);
                break;
              }
            printf("\nNo list yet!\n");
            break;
	  case 4:
	    if(node)
	      {
                list_print(node);
                break;
              }
            printf("\nNo list yet!\n");
            break;
	  case 5:
	    if(node)
	      {
                var5func(node);
                break;
              }
            printf("\nNo list yet!\n");
            break;
	  default:
            printf("\nERROR!\n");
            break;
        }
    }
    printf("Done\n");
}
