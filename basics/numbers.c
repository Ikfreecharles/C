#include <stdio.h>

int main (void) {
  int i = 3;
  int j = 87;
  float k= 5.0f / 9.0f;

  short l = 70000;

  printf("This print integer in base 10 various formats: %d %.2d %-.3d\n", i, i, i);
  printf("This print integer in base 100 various formats: %.1d %.2d %-.3d\n",j, j, j );

  printf("This prints floating point %f %.1f %.2f %e %.2e", k, k, k, k, k);
  printf("%s",l);
  return 0;
}