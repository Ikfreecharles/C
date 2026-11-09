#include <stdio.h>
#include <math.h>

int main () {
  // explore copysign()
  float a = copysignf(4.567f, -3.872f);
  printf("a from copysignf call is %f\n", a);

  // explore nextafter()
  float b = nextafterf(5.782f, 7.872f);
  printf("b from nextafterf call is %f\n", b);

  float c = nextafterf(7.872f, 5.782f);
  printf("c from nextafterf call is %f\n", c);

  float d = nextafterf(7.0f, 7.0f);
  printf("d from nextafterf call is %f\n", d);
  return 0;
}