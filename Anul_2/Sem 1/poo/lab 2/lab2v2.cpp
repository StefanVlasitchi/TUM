#include <iostream>
using namespace std;

class FlowerShop
{
    private:
        string fname;
        int fprice;
        int fquantity;
        int fsuma ;
    public:
    
  FlowerShop()
  {
    cout<<"Introdu nume: ";
    cin>> fname;
     cout<<"Introdu pret: ";
    cin>> fprice;
     cout<<"Introdu cantitate: ";
    cin>> fquantity;
  }
  FlowerShop(string nume , int pret , int cantitatea, int sum)
  {
        fname=nume;
        fprice=pret;
        fquantity=cantitatea;
        sum=fprice*fquantity;
        fsuma=sum;
  }
  FlowerShop(const FlowerShop &produs1)
  {
    fname=produs1.fname;
    fprice=produs1.fprice;
    fquantity=produs1.fquantity;
  }

void display()
{
    cout<< "Nume produs: "<<fname<<endl;
    cout<< "Pret produs: "<<fprice<<endl;
    cout<< "Cantitate produs: "<<fquantity<<endl;
    cout<< "Pret produs: "<<fsuma<<endl;

}

};
int main()
{


    FlowerShop produs1;
    FlowerShop produs2=FlowerShop("Orhidee",30,6,180);
    FlowerShop produs3(produs1);
    produs1.display();
    produs2.display();
    produs3.display();
    
    

}

 