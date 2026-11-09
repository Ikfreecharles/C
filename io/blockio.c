#include <stdio.h>

int main () {
  // fwrite writes the content of an array into a stream
  size_t num_el;
  char a[100] = "Charles is the bomb\nI can't get enough coffee and Cappucino!\n";
  FILE *fp = fopen("blockio.dat", "wb");
  num_el = fwrite(a, sizeof(a[0]), sizeof(a) / sizeof(a[0]), fp);
  fclose(fp);
  printf("number of elements written by fwrite is %zu\n", num_el);

  //freads reads the content of a stream into an array
  char b[100];
  FILE *rp = fopen("blockio.dat", "rb");
  num_el = fread(b, sizeof(b[0]), sizeof(b) / sizeof(b[0]), rp);
  fclose(rp);
  printf("number of elements written by fread is %zu\n", num_el);
  printf("%s", b);
  return 0;
}