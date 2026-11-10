#include <stdio.h>

int main () {
  char date[10];
  sprintf(date, "%d/%d/%d", 9, 20, 2026);
  fprintf(stdout, "%s\n", date);

  char name[13];
  snprintf(name, 13, "%s, %s", "Einstein", "Alberto");
  fprintf(stdout, "%s\n", name);
  return 0;
}