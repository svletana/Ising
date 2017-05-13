#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

#include "metropolis.h"
#include "lattice.h"

/*VARIABLES GLOBALES*/
float energia;

int main(int argc, char **argv) {
  int n = 3;
  int *lattice = malloc(n * n * sizeof(int));
  float prob = 0.5;
  float T = 2.0;
  int niter = 1;
  fill_lattice(lattice, n, prob);
  print_lattice(lattice, n);
  for (int i = 0; i < niter; i++) {
    metropolis(lattice, n, T);
  }
  print_lattice(lattice, n);
  return 0;
}
