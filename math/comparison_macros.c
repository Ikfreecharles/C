#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// this is a function-like macro
#define custom_greater(x, y) (x > y)

int main (int argc, char * argv[]) {
  // quick revision of function-like macro
  if (argc != 3) {
    printf("usage: Two floating point numbers should be passed!\n");
    exit(EXIT_FAILURE);
  }

  float x = strtof(argv[1], (char**)NULL);
  float y = strtof(argv[2], (char**)NULL);

  bool is_greater = custom_greater(x, y);
  printf("is greater? - %d\n", is_greater);

  // explore isgreater()
  int a = isgreater(x, y);
  printf("argv[1] = %f, argv[2] = %f\n", x, y);
  printf("a from isgreater call is %d\n", a);

  // explore islessequal()
  int b = islessequal(x, y);
  printf("b from islessequal is %d\n", b);
  return 0;
}