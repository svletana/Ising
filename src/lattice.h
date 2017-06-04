#ifndef LATTICE_H
#define LATTICE_H
float *fill_lattice(int *lattice, int n, float p, float *params, float J, float B, float J2);
int print_lattice(int *lattice, int n, float ener, float mag);
#endif
