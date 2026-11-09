#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
  /*
  pass the source and destination filenames in the cmd
  CONDITIONS:
    - cmd must contain exactly three args (file, source name, destination name). Throw error if not
    - open both files in binary mode
    - copy all content of source until EOF
  */

  FILE *source_fp, *dest_fp;
  int ch;

  // check number of args
  if (argc != 3) {
    fprintf(stderr, "usage: fcopy source dest\n");
    exit(EXIT_FAILURE);
  }
  // open source and destination
  char *sf = argv[1];
  char *df = argv[2];
  if ((source_fp = fopen(sf, "rb")) == NULL)
  {
    fprintf(stderr, "Can't open %s\n", sf);
    exit(EXIT_FAILURE);
  }
  if ((dest_fp = fopen(df, "wb")) == NULL) {
    fprintf(stderr, "Can't open %s\n", df);
    exit(EXIT_FAILURE);
  }
  // copy from src to dest
  while ((ch = getc(source_fp)) != EOF)
    putc(ch, dest_fp);
  fclose(source_fp);
  fclose(dest_fp);
  return 0;
}