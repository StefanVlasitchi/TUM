#include <conio.h>
#include <math.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "metode.h"

using namespace std;

void Gauss_Seidel(double A[][max], double b[], int n, double q){
	double x[max], y[max];
	int iter{0};
	double eps = pow(10, -3);
	double s, s1;
	for(int i=0; i<n; i++){
		x[i]=b[i];
	}
	do{
		iter++;
		for(int i=0; i<n; i++, s1=0){
			for(int j=0; j<n; j++){
				if(j!=i) 
					s1+= A[i][j] * x[j];
				x[i] = (b[i] - s1) / A[i][i];
			}
		}
		s = 0;
		for(int i=0; i<n; i++){
			s += fabs(x[i] - y[i]);
		}
		cout << iter << ")";
		for(int i=0; i<n; i++){
			cout << " | x[" << i+1 << "]= " << x[i]; 
			y[i] = x[i];
		}
		cout << endl;
	}while(q/(1-q)*s >= eps);

	cout << "\nSolutiile dupa metoda Gauss-Seidel sunt :" << endl;
	for(int i = 0; i < n; i++){
		cout << " | x[" << i+1 << "]= " << x[i]; 
	}
	cout << "\nS-au produs " << iter << " iteratii." <<endl;
}