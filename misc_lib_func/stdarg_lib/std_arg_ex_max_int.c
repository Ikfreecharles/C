#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "../../args_length.h"

/*
  -- EXPLORE VA_ARGS --
  - va_list
  - type va_arg(va_list ap, type)
  - void va_start(va_list ap, parmN)
  - void va_end(va_list ap)
  - void va_copy(va_list dest, va_list src)
  ----------------------
  use type va_list and functions va_start() and va_end() to handle variable
  list arguments
*/

int read_int_max(int n, const char *, ...);

int main (int argc, char *argv[]) {
  args_length(argc, argv[0]);
  fprintf(stdout, "Largest integer is %d\n", read_int_max(5, "This is a note", 30, 20, 1, 80, 2));
  return 0;
}

int read_int_max(int n, const char *note, ...) {
  va_list ap; // holds the variable arguments
  
  int curr, largest;
  va_start(ap, note); // tells where the variable arguments start
  largest = va_arg(ap, int); // assigns first argument to largest and says it expects it to be an int

  for (size_t i = 0; i < n; i++)
  {
    curr = va_arg(ap, int);
    if (curr > largest)
      largest = curr;
  }
  va_end(ap); // cleanup before returning
  printf("%s\n", note);
  return largest;
}