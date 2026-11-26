#include <stdarg.h>
#include <stdio.h>

int error_wrapper_errorf(const char *, ...);

int main () {
  error_wrapper_errorf("error");
  error_wrapper_errorf("anther error");
  error_wrapper_errorf("yet another error");
  return 0;
}

int error_wrapper_errorf(const char *format, ...) {
  static int num_errors = 0; // adding static makes the variable global within the parent function
  int n;
  va_list ap;
  num_errors++;

  fprintf(stderr, "** Error %d: ", num_errors);
  va_start(ap, format);
  n = vfprintf(stderr, format, ap);
  va_end(ap);
  fprintf(stderr, "\n");
  return n;
}