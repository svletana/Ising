#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#include "metropolis.h"
#include "lattice.h"

int main(int argc, char **argv) {
  float *params = (float *)malloc(2*sizeof(float));
  float ener = 0;
  float mag = 0;

  *params = ener;
  *(params+1) = mag;

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
  {
      fprintf(stderr, "Error opening file!\n");
      exit(1);
  }

  int n = 32;
  int *lattice = (int *)malloc(n * n * sizeof(int));
 float prob = 0.5;
 float T = 0.1; //No poner T=0
 int niter = 10000;
 srand(time(NULL));
 float B = 1;
 float J = 1;
 float J2 = -1;

 params = fill_lattice(lattice, n, prob, ener, mag);

 for (int i = 0; i < niter; i++) {
   params = metropolis(lattice, n, T, *params, *(params+1),B,J,J2);
   //fprintf(output, "%f\n", prob );
   fprintf(output, "%.10f %.10f\n", *(params+1)/(n*n), *params); //escribe: mag ener

 }

  fclose(output);
  free(lattice);
  return 0;
}
