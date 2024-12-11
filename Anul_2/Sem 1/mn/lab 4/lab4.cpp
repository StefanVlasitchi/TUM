#include <iostream> 
#include <cmath>
using namespace std;  
float f(float(x), float(y)){
	return 1-sin(1.25*x+y)+(0.4/(2+x));
}

int main(){
	int n, i;
	double a, b;
	float h;
	float k0[25], k1[25], k2[25], k3[25];
	cout << " Ecuatia dy/dx = 1-sin(1.25x+y)+(0.4/(2+x))" << endl;
	cout << " Introduceti intervalul:" << endl << " a = "; 
	cin >> a;
	cout << " b = ";
	cin >> b;
	cout << " Introduceti pasul: ";
	cin >> h;
	n = (b - a) / h;
	double y[10], e[10], x[10], Y[10], L[10];
	cout << " Introduceti x0: ";
	cin >> x[0];
	cout << " Introduceti y0: ";
	cin >> y[0];
	cout << " --------------------------------------------" << endl;
	cout << " Metoda Euler " << endl;
	cout << " --------------------------------------------" << endl;
	for (i = 1; i <= n; i++) {
		x[i] = x[i - 1] + h;
	}
	for (i = 1; i <= n; i++){
		y[i] = y[i - 1] + (h*f(x[i - 1], y[i - 1]));
	}
	
	cout << " Iteratii    x        y          f(x,y)" << endl;
	for (i = 1; i <= n; i++) {
		cout << "   " << i << "\t " << x[i] << "\t " << y[i] << "\t  " << f(x[i], y[i]) << endl;
	}
	 
	return 0;
}
