#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
  /*
  open file in write binary
  fwrite an array to file
  close file
  */

  FILE *fp = fopen("test_data.dat", "wb");
  if (fp == NULL)
    exit(EXIT_FAILURE);

  const float_t a[5] = {10.435, 2.763, 3.3092, 4.867, 5.12};
  fwrite(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
  fclose(fp);
  return 0;
}