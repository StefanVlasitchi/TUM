#ifndef METODE_H
#define METODE_H
#define max 100

void Gauss(double A[][max], double b[], int size);
void Cholesky(double A[][max], double b[], int size);
void Jacoby(double A[][max], double b[], int size, double norma);
void Gauss_Seidel(double A[][max], double b[], int size, double norma);

#endif