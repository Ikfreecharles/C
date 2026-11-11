#include <string.h>
#include "print.h"

int main () {
  /*
  Explore the concatenation functions
    strcat
    strncat
  */

  char src[] = "tea";
  // explore strcat
  char dest_strcat[7] = "hot";
  strcat(dest_strcat, src);
  print_line(dest_strcat, 7);

  // explore strncat
  char dest_strncat[9] = "black";
  strncat(dest_strncat, src, 1);
  print_line(dest_strncat, 9);
  return 0;
}