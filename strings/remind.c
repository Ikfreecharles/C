#include <stdio.h>
#include <string.h>
#include "../common/read_line.h"

#define MAX_REMIND 50
#define MSG_LEN 60

void sort_reminders(char *[MAX_REMIND] [MSG_LEN + 3], int n);

int main (void) {
  int day, num_remind = 0;
  char note[MSG_LEN + 1], day_str[3];
  char reminders[MAX_REMIND] [MSG_LEN + 3];

  for (;;)
  {
    if (num_remind >= MAX_REMIND){
      printf("-- No space left --\n");
      break;
    }
    printf("Enter day and reminder: ");
    scanf("%2d", &day);
    if (day == 0 || day > 31)
      break;
    sprintf(day_str, "%2d", day);
    read_line(note, MSG_LEN);

    strcpy(reminders[num_remind], day_str);
    strcat(reminders[num_remind], note);
    num_remind++;
  };
  // sort_reminders(reminders, num_remind);
  // Sort reminders
  char largest[MSG_LEN + 3];
  char last_el[MSG_LEN + 3];
  strcpy(largest, reminders[0]);
  strcpy(last_el, reminders[num_remind - 1]);

  int index_of_largest;

  for (int i = 0; i < num_remind; i++) {
    if ( strcmp(reminders[i], largest) >= 0 ){
      strcpy(largest, reminders[i]);
      index_of_largest = i;
    }
  };
  strcpy(reminders[index_of_largest], last_el);
  strcpy(reminders[num_remind - 1], largest);
  //  End of sort

  printf("\nDay Reminder\n");
  for (int i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);
  return 0;
}

void sort_reminders(char *a[MAX_REMIND] [MSG_LEN + 3], int n) {
  char largest[MSG_LEN + 3];
  char last_el[MSG_LEN + 3];
  strcpy(largest, *a[0]);
  strcpy(last_el, *a[n - 1]);

  int index_of_largest;

  for (int i = 0; i < n; i++) {
    if ( strcmp(*a[i], largest) >= 1 ){
      strcpy(largest, *a[i]);
      index_of_largest = i;
    }
  };
  strcpy(*a[index_of_largest], last_el);
  strcpy(*a[n - 1], largest);
}