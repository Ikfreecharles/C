#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "readline.h"

#define MAX_REMIND 50
#define MSG_LEN 60


int main (int argc, char *argv []) {
  char day_str[3], msg_str[MSG_LEN], *reminders[MAX_REMIND];
  int num_of_reminder = 0, day, i, j;

  for (;;)
  {
    if (num_of_reminder >= MAX_REMIND) {
      printf("--- No space left --\n");
      break;
    };
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0)
      break;
    else if (day > 31)
      printf("Day can't be bigger than 31");
    sprintf(day_str, "%2d", day);
    read_line(msg_str, MSG_LEN);

    for (i = 0; i < num_of_reminder; i++) 
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_of_reminder; j > i; j--)
      reminders[j] = reminders[j - 1];

    reminders[i] = malloc(2 + strlen(msg_str) + 1);
    if (reminders[i] == NULL)
     {
      printf("-- No space left --\n");
      break;
    }

    strcpy(reminders[i], day_str);
    strcat(reminders[i], msg_str);

    num_of_reminder++;
  };
  printf("\nDay Reminder\n");
  for (i = 0; i < num_of_reminder; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}