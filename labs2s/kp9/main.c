#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <struct.h>
#include <func.c>

int main()
{
  const int N = 50;
  int i, cnt, action;
  char ch;
  Row data[N];
  Key key;
  FILE *file = fopen("input.txt", "r");
  if (file == NULL)
    {
      printf("Can't open file\n");
      return 0;
    }
  i = 0;
  while (i < N && fscanf(file, "%d %c", &data[i].key.a, &data[i].key.b) == 2)
    {
      fscanf(file, "%c", &ch);
      Get_Row(file, data[i].val, sizeof(data[i].val));
      i++;
    }
  fclose(file);
  cnt = i;
do
{
  printf("1.Print 2.Binary search 3.Sort 4.Shake 5.Rev 6.Exit\n");
  scanf("%d", &action);
  switch (action)
    {
      case 1:
        {
          Printing_Table(data, cnt);
          break;
        }
      case 2:
        {
          if (!If_sort(data, cnt))
          printf("Error. Table isn't sorted\n");
	  else
            {
              printf("Enter key: ");
              scanf("%d %c", &key.a, &key.b);
	      i = Binery_Search(data, cnt, key);
              if (i > -1)
              printf("Found string: %s\n", data[i].val);
	      else
              printf("String with this key doesn't exist\n");
             }
          break;
        }
      case 3:
        {
          Sort(data, cnt);
          break;
        }
      case 4:
        {
          Shacking(data, cnt);
          break;
        }
      case 5:
        {
          Rev(data, cnt);
          break;
        }
      case 6: break;
      default:
        {
          printf("Error\n");
	  break;
        }
      }
    }
  while (action != 6);
  return 0;
}
