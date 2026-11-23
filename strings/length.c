#include <stdio.h>

int main (void) {
  int ch;
  int length = 0;
  printf("Enter a message: ");
  while ((ch = getchar()) != '\n')
    {
      printf("Int value: %d\n", ch);
      length++;
    }
  printf("Your message was %d characters(s) long.\n", length);

  int k = 'A';
  int l = 65;
  printf("k: %d\n", k);
  printf("l: %d\n", l);
  if (k == l)
  {
    printf("k and l ARE THE SAME\n");
  }
  return 0;
}