#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_FILE "sample_char.dat"
#define OUTPUT_FILE "outputfile.dat"

int main () {
  FILE *fp;
  // read character from getchar and write to output stream
  printf("Enter a single character: ");
  int ch = getchar();

  if ((fp = fopen(SAMPLE_FILE, "w")) == NULL){
    printf("%s can't open\n", SAMPLE_FILE);
    exit(EXIT_FAILURE);
  }
  putc(ch, fp);
  fclose(fp);

  // read the character from an arbitraty stream and write to output stream
  FILE *input_stream;
  FILE *output_stream;
  if ((input_stream = fopen(SAMPLE_FILE, "r")) == NULL || (output_stream = fopen(OUTPUT_FILE, "a")) == NULL)
  {
    printf("%s or %s can't open\n", SAMPLE_FILE, OUTPUT_FILE);
    exit(EXIT_FAILURE);
  }
 putc(getc(input_stream), output_stream);
 fclose(input_stream);
 fclose(output_stream);
 return 0;
}