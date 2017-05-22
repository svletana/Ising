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
      printf("Error opening file!\n");
      exit(1);
  }

  int n = 32;
  int *lattice = (int *)malloc(n * n * sizeof(int));
  for (int k=0;k<1;k++) {
   float prob = 0.5+k*0.1;
   float T = 0.1; //No poner T=0
   int niter =3000;
   srand(time(NULL));
   float B = 100;
   float J=0;

   params = fill_lattice(lattice, n, prob, ener, mag);

   for (int i = 0; i < niter; i++) {
     params = metropolis(lattice, n, T, *params, *(params+1),B,J);
     //fprintf(output, "%f\n", prob );
     fprintf(output, "%.10f %.10f\n", *(params+1)/(n*n), *params); //escribe: mag ener

   }
   //fprintf(output, "\n" );
 }

  fclose(output);
  free(lattice);
  return 0;
}
