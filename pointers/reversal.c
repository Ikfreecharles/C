#include <stdio.h>
#include <stdlib.h>

#define N 25

void reversal(int *, int);
void print_array(int *, int);

int main (void){
  char ch;
  int a[N];
  int length = 0;

  printf("Enter a message with: ");
  while((ch = getchar()) != '\n') {
    a[length] = ch;
    length++;
  }
  printf("Original is: ");
  print_array(a, length);

  reversal(a, length);
  
  printf("Reversal is: ");
  print_array(a, length);
  return 0;
}

void reversal(int a[], int length) {
  int *p = a, *q = a + length -1, temp;
  while (p < q) {
    temp = *p;
    *p++ = *q;
    *q-- = temp;
  }
}

void print_array(int a[], int length) {
  for (int *i = a; i < a + length; i++)
    printf("%c", *i);
  printf("\n");
}
