#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>


#include "metropolis.h"
#include "lattice.h"

int main(int argc, char **argv) {
  float *params = (float *)malloc(2*sizeof(float));

  *params = 0;
  *(params + 1) = 0;

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

 int nter = 40000; //es la cantidad de pasos para el sistema termalice.
 //int corr = 2000;
 srand(time(NULL));
 float B = 1;
 float J = 0;
 float J2 = 0;
 int jmax = 200; //cantidad de muestras
 int hmax = 2000; //tamaño del paso de correlacion.

 params = fill_lattice(lattice, n, prob, params, J, B, J2);
 float mag, mag2, energia, energia2, m, e;
 //print_lattice(lattice, n, *params, *(params+1));
 for (int k = 0; k < 5000; k++) {
   float T = 6 - 0.001 * k; //No poner T=0
   for (int i = 0; i < nter; i++) {
     params = metropolis(lattice, n, T, params, B, J, J2);
   }
   mag = 0;
   mag2 = 0;
   energia = 0;
   energia2 = 0;
   //m = 0;
   //e = 0;
   for (int j = 0; j < jmax; j++) {
     for (int h = 0; h < hmax; h++) {
       params = metropolis (lattice, n, T, params, B, J, J2);
       }
     m = *(params + 1);
     e = *(params);
     mag2 +=  pow(m, 2);
     mag += m;
     energia += e;
     energia2 += pow(e, 2);
   }

   mag = (mag / jmax) / (n * n);
   mag2 = (mag2 / jmax) / (n * n); // / (n * n * n * n);
   energia = energia / jmax;
   energia2 = energia2 / jmax;

  fprintf(output, "%f %f %f %f %f\n", T, mag, mag2, energia, energia2);
  //if(k == 0 || k == 499) print_lattice(lattice, n, energia, mag);
 }

fclose(output);
free(lattice);
return 0;
}
