#include <conio.h>
#include <math.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "metode.h"

using namespace std;

double _A[max][max][max], _b[max][max];
void print(double A[][max][max], double b[][max],int k, int size);
void inregistrareaDatelorGauss(double A[max][max], double b[max], int size);

void Gauss(double A[][max], double b[], int n){
	double x[max];
    inregistrareaDatelorGauss(A, b, n);
	for(int k = 0; k < n-1; k++){
		for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			if(i <= k) 
				_A[i][j][k+1] = _A[i][j][k];
			else if(j <= k) 
					_A[i][j][k+1] = 0;
				else 
					_A[i][j][k+1] = _A[i][j][k] - (_A[i][k][k] * _A[k][j][k]) / _A[k][k][k];
		}
		for (int i = 0; i < n; i++){
			if(i <= k) 
				_b[i][k+1] = _b[i][k];
			else 
				_b[i][k+1] = _b[i][k] - (_A[i][k][k] * _b[k][k]) / _A[k][k][k];
		}
		print(_A,_b,k+1,n);
	}
	x[n-1] = _b[n-1][n-1] / _A[n-1][n-1][n-1];

	for(int i = n-2; i >= 0; i--){
		double s = 0;
		for(int j = i+1; j < n; j++)
			s += _A[i][j][i] * x[j];
			
		x[i] = (_b[i][i] - s) / _A[i][i][i];
	}
	cout << "Solutiile dupa metoda Gauss sunt :" << endl;
	for(int i = 0; i < n; i++){
		cout << " | x[" << i+1 << "]= " << x[i]; 
	}
	cout << endl;
}


void inregistrareaDatelorGauss(double A[max][max], double b[max], int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			_A[i][j][0] = A[i][j];
			_b[i][0] = b[i];
		}
	}
}
void print(double A[max][max][max], double b[max][max], int k, int n){
	cout << k << ")" << endl;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout << setw(8) << A[i][j][k] << " ";
		}
		cout << " | " << b[i][k] << endl;
	}
	cout << endl;
}