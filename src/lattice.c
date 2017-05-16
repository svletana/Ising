#include "lattice.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int fill_lattice(int *lattice, int n, float p) {
  int i,j,s,elocal;
  energia = 0;
  // genero la red inicial aleatoriamente
  for (i=0;i<n*n;i++) {
    srand(i*time(NULL)); //en cada iteracion genero una nueva semilla
    s = 2*(rand()%2) - 1;
    *(lattice+i) = s;
  }
  // calculo su energia
  for (i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      s = lattice[i + j*n];
      elocal = lattice[(n+i+1)%n + n*j] + lattice[(n+i-1)%n + n*j] + lattice[i + n*((j+1+n)%n)] + lattice[i + n*((j-1+n)%n)];
      energia += s*elocal;
    }
    energia = energia/2; // no estoy segura si esta bien el calculo de energia, y esto
  }
  return 0;
}

int print_lattice(int *lattice, int n) {
  int i,j;
  printf("ENERGIA: %f\n\n", energia);
  for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
      printf("%2.1d  ",lattice[i*n + j]);
    }
    printf("\n");
  }

  return 0;
}
