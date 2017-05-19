#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>


#include "metropolis.h"
#include "lattice.h"

int main(int argc, char **argv) {
  float *params = malloc(2*sizeof(float));
  float ener = 0;
  float mag = 0;

  *params = ener;
  *(params+1) = mag;

  FILE *output = fopen("output.txt", "w");
  if (output == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  int n = 10;
  int *lattice = malloc(n * n * sizeof(int));
  float prob = 0.5;
  float T = 0.1; //No poner T=0
  int niter = 10000;
  srand(time(NULL));

  params = fill_lattice(lattice, n, prob, ener, mag); 
  print_lattice(lattice, n, *params, *(params+1));

  for (int i = 0; i < niter; i++) {
    params = metropolis(lattice, n, T, *params, *(params+1));
    fprintf(output, "%.10f\n", *(params+1)/(n*n));
    if (i==niter-1) print_lattice(lattice, n, *params, *(params+1));
  }

  return 0;
}
