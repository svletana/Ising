#include "metropolis.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


int metropolis(int *lattice, int n, float T) {
  int s;
  s = pick_site(lattice,n);
  //printf("\nvalor sitio elegido: %d\n", *(lattice + s));
  //printf("\nvalor sitio elegido: %d\n", s);
  flip(lattice,s,n,T);
  //printf("nuevo valor sitio: %d\n", *(lattice + s));
  return 0;
}

int pick_site(int *lattice, int n) {
  //srand(time(NULL));
  int s = (n*n)*((double)rand()/RAND_MAX);
  return s;
}

int flip(int *lattice, int s, int n, float T) {
  int i,j,sum,deltae;
  float prob, moneda;
  j=s%n;
  i=(s - s%n)/n;
  sum = lattice[(n+i+1)%n + n*j] + lattice[(n+i-1)%n + n*j] + lattice[i + n*((j+1+n)%n)] + lattice[i + n*((j-1+n)%n)];
  deltae = 2*(lattice[s])*sum; //chequear signo
  prob = exp((double)(-deltae/T));
  //printf("%f\n",prob);
  moneda = ((double)rand())/RAND_MAX;
  if (prob>moneda) { //obs: poner deltae menor a 0 como caso aparte.
    //if (*(lattice + s)<0) {
     *(lattice + s) = -*(lattice + s);
      energia += deltae;
      magnetizacion += 2*(*(lattice + s)) ;

  }
  return 0;
}
