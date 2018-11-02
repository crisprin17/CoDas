#include <stdio.h>
#define ARRAY_SIZE 1024
#define NUMBER_OF_TRIALS 1000000
/* Declare static arrays small enough to stay in L1 cache. Assume the compiler aligns them correctly. */
static double a[ARRAY_SIZE], b[ARRAY_SIZE], c[ARRAY_SIZE], d;
void main(int argc, char *argv[]) {
  int i, t;
  double m = 1.5;
  /* Initialize b and c arrays */
  for (i=0; i < ARRAY_SIZE; i++) {
    b[i] = i*1.0e-9; c[i] = i*0.5e-9;
  }
  /* Perform operations with arrays many, many times */ for (t=0; t < NUMBER_OF_TRIALS; t++) {
    for (i=0; i < ARRAY_SIZE; i++) {
      a[i] += m*b[i] + c[i];
    } }
  /* Print a result so the loops won't be optimized away */ for (i=0; i < ARRAY_SIZE; i++) d += a[i]; printf("%f\n",d/ARRAY_SIZE);
}
