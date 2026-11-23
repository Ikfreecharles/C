#include <stdio.h>

int main (void) {
  // Using signed short, when sum > 32767, overflow occurs
  // and result returns undesired result
  unsigned short num, sum=0;
  printf("This program sums a series of integers\n");
  for (;;)
  {
    printf("Enter integer (0 to terminate): ");
    scanf("%hd", &num);
    if (num == 0) {
      printf("The sum is: %hd\n", sum);
      return 0;
    }
    sum += num;
  };
  return 0;
}