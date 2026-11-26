#include <stdlib.h>
#include <stdio.h>

/*
  Explore <stdlib.h>
  - char *getenv(const char *name)
  - int system(const char *string)
  - void exit(int status)
  - void abort(void)
  - int atexit(void (*func)(void))
  - void _Exit(int status) introduced in C99 
  -------------
  getenv() provides access to any string in the user's environment.
  system() allows to run another program e.g. an OS command.
  exit() terminates a program and returns status code to the operating system.
  abort(). similar to exit. it causes abnormal program termination. Abort unlike exit() might not flush output buffers, not close streams and leave temporary files undeleted.
  atexit() allows us to call a function at program exit.
*/

int main () {
  char *a = getenv("PATH");
  printf("%s\n\n", a);
  int b = system("ls -al"); // returns 0 for success. non-zero for failure
  if (b != 0)
    printf("System call failed\n");
  printf("System call successful\n");
  return 0;
}