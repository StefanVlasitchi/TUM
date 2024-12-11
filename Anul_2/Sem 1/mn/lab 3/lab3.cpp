#include <iostream>
#include <iomanip>
#include<math.h>
int n = 7;
int z;
//Lagrange interpolarea valoarea polinomului in punctul x0
float x[] = {0.176, 0.349, 0.598, 0.768, 0.956, 1.987, 3.432 };
float y[] = {3.45612, 4.98457, 5.14388, 3.93012 ,1.78901,-1.2349,-2.9806};
using namespace std;
void Lagrange(double alpha)
{
    double l, L = 0;
     
    for (int i = 0; i <= n; i++)
     {
        l = 1;
        for (int j = 0; j <= n; j++)
            if (j != i)
            {
                l = l * (alpha - x[j]) / (x[i] - x[j]);
            }
        L = L + l * y[i];
          float Eroare = L - y[i];

        
        if(i==z)
        {
        
            if (alpha == 0.265)
                {
                    cout << setw(10) << L << " | " << endl;
                }
                else
                {
                    cout << setw(10) << L << " | " << setw(10) << abs(Eroare) << " |" << endl;
                }
        }
    }
}
int main() 
{
    std::cout <<"TI-216 Vlasitchi Stefan\n";
    cout << fixed;
    cout << " ------------------------------------------------------------" << endl;
    cout << " | " << setw(4) << "n" << " | " << setw(10) << "x(i)" << " | " << setw(10) << "y(i)" << " | " << setw(10) << "L(i)" << " | " << setw(10) << "L(i)-y[i]" << " |" << endl;
    cout << " ------------------------------------------------------------" << endl;
    for( z=0;z<n;z++)
    {
        cout << " | " << setw(4) << z << " | " << setw(10) << x[z] << " | " << setw(10) << y[z] << " | "; Lagrange(x[z]);
    }
    double alpha=0.265;
    cout << " ------------------------------------------------------------\n" << endl;
    cout << "Valoarea functiei f(x) in punctul x=" << alpha << " : L(6)(" << alpha << ") = ";
    Lagrange(alpha);
}   