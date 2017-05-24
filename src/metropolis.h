#ifndef METROPOLIS_H
#define METROPOLIS_H
float *metropolis(int *lattice, int n, float T, float ener, float mag,float B, float J, float J2);
int pick_site(int *lattice, int n);
float *flip(int *lattice, int s, int n, float T, float ener, float mag,float B, float J, float J2);
#endif
