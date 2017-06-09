#include "lattice.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

float *fill_lattice(int *lattice, int n, float p, float *params, float J, float B, float J2) {
  int i, j, k, s, elocal, sum2, ener, mag;

  // genero la red inicial aleatoriamente
  for (i = 0; i < n * n; i++) {
    double s= ((double)rand())/RAND_MAX;
    if(s < p) { *(lattice + i) = 1; }
		  else { *(lattice + i) = -1; }
  }

  // calculo su energia
  for (i = 0; i < n; i++) {
    for(j = 0; j < n; j++) {
      s = lattice[i + j * n];
      elocal = lattice[(n + i + 1) % n + n * j] + lattice[(n + i - 1) % n + n * j] + lattice[i + n * ((j + 1 + n) % n)] + lattice[i + n * ((j - 1 + n) % n)];
      sum2 = lattice[i + 1 + n * ((j + 1 + n) % n)] + lattice[i + 1 + n * ((j - 1 + n) % n)] + lattice[i - 1 + n * ((j + 1 + n) % n)] + lattice[i - 1 + n * ((j - 1 + n) % n)];
      ener += s * ( J * elocal + B + J2 * sum2 );
    }
  }
  ener = ener / 2;

  //calculo su magnetizacion
  for (k = 0; k < n * n; k++) {
          mag += (*(lattice + k));
  }

  *params = ener;
  *(params + 1) = mag;

  return params;
}

int print_lattice(int *lattice, int n, float ener, float mag) {
  int i,j;
  //printf("ENERGIA: %f\n\n", ener);
  //printf("MAGNETIZACION: %f\n\n", mag/(n*n));
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      if(lattice[i*n + j] == 1) { printf("\x1B[31m + "); }
      else {printf("\x1B[37m - ");}
    }
    printf("\x1B[37m \n");
  }
  printf("\n\n");

  return 0;
}
