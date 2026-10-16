#include <stdlib.h>
#include <stdio.h>

int main (int argc, [[maybe_unused]] char* argv[argc+1]) {
  
    double A[5] = {
        [0]=9.0,
        [1]=2.9,
        [4]=3.E+25,
        [3]=.00007,
    };
    
    size_t B = 5;
    for (size_t i = 0; i < 5; ++i) {
        printf("element at index %zu is %g, \tits square is %g\n",
               i,
               A[i],
               A[i]*A[i]);
    }
    
    puts(*B);
    return EXIT_SUCCESS;
}
