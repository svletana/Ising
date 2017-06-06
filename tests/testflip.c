#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../src/lattice.h"
#include "../src/metropolis.h"

float calc(int k, int s, int n, int *red, float *params, float B, float J, float J2, float T);
int *elegirred(int *red, int n, int s, int i);

int main() {
  int *red = (int*)malloc(9 * sizeof(int));
  float *params = (float*)malloc(2 * sizeof(float));
  int s, n, i, k, trials;
  float T, B, J, J2, porcentaje;
  srand(time(NULL));

  n = 3; // testeamos flip con redes de 3x3
  s = 4;
  T = 1.0;
  B = 0;
  J = 1;
  J2 = 0;
  k = 5000; // numero de veces que se llama a flip
  trials = 4; // numero de test cases
  *params = 0;
  *(params + 1) = 0;

  for(i = 1; i <= trials; i++) {
    red = elegirred(red, n, s, i);
    porcentaje = calc(k, s, n, red, params, B, J, J2, T);
    print_lattice(red, n, *params, *(params + 1));
    printf("promedio valor del sitio: %f\n", porcentaje);
  }
  return 0;
}

float calc(int k, int s, int n, int *red, float *params, float B, float J, float J2, float T) {
  int j;
  float porcentaje;

  for(j = 0; j < k; j++) {
    params = flip(red, s, n, T, params, B, J, J2);
    porcentaje += *(red + s);
  }
  porcentaje = porcentaje / k; // da una idea de la cantidad de veces que se flipea el spin
  return porcentaje;
}

int *elegirred(int *red, int n, int s, int i) {
  int j;
  switch (i) {
    case 1:
      for(j = 0; j < n * n; j++) { *(red + j) = 1; }
      break;
    case 2:
      for(j = 0; j < n * n; j++) { *(red + j) = 1; }
      *(red + s) = -1;
      break;
    case 3:
      for(j = 0; j < n * n; j++) { *(red + j) = pow(-1,j); }
      break;
    case 4:
      for(j = 0; j < n * n; j++) { *(red + j) = 1; }
      *(red + s + 1 + n) = -1;
      break;
  }
  return red;
}
