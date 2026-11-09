#include <stdio.h>
#include <math.h>

int main () {
  // explore fdim()
  double a = fdim(3.459, 5.873);
  double b = fdim(6.234, 3.326);
  printf("a from fdim call is %f\n", a);
  printf("b from fdim call is %f\n", b);
  printf("\n");

  // explore fmaxf()
  float c = fmaxf(3.2893, 7.87234);
  float d = fmaxf(7.87234, 3.2893);
  printf("c from fmaxf call is %f\n", c);
  printf("d from fmaxf call is %f\n", d);
  printf("\n");

  // explore fminf()
  float e = fminf(4.98123, 15.8934);
  float f = fminf(15.8934, -4.98123);
  printf("e from fminf call is %f\n", e);
  printf("f from fminf call is %f\n", f);
  printf("\n");
  return 0;
  /*
  NOTE:
    All of these functions from the math.h library can throw a domain or range error
    float f = fminf(15.8934, -4892839419782734390247722003401481081274675032477024.98123); this for example returns -inf
  */
}