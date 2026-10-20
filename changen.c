#include <stdio.h>

#define N 10

int main (void) {
  int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, *p = a, *q = a +N-1, temp;

  while (p < q)
  {
    printf("Before incrementing p: %d\n", *p);
    temp = *p;
    printf("temp: %d\n", temp);
    *p++ = *q; //1. assign to *p first. 2. Then increment p -> *p = *q; p++;
    printf("After incrementing p: %d\n", *p);
    *q-- = temp; //1. assign to +q first. 2. Then decrement q -> *q = temp; q--;
  }
   for (int i = 0; i < N; i++)
    printf("%d ", a[i]);
   printf("\n");
 
   return 0;
}