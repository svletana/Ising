#include "lattice.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int fill_lattice(int *lattice, int n, float p) {
  int i,j,k,s,elocal;
  energia = 0;
  magnetizacion = 0;
  // genero la red inicial aleatoriamente
  for (i=0;i<n*n;i++) {
    //srand(i*time(NULL)); //en cada iteracion genero una nueva semilla
    double s= ((double)rand())/RAND_MAX;
    if(s<p) { *(lattice + i) = 1; }
		  else { *(lattice + i) = -1; }
  }
  // calculo su energia
  for (i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      s = lattice[i + j*n];
      elocal = lattice[(n+i+1)%n + n*j] + lattice[(n+i-1)%n + n*j] + lattice[i + n*((j+1+n)%n)] + lattice[i + n*((j-1+n)%n)];
      energia += s*elocal;
    }
     // no estoy segura si esta bien el calculo de energia, y esto
  }
  energia = energia/2;
  //calculo su magnetizacion
  for (k=0;k<n*n;k++) {
          magnetizacion += (*(lattice + k));
  }
    
  return 0;
}

int print_lattice(int *lattice, int n) {
  int i,j;
  printf("ENERGIA: %f\n\n", energia);
  printf("MAGNETIZACION: %f\n\n", magnetizacion/(n*n));
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%2.1d  ",lattice[i*n + j]);
    }
    printf("\n");
  }

  return 0;
}
