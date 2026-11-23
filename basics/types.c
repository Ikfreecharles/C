#include <stdio.h>

// d, u, o, x are the conversion specifications for int
// add h, and l for short and long respectively e.g %hu %lu &hd %ld

// e, f, g, are the conversion specifications for floating point numbers
// add l  and L for double and long double respectively e.g. %lf LF
int main (void) {
  #define LONG_LONG_INT 15ll
  #define UNSIGNED_LONG_LONG_INT 39llu
  
  int i = 2147483647;
  unsigned short j = 65000;
  unsigned long k = 5000000000000;

  short l=32500, m=32500;
  long double n = 546.90;

  printf("The size of i is %zu\n", sizeof i);
  printf("The size of j  is %zu\n", sizeof j);
  printf("The size of k is %zu\n", sizeof k);

  printf("The size of long long is %zu\n", sizeof LONG_LONG_INT);
  printf("The size of unsigned long long is %zu\n", sizeof UNSIGNED_LONG_LONG_INT);
  printf("Sum of l and m is %d. Size is %zu\n", l+m, sizeof (l + m));
  printf("The size of long double is %zu\n", sizeof n);
  return 0;
}