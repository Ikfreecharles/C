#include <stdio.h>

int main (void) {
  int digits_with_do = 0, digits_with_while = 1, n, k;

  printf("Enter a non zero number: ");
  scanf("%d", &n);
  k = n;

  while (k > 0) {
    k /= 10;
    digits_with_while++;
  };
  printf("The number in while has %d digit(s)\n", digits_with_while);

  do{
    n /= 10;
    digits_with_do++;
  } while (n > 0);
  printf("The number in do has %d digit(s) \n", digits_with_do);
  return 0;
}