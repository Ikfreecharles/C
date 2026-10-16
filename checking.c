#include <stdio.h>

int main(int argc, char *argv[]){
  int cmd;
  float balance = 0.0f, credit, debit;
  printf("*** ACME checkbook-balancing program ***\n");
  printf("Commands: 0=clear, 1=credit, 2=debit, 3=balance, 4=exit\n\n");

  // Using the for loop as an infinite for loop to take user inputs
  // Must take a command to exit the loop
  for (;;) {
    printf("Enter command: ");
    scanf("%d", &cmd);
    switch(cmd){
      case 0:
        balance = 0.0f;
        break;
      case 1:
        printf("Enter amount of credit: ");
        scanf("%f", &credit);
        balance += credit;
        break;
      case 2:
        printf("Enter amount of debit: ");
        scanf("%f", &debit);
        balance -= debit;
      case 3:
        printf("Current balance: %.2f\n", balance);
        break;
      case 4:
        printf("Your balance is %.2f\n", balance);
        return 0;
      default:
        printf("This command does not exist\n");
        break;
      }
  };
  return 0;
}