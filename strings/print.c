#include <stdio.h>
#include "print.h"

void print_line(char * str, size_t n) {
  for (size_t i = 0; i < n; i++)
    printf("%c", str[i] == '\0' ? '-' : str[i]);
  printf("\n");
}