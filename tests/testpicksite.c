#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "../src/metropolis.h"

int main() {
  /* Este programa testea la funcion pick_site de metropis.c. Imprime dos valores numericos,
  el primero deberia ser igual a cero si todos los sitios de la red fueron elegidos al menos una vez.
  El segundo valor da una idea de que tan equitativamente fueron distribuidas las elecciones de sitio por pick_site.
  Si el mismo es igual a 1, quiere decir que todos los sitios fueron elegidos la misma cantidad de veces. */
  int i, j, s, niter, n, sum;//, P;
  float expect, res;

  n = 10;
  int *lattice = (int *)malloc(n*n*sizeof(int));
  int *histogram = (int *)malloc(n*n*sizeof(int));

  for (j=0;j<n*n;j++) { *(lattice + j) = 1;  *(histogram + j) = 0; }
  niter = 100000;
  srand(time(NULL));

  for(i=0;i<niter;i++) {
    s = pick_site(lattice, n);
    *(histogram + s) += 1;
  }
  free(lattice);

  sum = 0;
  res = 0;
  for(i=0;i<n*n;i++) {
    if (*(histogram + i)==0) { sum += 1; }
    res += (i+1)*(*(histogram + i));
  }
  printf("%d\n", sum);
  //P = n*n*(n*n + 1)*0.5; //suma parcial
  //expect = (niter*P)/(n*n);
  expect = niter*(n*n + 1)*0.5;
  printf("%f\n", res/expect);

  return 0;
}
