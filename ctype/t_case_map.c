#include <stdio.h>
#include <ctype.h>

int main() {
  /*
  Explore tolowercase and touppercase function-like macros
  */
  char *p;
  for (p = "aAoi!jKlQ"; *p != '\0'; p++) {
    printf("tolowercase('%c') is '%c'; ", *p, tolower(*p));
    printf("touppercase('%c') is '%c'\n", *p, toupper(*p));
    printf("isdigit('%c') is '%c\n", *p, isdigit(*p));
  };
  return 0;
}