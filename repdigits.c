#include <stdio.h>
#include <stdbool.h>

// #define N 5

// int main (void) {
//   int num;
//   int a[5], i = 0;

//   printf("Enter a 5 digit number: ");
//   scanf("%u", &num);
//   while(num > 0 && i < N) {
//     a[i] = num % 10;
//     num /= 10;
//     i++;
//   }
//   for (int i = 0; i < N; i++) {

//   }
//     printf("Array: %lu\n", sizeof(a) / sizeof(a[0]));
//   return 0;
// }

int main (void) {
  bool digit_seen[10] = {false};
  long n;
  int digit;

  printf("Enter a number: ");
  scanf("%ld", &n);
  
  while(n > 0) {
    digit = n % 10;
    if (digit_seen[digit])
      break;
    digit_seen[digit] = true;
    n /= 10;
  }
  if (n > 0)
    printf("Repeated digits\n");
  else
    printf("No repeated digits\n");
  return 0;
}