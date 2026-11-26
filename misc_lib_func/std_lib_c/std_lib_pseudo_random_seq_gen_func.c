#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/*
Explore the <stdlib.h> pseudo random sequence generation functions
- int rand(void)
- void srand(unsigned int seed)
*/

int main () {
  // rand() returns a number btw 0 and RAND_MAX. The numbers returned are not quite random. They are generated from a seed value
  printf("value of RAND_MAX: %d\n", RAND_MAX);

  // calling srand() therefore supplies a seed value for rand
  printf("Random number generated: %d\n", rand()); // default seed is 1

  //calling srand() before rand()
  srand(time(NULL));
  printf("New random number with srand supplied seed: %d\n", rand());
  return 0;
}