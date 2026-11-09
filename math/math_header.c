#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <float.h>
#include <limits.h>

#if INT_MAX >= 2147483648
typedef long Quantity;
#else
typedef int Quantity;
#endif

int main () {
  printf("Float Evaluation Method: %d\n", FLT_EVAL_METHOD);
  printf("Value of isnan: %d\n", isnan(2));
  printf("Value of signbit: %d\n\n", signbit(-2));

  printf("Math error handling: %d\n", math_errhandling);
  printf("Math Error No: %d\n", MATH_ERRNO);
  printf("Math Error Exception: %d\n\n", MATH_ERREXCEPT);

  float_t result = powf(323.89, 10.09);
  printf("Power is: %f. Error no is: %d\n\n", result, errno);

  /*
  test various math.h methods and their err
  */

  // pass values that would make powf to be infinite and test isinf()
  float_t a = powf(32353434474853452326364624.89f, 2.09f);
  if (isinf(a))
    printf("a is inf - %d\n", isinf(a));
  else
    printf("a is: %f. Value of isinf is: %d\n", a, isinf(a));

  // pass a negative number ot sqrtf and test isnan()
  float_t b = sqrtf(-23.245f);
  if (errno == EDOM)
    printf("b is NaN - %d\n", isnan(b));
  else
    printf("b is: %f. Value of isnan is: %d\n\n", b, isnan(b));
  printf("\n");

  // gamma function lgamma()
  double value = 5;
  double c = tgamma(value);
  double d = lgamma(value);
  printf("tgamma c is: %.2f\n", c);
  printf("lgamma d is: %.4f\n", d);
  return 0;
}