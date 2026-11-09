#include <stdio.h>
#include <math.h>

int main () {
  // explore the remquo() function
  int quo;
  float h = remquof(-100.98123f, 8.127f, &quo);
  printf("h is %f. quo is %d\n", h, quo);
  return 0;
}