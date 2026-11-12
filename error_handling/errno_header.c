#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <math.h>

#define set_errno(y) (errno = isnan(y) ? EDOM : isinf(y) ? ERANGE \
                                                         : 0)

int main() {
  errno = 2;

  float y = sqrtf(-5.0f);
  set_errno(y);

  if (errno != 0) {
    fprintf(stderr, "sqrt error; program terminated.\n");
    perror("sqrt error in perror");
    exit(EXIT_FAILURE);
  }
  printf("Value of y: %f\n", y);
  return 0;
}