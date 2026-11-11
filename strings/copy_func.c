#include <stdio.h>
#include <string.h>
#include "print.h"

int main () {
  /*
  Explore the various string copy functions
  */

  // string variable
  char src[] = {'h', 'o', 't', 'e', 'l', '\0', 'o', 'm', 'e', 'g', 'a', '\0'};

 // explore memcpy. Copies everything including \0
  char dest_memcpy[12] = {0};
  memcpy(dest_memcpy, src, 8);
  print_line(dest_memcpy, 12);

  // explore memmove. Copies everything including \0
  char dest_memmove[12] = {0};
  memmove(dest_memmove, src, 8);
  print_line(dest_memmove, 12);

  // explore strcpy. Automatically stops copying at the first \0
  char dest_strcpy[12] = {0};
  strcpy(dest_strcpy, src);
  print_line(dest_strcpy, 12);

  // explore strncpy. Even though size_t n is 8, it stopped copying at the encounter of the first \0 and writes null to the other memory space until the end
  char dest_strncpy[12] = {0};
  strncpy(dest_strncpy, src, 8);
  print_line(dest_strncpy, 12);

  return 0;
}

