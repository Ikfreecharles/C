#include <stdio.h>
#include <string.h>

#define MSG_LEN 20

int read_line(char *, int n);

int main(int argc, char *argv[])
{
  char ch[MSG_LEN + 1], smallest_word[MSG_LEN + 1] = {}, largest_word[MSG_LEN + 1] = {};

  for (;;)
  {
    printf("Enter word: ");
    read_line(ch, MSG_LEN);

    if (strlen(ch) == 4)
      break;
    if (strcmp(ch, smallest_word) < 0)
      strcpy(smallest_word, ch);

    if (strcmp(ch, largest_word) > 0)
      strcpy(largest_word, ch);

  };
  printf("Smallest word is: %s\n", smallest_word);
  printf("Largest word is: %s\n", largest_word);
  return 0;
}

int read_line(char a[], int n) {
  int ch, i = 0;
  while ((ch = getchar()) != '\n')
    if(i < n)
     {
       a[i++] = ch;
     }
  a[i] = '\0';
  return i;
}