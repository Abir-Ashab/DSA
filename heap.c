#include <stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)//ith index er data ke tar right position e rakhe
{
    int largest = i;
    int l = 2 * i ;
    int r = 2 * i + 1;
    if (l <= size && array[l] > array[largest])
      largest = l;
    if (r <= size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
}
void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size ++;
  }
  else
  {
    array[size] = newNum;
    size ++;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size --;
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}

int main()
{
  int array[100];

  insert(array, 22);
  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 2);
  insert(array, 20);
  insert(array, 21);
  insert(array, 62);
  insert(array, 50);

  printf("Max-Heap array: ");
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");


  
  printf("After deleting an element: ");
  deleteRoot(array, 4);
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}