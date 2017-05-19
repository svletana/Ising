#ifndef METROPOLIS_H
#define METROPOLIS_H
float *metropolis(int *lattice, int n, float T, float ener, float mag);
int pick_site(int *lattice, int n);
float *flip(int *lattice, int s, int n, float T, float ener, float mag);
#endif
