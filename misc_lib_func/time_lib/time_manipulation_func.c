#include <stdio.h>
#include <time.h>

int calc_processortime();
int calc_runtime();
int calc_mktime();

/*
  Explore the various types and function in <time.h>
  clock_t
  time_t
  struct tm - broken down time
  - clock_t clock(void)
  - double difftime(time_t time1, time_t time0)
  - time_t time(time_t *timer)
  - time_t mktime(struct tm *timeptr)
  --------------------
  clock() represents the processor time used by a program since exec started
*/
int main () {
  calc_processortime();
  calc_runtime();
  calc_mktime();
  return 0;
}

int calc_processortime() {
  size_t i;
  clock_t start_time = clock();
  for (i = 0; i < 10000000; i++) // count to 10 million
  {}
  printf("Value of i is %ld\n", i);
  printf("Program processor time used %f sec.\n", (clock() - start_time) / (double)CLOCKS_PER_SEC);
  printf("\n");
  return 9;
}
int calc_runtime() {
  size_t j;
  time_t start_time = time(NULL);
  for (j = 0; j < 5000000000; j++) // count to 2 billion
  {}
  printf("Value of j is %ld\n", j);
  printf("Process running time %f sec.\n", difftime(time(NULL), start_time));
  return 0;
}

int calc_mktime() {
  struct tm t;
  t.tm_mday = 27;
  t.tm_mon = 6;
  t.tm_year = 112;
  time_t a = mktime(&t);
  printf("mktime return value %ld\n", a);
  printf("tm_member\tvalue\n");
  printf("tm_day\t\t%d\n", t.tm_mday);
  printf("tm_mon\t\t%d\n", t.tm_mon);
  printf("tm_year\t\t%d\n", t.tm_year);
  return 0;
}

/*
Some macros in <time.h>
CLOCK_PER_SEC
*/