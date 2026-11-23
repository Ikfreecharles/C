#include <stdio.h>

void modify_value(double x, long *, double *);
void wrong_modify_value(double x, long, double);

int main(void)
{
  long i = 0;
  double j = 0;

  wrong_modify_value(3.14257, i, j);
  printf("WRONG call: \n");
  printf("Value of i: %ld\n", i);
  printf("Value of j: %f\n\n", j);

  modify_value(3.14257, &i, &j);
  printf("Correct call: \n");
  printf("Value of i: %ld\n", i);
  printf("Value of j: %f\n\n", j);

  modify_value(8.568920, &i, &j);
  printf("Correct call: \n");
  printf("Value of i: %ld\n", i);
  printf("Value of j: %f\n", j);
  return 0;
}

void modify_value(double x, long *int_part, double *frac_part){
  *int_part = (long)x;
  *frac_part = x - *int_part;
}

void wrong_modify_value(double x, long int_part, double frac_part) {
  int_part = (long)x;
  frac_part = x - int_part;
}