#include "metropolis.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int metropolis(int *lattice, int n, float T) {
  int s;
  s = pick_site(lattice,n);
  printf("\nvalor sitio elegido: %d\n", *(lattice + s));
  flip(lattice,s,n,T);
  printf("nuevo valor sitio: %d\n", *(lattice + s));
  return 0;
}

int pick_site(int *lattice, int n) {
  srand(time(NULL));
  int s = (n*n)*((double)rand()/RAND_MAX);
  return s;
}

int flip(int *lattice, int s, int n, float T) {
  int sum,deltae;
  float prob, moneda;
  sum = *(lattice + n*((s + n - 1)%n)) + *(lattice + n*((s + n + 1)%n)) + *(lattice + (s + n - 1)%n) + *(lattice + (s + n + 1)%n);
  deltae = -2*(lattice[s])*sum;
  prob = exp((double)deltae/T);
  moneda = ((double)rand())/RAND_MAX;
  if(prob>moneda) {
    *(lattice + s) = -*(lattice + s);
    energia += deltae;
  }
  return 0;
}
