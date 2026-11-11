#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "print.h"

int main() {
  /*
  Explore the various string search functions
  */

  char *p, src[22] = "Form follows function";

  // explore memchr()
  p = memchr(src, 'f', sizeof(src));
  printf("memchar search result is %c\n", *p);

  // explore strchr
  p = strchr(src, 'r');
  printf("strchr search result is %c\n", *p);

  // explore strpbrk
  p = strpbrk(src, "mn");
  printf("strpbrk1 search result is %c\n", *p);
  p = strpbrk(src, "to");
  printf("strpbrk2 search result is %c\n", *p);

  // explore strstr
  p = strstr(src, "low");
  printf("strstr search result is %c\n", *p);
  return 0;
}