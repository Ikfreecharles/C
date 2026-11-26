#include <time.h>
#include <stdio.h>
#include <locale.h>

/*
Explore the time conversion function of <time.h>. The time conversion functions make it possible to convert calendar times to broken-down times.

- char *acstime(const struct tm *timeptr)
- char *ctime(const time_t *timer)
acstime converts from struct tm to character string.
ctime converts from Calender time time_t to character string
-----------------------
- struct tm *gmtime(const time_t *timer)
- struct tim *localtime(const time_t *timer)
gmtime() & localtime() converts time_t to struct tm
------------------

- size_t strftime(char * restrict s, size_t maxsize, const char * restrict format, const struct tm * restrict timeptr)
strftime converts struct tm to character string. This gives a great deal of control over how the time is formatted using the large array of conversion specifiers available
-----------------
*/



int run_acstime_conversion();
int run_ctime_conversion();
int run_gmtime_conversion();
int run_localtime_conversion();

int main()
{
  run_acstime_conversion();
  run_ctime_conversion();
  run_gmtime_conversion();
  run_localtime_conversion();
  return 0;
}

int run_acstime_conversion() {
  time_t timer = time(NULL);
  char *a = asctime(localtime(&timer)); // returns a pointer to a null terminated string
  printf("asctime conversion to char string: %s", a);
  return 0;
};

int run_ctime_conversion() {
  time_t timer = time(NULL);
  char *a = ctime(&timer);
  printf("ctime conversion to char string: %s", a); // Thu Nov 26 02:10:35 2026
  return 0;
};

int run_gmtime_conversion() {
  time_t timer = time(NULL);
  struct tm *t = gmtime(&timer); // gmtime returns time expressed in UTC
  printf("gmtime_tm_member\tvalue\n");
  printf("tm_day\t\t%d\n", t->tm_mday);
  printf("tm_mon\t\t%d\n", t->tm_mon);
  printf("tm_year\t\t%d\n", t->tm_year);
  printf("tm_yday\t\t%d\n", t->tm_yday);
  printf("tm_hour\t\t%d\n", t->tm_hour);
  return 0;
};

int run_localtime_conversion() {
  setlocale(LC_TIME, "ca_ES.ISO8859-15");
  time_t timer = time(NULL);
  struct tm *t = localtime(&timer); // localtime returns time expressed in localt time
  printf("localtime_tm_member\tvalue\n");
  printf("tm_day\t\t%d\n", t->tm_mday);
  printf("tm_mon\t\t%d\n", t->tm_mon);
  printf("tm_year\t\t%d\n", t->tm_year);
  printf("tm_yday\t\t%d\n", t->tm_yday);
  printf("tm_hour\t\t%d\n", t->tm_hour);
  return 0;
};

/*
OTHER NOTES
- changing the LC_TIME category of the locale may affect the strftime conversion specifier
*/