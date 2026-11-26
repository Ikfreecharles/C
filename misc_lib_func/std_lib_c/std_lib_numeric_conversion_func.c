#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include "../../args_length.h"

/*
  Explore the various numeric conversion functions
  int atoi()
  double atof()
  long atol()
  -- The first three lack error checks --

  double strtod(const char * restrict nptr, char ** restrict endptr)
  long int strtol()
  unsigned long int strtoul()

  ------
  All introduced in C99
    These two are similar to strtod(). 
    float strtof()
    long double strtold()
    ----------
    long long int strtoll()
    --------
    This is similar to strtoul()
    unsigned long long int strtoull()
*/

int32_t string_to_int(char *);
int32_t string_to_dou(char *);

int main(int argc, char *argv[])
{
  /* int atoi() converts string to integer */
  args_length(argc, argv[0]);
  printf("%d\n", string_to_dou(argv[1]));
  return 0;
}

int32_t string_to_int(char *a){
  /*
  atoi() is not reliable as it does no conversion status checks
  */
  return (int32_t)atoi(a);
}

/*
strtod, strtol, strtoul does the following:
- checks conversion success status
- stores ERANGE in errno if conversion produces out of range value
- strtod returns +/- HUGE_VAL
- strtol and strtoul returns the smallest or largest values of thier resp return types.
*/ 
int32_t string_to_dou(char *a) {
  /*
  Using strtod or one the other variants is a step better than atol()
  as it checks if conversion is successful
  */

  /*
  In this program, we:
    - convert string to double
    - test *endptr to check for failed conversion due to presence of non-numeric characters
    - check for int32 limits
    - cast result to int32 type
  */
  errno = 0;
  char *end;
  double b = strtod(a, &end);
  if (*end != '\0') {
    fprintf(stderr, "Number conversion failed\n");
    exit(EXIT_FAILURE);
  }
  if ( errno == ERANGE) {
    fprintf(stderr, "Number out of range\n");
    exit(EXIT_FAILURE);
  }
  if (b < INT32_MIN || b > INT32_MAX) { // without this check, casting to int32_t returns the max or min INT32 value
    fprintf(stderr, "Number is out of bound of int32_t. Conversion failed\n");
    exit(EXIT_FAILURE);
  }

  return (int32_t)b;
}