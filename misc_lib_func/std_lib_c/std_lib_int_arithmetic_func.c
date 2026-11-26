#include <stdlib.h>
#include<stdio.h>

// Program run on ARM64
/*
  Explore the remaining Integer Arithmetic functions
  - int abs(int j)
  - long int labs(long int j)
  - long long int llabs(long long int j)
  - div_t div(int number, int demon)
  - ldiv-t ldiv(long number, long demon)
  - lldiv-t lldiv(long long number, long long demon)
  -----------------
  We essentially have the abs() and the div() function and various variants of these.
  div_t itself is a typedef struct with members quot & rem
  print out their values and the byte size they occupy in memory
*/
int main () {
  int a = abs(-50);
  long b = labs(-981);
  long long c = labs(-912342);
  printf("abs value of -50: %d. size in byte %zu\n", a, sizeof a); // size 4 bytes
  printf("labs value of -981: %ld. size in byte %zu\n", b, sizeof b); // size 8 bytes
  printf("llabs value of -912342: %lld. size in byte %zu\n", c, sizeof c); // size 8 bytes

  div_t d = div(10, 3);
  printf("Quotient is %d. Remainder is %d\n", d.quot, d.rem);
  return 0;
}