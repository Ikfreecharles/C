#include <stdio.h>
#include <stdlib.h>

int main () {
  FILE *fp;
  char ch = 'c';

  if ((fp = fopen("sample.txt", "w")) == NULL){
    printf("%s can't open\n", "sample.txt");
    exit(EXIT_FAILURE);
  }
  fputc(ch, fp);
  fclose(fp);
  return 0;
}