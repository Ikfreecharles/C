#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]){
  /*
  - function call takes in one file name as a arg from the terminal e.g. ,/canopen test.txt
  - main open file in read mode
    * returns NULL, print error and exit
    * print file can be opened. close file.
  */
  FILE *fp;
  char *file = argv[1];
  if (argc > 2) {
    printf("usage: must pass only one file name\n");
    exit(EXIT_FAILURE);
  }
  if ((fp = fopen(file, "r")) == NULL) {
    printf("%s can't be opened\n", file);
    exit(EXIT_FAILURE);
  }
  printf("%s can be opened\n", file);
  
  fclose(fp);
  return 0;
}