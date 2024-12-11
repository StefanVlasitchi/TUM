#include <iostream>
#include <vector>

using namespace std;

class Buget
{

private:
    float portmoneu;
    vector <float> x_acumulari;
    vector <float> x_cheltuieli;

public:
int day=1;
Buget operator+=(float num)
{
    x_acumulari.push_back(num);
    return *this;
}
Buget operator-=(float num)
{
    x_cheltuieli.push_back(num);
    return *this;
}
Buget operator%=(float num)
{
   cout << "Taxe de drum: "<<(acum_sum()-lost_sum())*num<< endl;
    return *this;
}
Buget operator+(float num)
{
   cout << "Bonus la Salariu: "<<num<< endl;
    return *this;
}
Buget operator==(float num)
{
   cout << "Partea sotiei "<<(acum_sum()-lost_sum())*num<< endl;
    return *this;
}
float get_sum(const vector <float> &vec )
{
    float sum=0;
for (const auto &num : vec )
{
    sum+=num;
}
    return sum;
}
float lost_sum(){
    return get_sum(x_cheltuieli);
}
float acum_sum(){
    return get_sum(x_acumulari);
}

float venit ()
{
    cout <<"Venitul "<< acum_sum()-lost_sum()<<endl;

    return acum_sum()-lost_sum();
}
void media ()
{
  cout << "Media: " << acum_sum()/x_acumulari.size()<<endl;

}
float acumulari()
{
cout << portmoneu <<endl;
if (day >=30){
        portmoneu+=venit();
    }
return portmoneu;
}
void lunaNoua()
{
    x_cheltuieli.clear();
    x_acumulari.clear();
    day=1;
}
};
int main()
{
    Buget F;
    F.lunaNoua();
    F+=10000;
    F-=500;
    F.venit();
    F%=0.10;
    F==0.50;
    
    F.lunaNoua();
    for (int i=1 ; i <=30 ;i++)
    {
        F+=50;
        F-=8.5;
    }

    F.venit();
    F.media();
    F==0.50;
    F%=0.10;

}
