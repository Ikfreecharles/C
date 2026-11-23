#include <stdio.h>

int main(void) {
  short sum = 0, num;
  printf("*** This program sums a series of integers ***\n");
  printf("Enter integers (0 to terminate): ");
  scanf("%hu", &num);
  while (num != 0) {
    sum += num;
    scanf("%hu", &num);
  }
  printf("The sum is: %hu\n", sum);
  return 0;
}