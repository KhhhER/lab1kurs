#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <struct.h>

int Comp(const Key k1, const Key k2)
{
  if (strcmp(k1->a, k2->a) == 0)
  return k1->_b <= k2->_b;
  return strcmp(k1->a, k2->a) <= 0;
}

void Swap_Rows(Row *rows, const int a, const int _b)
{
  Row tmp;
  tmp = rows[a];
  rows[a] = rows[_b];
  rows[_b] = tmp;
}

int Rand(const int a, const int _b)
{
  return a + rand() % (_b - a + 1);
}

void Printing_Table(const Row *rows, const int size)
{
  int i;
  printf("+---------+ +\n");
  printf("| Ключ | Значение |\n");
  printf("+---------+ +\n");
  for (i = 0; i < size; i++)
  printf("|%4d %4c| %60s\t\t\t\b|\n", rows[i].key.a, rows[i].key._b, rows[i].val);
  printf("+---------+ +\n");
}

int Binery_Search(const Row *rows, const int size, const Key key)
{
  int start = 0, end = size - 1, mid;
  if (size <= 0) return -1;
  while (start < end)
    {
      mid = start + (end - start) / 2;
      if (Comp(rows[mid].key, key) == 0) return mid;
      else if (Comp(rows[mid].key, key) < 1) start = mid + 1;
      else
      end = mid;
    }
  if (Comp(rows[end].key, key) == 0) return end;
  return -1;
}

void Heap_Building(Row *rows, int n, int k)
{
  int child;
  Key new;
  char newest[81];
  new = rows[k].key;
  strcpy(newest, rows[k].val);
  while (k<=n/2)
    {
      child = 2*k;
      if ((child < n) && (Comp(rows[child].key, rows[child+1].key) > 0))
      {
        child++;
      }
      if (Comp(new, rows[child].key) <= 0)
      {
        break;
      }
      else
      {
        rows[k].key = rows[child].key;
	strcpy(rows[k].val, rows[child].val);
	k = child;
      }
      rows[k].key = new;
      strcpy(rows[k].val, newest);
    }
}

void Final(Row *rows, int size)
{
  int count = size;
  int s = 1;
  Row fin[size];
  while (count > 0)
    {
      Row _b[count - 1];
      fin[s - 1] = rows[0];
      for (int i = 1; i < count; i++)
        {
          _b[i - 1] = rows[i];
        }
    count--;
    for (int i = (count/2 - 1); i >= 0; i--)
      {
        Heap_Building(_b, count - 1, i);
      }
    for (int i = 0; i < count; i++)
      {
        rows[i] = _b[i];
      }
      s++;
    }
  for (int i = 0; i < size; i++)
  {
    rows[i] = fin[i];
  }
}

void Sort(Row *rows, int size)
{
  Key chan;
  char chchan[81];
  for (int i = size/2; i >= 0; i--)
    {
      Heap_Building(rows, size - 1, i);
    }
  Final(rows, size);
}

void Rev(Row *rows, const int size)
{
  int i, j;
  for (i = 0, j = size - 1; i < j; i++, j--) Swap_Rows(rows, i, j);
}

void Get_Row(FILE *stream, char *str, const int size)
{
  int cnt = 0, ch;
  while ((ch = getc(stream)) != '\n' && cnt < size - 1) str[cnt++] = ch;
  str[cnt] = '\0';
}

void Shacking(Row *rows, const int size)
{
  int i, j, z;
  srand((unsigned int)time(0));
  for (z = 0; z < size; z++)
    {
      i = Rand(0, size - 1); j = Rand(0, size - 1);
      Swap_Rows(rows, i, j);
    }
}

int If_sort(const Row *rows, const int size)
{
  int i;
  for (i = 0; i < size - 1; i++)
    if (Comp(rows[i].key, rows[i + 1].key) > 0) return 0;
  return 1;
}
