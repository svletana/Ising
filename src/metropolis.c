#include "metropolis.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


float *metropolis(int *lattice, int n, float T, float *params, float B, float J, float J2) {
  int s;
  s = pick_site(lattice, n);
  return flip(lattice, s, n, T, params, B, J, J2);
}

int pick_site(int *lattice, int n) {
  int s = (n * n) * ((double)rand()/RAND_MAX);
  return s;
}

float *flip(int *lattice, int s, int n, float T, float *params, float B, float J, float J2) {
  int i, j, sum, sum2, deltae;
  float prob, moneda, ener, mag;
  ener = *params;
  mag = *(params + 1);

  j = s % n;
  i = (s - s % n) / n;
  sum = lattice[(n + i + 1) % n + n * j] + lattice[(n + i - 1) % n + n * j] + lattice[i + n * ((j + 1 + n) % n)] + lattice[i + n * ((j - 1 + n) % n)];
  sum2 = lattice[i + 1 + n * ((j + 1 + n) % n)] + lattice[i + 1 + n * ((j - 1 + n) % n)] + lattice[i - 1 + n * ((j + 1 + n) % n)] + lattice[i - 1 + n * ((j - 1 + n) % n)];
  deltae = 2 * (lattice[s]) * (J * sum + B + J2 * sum2);
  if (deltae < 0) {
    *(lattice + s) = -*(lattice + s);
     ener += deltae;
     mag += 2 * (*(lattice + s)) ;
  }
  else {
    prob = exp((double)(-deltae/T));
    moneda = ((double)rand())/RAND_MAX;
    if (prob>moneda) {
       *(lattice + s) = -*(lattice + s);
        ener += deltae;
        mag += 2*(*(lattice + s)) ;
    }
  }

  *params = ener;
  *(params + 1) = mag;

  return params;
}
