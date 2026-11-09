#include <stdio.h>
#include <math.h>

#pragma STDC FP_CONTRACT OFF

int main() {
  // explore fmaf()
  float a;
  if (FP_FAST_FMAF)
  {
    printf("Using fmaf...\n");
    a = fmaf(3.45f, 6.23f, 10.78f);
    printf("a from fmaf is %f\n", a); 
  }
  else
  {
    // the pragma above when OFF instructs the compiler not to use contraction
    a = 3.45f * 6.23f + 10.78f;
    printf("a from fmaf is %f\n", a);
  }
  return 0;
}