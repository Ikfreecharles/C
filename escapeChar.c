#include <stdio.h>

int main (void) {
  int i;
  printf("\"Hello!\"");
  printf("\\\n");
  printf("Item\tUnit\tPrice\tPurchase\n\t2\t$70\t$140\n");

  printf("Enter a number: ");
  scanf("%d", &i);
  printf("You have entered %d", i);
  return 0;
}