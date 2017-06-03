#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>


#include "metropolis.h"
#include "lattice.h"

int main(int argc, char **argv) {
  float *params = (float *)malloc(2*sizeof(float));

  *params = 0;
  *(params+1) = 0;

  FILE *output = fopen("../scripts/output.txt", "w");
  if (output == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  int n = 32;
  int *lattice = (int*)malloc(n * n * sizeof(int));

 float prob = 0.5; //Probabilidad inicial de llenado de la red con spines up. Está elegida de forma tal que los spines arranquen
 //con la condición inicial de forma mas aleatoria posible, asi tarda menos en termalizar.

 int nter = 5000; //es la cantidad de pasos para el sistema termalice.
 //int corr = 2000;
 srand(time(NULL));
 float B = 0.01;
 float J = 1;
 float J2 = 0;
 int jmax = 2000;
 int hmax = 2000;

 params = fill_lattice(lattice, n, prob, params);
 //print_lattice(lattice, n, *params, *(params+1));
 for (int k=0;k<500;k++) {
   float T=6-(0.01)*k; //No poner T=0
   for (int i = 0; i < nter; i++) {
     params = metropolis(lattice, n, T, params, B, J, J2);
   }
   float mag = 0;
   float mag2 = 0;
   float energia = 0;
   float energia2 = 0;
   for (int j = 0; j < jmax; j++) {
     for (int h = 0; h < hmax; h++) {
       params = metropolis (lattice, n, T, params, B, J, J2);
       }
     mag += *(params + 1);
     mag2 += (*(params + 1)) * (*(params + 1));
     energia += *(params);
     energia2 += (*(params)) * (*(params));
   }

   mag = mag / jmax;
   mag2 = mag2 / jmax;
   energia = energia / jmax; //Jmax: cantidad de muestras
   energia2 = energia2 / jmax;
   //hmax: tamaño del paso de correlacion.
  fprintf(output, "%f %f %f %f %f\n", T, mag / (n * n), mag2 / (n * n), energia, energia2);
 }

fclose(output);
free(lattice);
return 0;
}
