#include <conio.h>
#include <math.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "metode.h"

using namespace std;
void print(double lower[][max], double lowerT[][max], int n);
void CholeskyDescomposition(double A[][max], double lower[][max], double lowerT[][max], int size);

void Cholesky(double A[][max], double b[], int n){
	double lower[max][max]; // matricea inferioara triunghiulara
	double lowerT[max][max];
	double y[max], x[max];
    
    CholeskyDescomposition(A,lower,lowerT,n);
    
	// lower*y=b
	cout <<endl;
	y[0] = b[0] / lower[0][0];
	for(int i = 1; i < n; i++){
		double s = 0;
		for(int j = 0; j < i; j++)
			s += lower[i][j] * y[j]; 
			
		y[i] = (b[i] - s) / lower[i][i];
	}

	for(int i = 0; i < n; i++){
		cout << " | y[" << i+1 << "]= " << y[i]; 
	}

	// lowerT*x=y
	x[n-1] = y[n-1] / lowerT[n-1][n-1];
	for(int i = n-2; i >= 0; i--){
		double s = 0;
		for(int j = i+1; j < n; j++){
			s += lowerT[i][j] * x[j];
		}
		x[i] = (y[i] - s) / lowerT[i][i];
	}

	cout << "\n\nSolutiile dupa metoda Cholesky sunt :" << endl;
	for(int i = 0; i < n; i++){
		cout << " | x[" << i+1 << "]= " << x[i]; 
	}
	cout << endl;
}

void CholeskyDescomposition(double A[][max], double lower[][max], double lowerT[][max], int n){
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		lower[i][j] = 0;
		
	// Descomunera in matricea inferioara triunghiulara 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
 
            if (i == j) // Formula pt diagonala
            {
                for (int k = 0; k < j; k++)
                    sum += pow(lower[j][k], 2);
                lower[j][j] = sqrt(A[j][j] - sum);
            } else {								//Formula 2
                for (int k = 0; k < j; k++)
                    sum += (lower[i][k] * lower[j][k]);
                lower[i][j] = (A[i][j] - sum) / lower[j][j];
            }
        }
    }
	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		lowerT[i][j] = lower[j][i];

	print(lower,lowerT, n);
}
void print(double lower[][max], double lowerT[][max], int n){
    cout  << " Lower Triangular" 
         << setw(65) << "Transpose" << endl;
    for (int i = 0; i < n; i++) {
         
        // Lower Triangular
        for (int j = 0; j < n; j++)
            cout << setw(8) << lower[i][j] << "\t";
        cout << "\t";
         
        // Transpose of Lower Triangular
        for (int j = 0; j < n; j++)
            cout << setw(8) << lowerT[i][j] << "\t";
        cout << endl;
	}
}
