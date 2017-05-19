#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
 

#include "metropolis.h"
#include "lattice.h"


/*VARIABLES GLOBALES*/
float energia;
float magnetizacion; //OJO! MAGNETIZACION EN REALIDAD ES MAGNETIZACION POSTA * (n*n)

int main(int argc, char **argv) {

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
  fill_lattice(lattice, n, prob);
  print_lattice(lattice, n);
  for (int i = 0; i < niter; i++) {
    metropolis(lattice, n, T);
    fprintf(output, "%.10f\n", (magnetizacion)/(n*n));
    if (i==niter-1) print_lattice(lattice, n);
  }
  
  
  return 0;
}
