#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class Calculator
{
private:
    T num1, num2, fact;

public:
    Calculator(T n1, T n2)
    {
        num1 = n1;
        num2 = n2;
    }

    void displayResult()
    {
        cout << "Numerele: " << num1 << " si " << num2 << "." << endl;
        cout << num1 << " + " << num2 << " = " << add() << endl;
        cout << num1 << " - " << num2 << " = " << subtract() << endl;
        cout << num1 << " * " << num2 << " = " << multiply() << endl;
        cout << num1 << " / " << num2 << " = " << divide() << endl;
        cout << "raducalul numarului " << num1 << " este :" << sqrt(num1) << endl;
        cout << "raducalul numarului " << num2 << " este :" << sqrt(num2) << endl;
        cout << "Patratele  sunt :" << pow(num1, num2) << endl;
        cout << "Factorialul numarului " << num1 << " este :" << factoroial(num1) << endl;
        cout << "Factorialul numarului " << num2 << " este :" << factoroial(num2) << endl;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }
    T divide() { return num1 / num2; }
    T factoroial(float n)
    {
        fact = 1;
        for(float i=1;i<=n;i++)
        fact *=i;

        return fact;
    }
    
};


int firstRun=1;
void Menu(int *m)
{
    if(firstRun)
        firstRun = 0;
    else
    {
        system("pause");
        system("cls");
    }
    printf("\n1. Integer.");
    printf("\n2. Float.");
    printf("\n0. Iesire.");
    printf("\nOptiunea -");
    cin >> *m;
   
   
}
int main()
{
    int x, y, num = 0;
    float c, v;
    int m;
    do
    {   
        
        Menu(&m);
        switch (m)
        {
        case 1:
        {

            cout << "x=";
            cin >> x;
            cout << "y=";
            cin >> y;
            Calculator<int> intCalc(x, y);
            cout << "Int results:" << endl;
            intCalc.displayResult();
        }
        break;
        case 2:
        {
            cout << "c=";
            cin >> c;
            cout << "" << endl;
            cout << "v=";
            cin >> v;
            Calculator<float> floatCalc(c, v);
            cout << "Float results:" << endl;
            floatCalc.displayResult();
            break;
        }
        default:
            break;
        }  
    }
    while (m);

    return 0;
}