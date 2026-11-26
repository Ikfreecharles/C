#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include "../../args_length.h"

#define CHK_VALID ("%d", errno != ERANGE ? 1 : 0)

/*
  Explore the various numeric conversion functions from <stdlib.h>
  - pass the value as a cmd arg
  CONDITION:
    - cmd arg must eq 2, else exit
*/

int main (int argc, char *argv[]) {
  args_length(argc, argv[0]);
  errno = 0;
  char *a = argv[1];
  printf("%e\n", DBL_MAX);
  printf("----------------\n");
  printf("a to float: %f. size of: %zu bytes\n", atof(a), sizeof atof(a));
  printf("a to int: %d. size of: %zu bytes\n", atoi(a), sizeof atoi(a));
  printf("a to long: %ld. size of: %zu bytes\n", atol(a), sizeof atol(a));
  printf("a to long long: %lld. size of: %zu bytes\n", atoll(a), sizeof atol(a));

  // strtod, strtol, strtoul
  char *b;
  double c = strtod(a, &b); // able to sets errno to ERANGE. strtol and strtoul too
  if (errno == ERANGE)
  {
    printf("Value out of range %d\n", errno);
    exit(EXIT_FAILURE);
  }
if (*b != '\0')
{
  printf("Conversion not completed - %s\n", b);
  exit(EXIT_FAILURE);
}
  printf("strtod - a to double: %f\n", c);
  return 0;
}