#include <stdio.h>

int main (int argc, char *argv[]) {
  float largest_number, smallest_number, num;
  size_t count = 0;
  for (;;)
  {
    printf("Enter a number: ");
    scanf("%f", &num);
    if (count < 1) {
      smallest_number = num;
      largest_number = num;
      ++count;
    }
    if (num == 0) {
      printf("The largest number entered was %.2f\n", largest_number);
      printf("The smallest number entered was %.2f\n", smallest_number);
      return 0;
    } else if (num > largest_number) {
      largest_number = num;
    }else if (num < smallest_number) {
      smallest_number = num;
    }
  }
    return 0;
}