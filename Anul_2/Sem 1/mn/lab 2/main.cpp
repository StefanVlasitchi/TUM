#include <iostream>
#include <conio.h>
#include <math.h>
#include <iomanip>
#include "Gauss.cpp"
#include "Gauss_Seidel.cpp"
#include "Jacoby.cpp"
#include "Cholesky.cpp"

using namespace std;

int meniu();
double Norma(double A[][max], int size);
void print(double A[][max], int size);

int main() {
	//
	double A[max][max] ={
		{17.7, 0.3, 1.4, 0.9},
		{0.3, 20.1, -0.8,  -1.2},
		{ 1.4,  -0.8, 21.9,  0.8},
		{0.9,  -1.2, 0.8, 17.6}};
	double b[max] = {11.2, -20.3, 14.4, 17.9};
	int n = 4;
	double q = Norma(A,n);
	int option;
	do {
		switch (option = meniu()) {
		case 1: 
			Gauss(A, b, n);
			break;
		case 2: 
			Cholesky(A, b, n);
			break;
		case 3:  
			Jacoby(A,b,n,Norma(A,n));
			break;
		case 4: 
			Gauss_Seidel(A,b,n,Norma(A,n));
			break;
		}
		system("pause");
	}	 
	while (option != 0);
	std::cout <<    "Efectuat: St.Gr. TI-216, Vlasitchi Stefan" << std::endl;
}	

int meniu() {
	system("cls");
	std::cout << " 1. Metoda eliminarii lui Gauss." << std::endl;
	std::cout << " 2. Metoda Cholesky (metoda radacinii patrate)." << std::endl;
	std::cout << " 3. Metoda Iterativa a lui Jacobi." << std::endl;
	std::cout << " 4. Metoda Gauss-Scidel." << std::endl;
	std::cout << " 0. Iesire" << std::endl;
	int option;
	do {
		option = _getch();
	} while (option<'0' || option>'4');
	system("cls");
	return option - '0';
}

double Norma(double A[][max], int n){
	double Q[max][max];
    double q=0, m;

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(j==i){
				Q[i][j] = 0;
			}
			else 
				Q[i][j] = -A[i][j] / A[i][i];
		}
	}
	print(Q,n);

    for(int i=0; i<n; i++){
        m = 0;
        for(int j=0; j<n; j++){
            m += fabs(Q[i][j]);
        }
        if(q < m) 
			q = m;
			cout << m << endl;
	}
	cout << "norma = " << q << endl;
	// norma < 1;
    return q;
}

void print(double A[][max], int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			std::cout << std::setw(15) << A[i][j];
		}
		std::cout << std::endl;
	}
}