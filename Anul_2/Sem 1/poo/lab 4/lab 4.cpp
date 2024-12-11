#include <iostream>
using namespace std;

class Imobile 
{
    int baie,living,bucatarie,camera1;
    float sum=0,fsum=0,bonus=0;
    public:
    void  get_surface()
    {
        cout<<"Suprafata baie:"<<endl;
        cin>>baie;
         cout<<"Suprafata living:"<<endl;
        cin>>living;
         cout<<"Suprafata bucatariei:"<<endl;
        cin>>bucatarie;
         cout<<"Suprafata camera 1:"<<endl;
        cin>>camera1;
    }
    float get_suprafata()
    {
    sum = baie + living + bucatarie + camera1;
    return sum;
    }
    float get_price(int psum=0)
    {
        return sum*psum;
    }
  float garaj()
    {
        cout <<"Locul de parcare de la parter:"<<endl;
        cin>>bonus;  
        return bonus;
    }
    float penthouse()
    {
        cout <<"Penthouse-ul de pe acoperis: "<<endl;
        cin>>bonus;
        return bonus;

    }
    float get_bprice(int psum=0)
    {
        return sum*psum+bonus;
    }
};

class Apartament1: private Imobile
{
    char adresa;
    int etajul,blocul,ap;
    public:
    void get_date()
    {
        cout<<"Strada, blocul, etajul, apartamentul "<<endl;
        cin>>adresa>>blocul>>etajul>>ap;
        get_surface();
        garaj();
    } 

    void print_date(int x)
    {
        cout<<"Pe strada "<<adresa<<" bl."<<blocul<<" etajul "<<etajul<<" apartamentul "<<ap<<endl;
        cout<<"Se vinde un apartament cu x camere cu o suprafata de "<<get_suprafata()<<endl;
        cout<<"Plus garajul"<<endl;
        cout<<"La un pret de: "<<get_bprice(x)<<endl;
    }
  
};

class Apartament2: private Imobile
{
    char adresa;
    int etajul,blocul,ap;
    public:
    void get_date()
    {
        cout<<"Strada, blocul, etajul, apartamentul "<<endl;
        cin>>adresa>>blocul>>etajul>>ap;
        get_surface();
        penthouse();
    } 

    void print_date(int x)
    {
        cout<<"Pe strada "<<adresa<<" bl."<<blocul<<" etajul "<<etajul<<" apartamentul "<<ap<<endl;
        cout<<"Se vinde un apartament cu x camere cu o suprafata de "<<get_suprafata()<<endl;
        cout<<"Plus penthous-ul"<<endl;
        cout<<"La un pret de: "<<get_bprice(x)<<endl;
    }
    
};
class Apartament3: private Imobile
{
    char adresa;
    int etajul,blocul,ap;
    public:
    void get_date()
    {
        cout<<"Strada, blocul, etajul, apartamentul "<<endl;
        cin>>adresa>>blocul>>etajul>>ap;
        get_surface();
    } 

    void print_date(int x)
    {
        cout<<"Pe strada "<<adresa<<" bl."<<blocul<<" etajul "<<etajul<<" apartamentul "<<ap<<endl;
        cout<<"Se vinde un apartament cu x camere cu o suprafata de "<<get_suprafata()<<endl;
        cout<<"La un pret de: "<<get_price(x)<<endl;
    }
    
};
int main ()
{
Apartament1 s;
s.get_date();
s.print_date(850);
Apartament2 w;
w.get_date();
w.print_date(850);
Apartament3 x;
x.get_date();
x.print_date(850);
}