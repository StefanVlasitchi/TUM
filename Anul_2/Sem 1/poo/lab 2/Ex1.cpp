#include <iostream>

using namespace std;

class Geometrie {
  private:
    int lungime , latime ;
    
  public:
    void initiere(int lun ,int lat)
    {
    lungime = lun;
    latime = lat ;
    }
      int Perimetru()
      {
        return 2*(lungime+latime); 
      }
      int Aria()
      {
        return lungime*latime;
      }
};

int main()
{
 int a,b;


cin>>a;
cin>>b;
Geometrie Ex1;
Ex1.initiere(a,b);


  cout << "Perimetru =  " << Ex1.Perimetru() << endl;
  cout << "Aria =  " <<Ex1.Aria() << endl;

  return 0;

}