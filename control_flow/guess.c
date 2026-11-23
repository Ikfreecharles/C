#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100

int new_secret_number(void);
void read_guesses(int secret_number);

int main (void) {
  char command;
  int secret_number;

  printf("Guess the secret number between 1 and %d\n\n", MAX_NUMBER);
  srand((unsigned)time(NULL));
  
  do {
    secret_number = new_secret_number();
    printf("A new number has been chosen.\n");
    read_guesses(secret_number);
    printf("Play again? (Y/N): ");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');

  return 0;
}

int new_secret_number() {
  return rand() % MAX_NUMBER + 1;
}

void read_guesses(int secret_number) {
  int guess, attempts = 0;
  for (;;)
  {
    printf("Enter guess: ");
    scanf("%d", &guess);
    attempts++;
    if (guess == secret_number) {
      printf("You won in %d guesses\n\n", attempts);
      return;
    }
    else if (guess > secret_number)
    {
      printf("Too high, try again.");
    }
    else
    {
       printf("Too low, try again.");
    }
  };
}