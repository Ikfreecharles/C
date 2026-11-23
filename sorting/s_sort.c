#include <stdio.h>

#define N 10
void selectionsort(int a[], int length);
void sort(int a[], int length);
int main(void)
{
  int length = N;
  int a[N];
  printf("Enter %d numbers to be sorted: ", N);
  for (int i = 0; i < N; i++)
  {
    scanf("%d", &a[i]);
  };
  
  printf("Sorted: ");
  selectionsort(a, length);
  for (int i = 0; i < N; i++)
  {
    printf("%d ", a[i]);
  };
  printf("\n");
  return 0;
}

void selectionsort(int a[], int length) {
  while (length > 0) {
    sort(a, length);
    length--;
  };
}

void sort (int a[], int length) {
  int largest = a[0];
  int index_of_largest;
  int last_el = a[length - 1];

  for (int i = 0; i < length; i++) {
    if (a[i] >= largest){
      largest = a[i];
      index_of_largest = i;
    }
  };
  a[index_of_largest] = last_el;
  a[length - 1] = largest;
}