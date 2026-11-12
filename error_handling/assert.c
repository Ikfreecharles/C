#include <stdio.h>
#include <stdlib.h>
#include "../strings/print.h"
#include <assert.h> // adding a -DNDEBUG flag when compiling deactivates all asserts

#define N 10

int main()
{
  char a[N] = {0};
  size_t i = 11;
  printf("Before insertion: ");
  print_line(a, N);
  assert(i >= 0 && i < N); // if i is not within range, abort program and exit
  a[i] = 'k';
  printf("After insertion: ");
  print_line(a, N);
  return 0;
}