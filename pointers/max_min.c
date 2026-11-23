#include <stdio.h>

#define N 10
void get_max_min(double a[], int, double *, double *);

int main (void) {
  double min, max, a[N] = { 30.59, 20.54, 8.03, 9.89, 10.54, 87.98, 54.09, 90.43, 76.84, 42.21 };

  get_max_min(a, N, &max, &min);
  printf("Smallest number is: %.2f\n", min);
  printf("Largest number is: %.2f\n", max);
  return 0;
}

void get_max_min(double a[], int n, double *max, double *min) {
  *min = *max = a[0];
  for (int i = 0; i < n; i++)
  {
    if ( a[i] < *min )
      *min = a[i];
    else if ( a[i] > *max )
      *max = a[i];
  }
}