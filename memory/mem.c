#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  int *p = malloc(sizeof(int));
  if (p != NULL) { 
    printf("(%d) address pointed to by p: %p\n", getpid(), p);
  }
  free(p);
  if (p) {
    printf("Address free - %p", p);
  }
  return 0;
}