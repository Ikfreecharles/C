#include <stdio.h>
#include <math.h>

int main () {
  // explore the various variant of round()
  double e = round(4901357234.4);
  float f = roundf(4123072.3);
  long double g = roundl(423408234753.5);

  printf("e is %f. Size of double is %zu\n", e, sizeof e);
  printf("f is %f. Size of float is %zu\n", f, sizeof f);
  printf("g is %Lf. Size of long double is %zu\n", g, sizeof g);
  printf("\n");

  /*
  let's write these values to a binary file to view their "bits"
  wc -c <file-name> to check size
  xxd -g 1 <file-name> to check binary data
  */
  FILE *fp  = fopen("float_sizes.dat", "wb");
  fwrite(&e, sizeof(e), 1, fp);
  fwrite(&f, sizeof(f), 1, fp);
  fwrite(&g, sizeof(g), 1, fp);
  fclose(fp);

  FILE *fptext  = fopen("float_sizes_non_binary.dat", "w");
  fprintf(fptext, "%.2f", 4.0f);
  fprintf(fptext, "%.2f", 4.0f);
  fprintf(fptext, "%.2Lf", 5.0l);
  fclose(fptext);

  /*
  NOTE:
    Writing as binary above, the file maintains its 20 bytes size irrespective of the size of the number.
    However, with fprint(), each number takes a byte. So if the numbers 4,4,5 are written to the file, the size will be 3 bytes. However, if the same number from e,f,g are written, each number will take a byte therefore immediately bloating the file past 20 bytes. 35 bytes actually.
    So at very small numbers, not writing as binary might shine. But this quickly turns sour.
    These large numbers is where binary shines and in most programs, it immediately shines.
  */

  // explore lround()
  long a = lroundf(4.5f);
  long b = lroundf(4.3f);
  printf("a is %ld. Size of long is %zu\n", a, sizeof a);
  printf("b is %ld. Size of long is %zu\n", b, sizeof b);
  return 0;
}