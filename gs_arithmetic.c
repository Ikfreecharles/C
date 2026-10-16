#include <stdio.h>

int main()
{
  size_t a = 45;
  size_t b = 7;
  size_t c = (a - b) * 2;
  size_t d = a - b * 2;

  printf("c is %zu \nd is %zu\n", c, d);
  puts("This is just a string");
}