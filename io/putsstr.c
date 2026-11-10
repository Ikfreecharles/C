#include <stdio.h>
#include <stdlib.h>

int main () {
  char str[20];
  printf("Enter a one line sentence with 20 characters: ");
  fgets(str, sizeof(str), stdin);
  puts(str);

  /*
  create a char variable which will hold the array of characters
  open the file stream - fopen(...)
  fgets(...) to get the sentence line
  puts(...) prints out the line in fstr
  close the opened filed stream - fclose(...)
  */
  char *ptr;
  char fstr[50];
  FILE *fp = fopen("sample_char.dat", "r");
  ptr = fgets(fstr, sizeof(fstr), fp);
  puts(fstr);
  fclose(fp);
  printf("fgets pointer - %p", ptr);
  return 0;
}