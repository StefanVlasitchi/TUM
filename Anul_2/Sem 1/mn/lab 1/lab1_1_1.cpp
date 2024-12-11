#define _USE_MATH_DEFINES
#include <iostream>
#include "bits/stdc++.h"
#define epsilon 0.0000001
#define epsiloon 0.001
using namespace std;

int it=0,it1=0,it2=0,it3=0;

double mx1,mn1,mx2,mn2,q;

double f(double x) {
	return cos(x) + 2 * x - 0.5;
}
double fi(double x) {
	return (-cos(x)+0.5)/2;
}
double f1(double x) {
	return 2-sin(x);
}
double f2(double x) {
	 return -cos(x);
}
void m1(double a,double b)
{
    if(f1(a)>f1(1))
    {
        
        mx1=f1(a);
        mn1=f1(b);
    }
    else
    {
        
        mx1=f1(b);
        mn1=f1(a);
    }
    
}
void m2(double a,double b)
{
    if(f2(a)>f2(1))
    {
        mx2=f2(a);
        mn2=f2(b);
    }
    else
    {
        mx2=f2(b);
        mn2=f2(a);
    }
}

double injumatatire(double a,double b)
{
    double c;
    if((f(a)*f(b))<0)
    {
        while(abs(b-a)>2*epsiloon)
        {
            it++;
            c=(a+b)/2;
            if(f(a)*f(c)<0)
                b=c;
            else
                a=c;
        }
        return c;
    }
    else
        return -1;
}
double aproximare(double a,double b)
{
    double x=a,y;
    q=(mx1-mn1)/(mx1+mn1);
    y=fi(x);
    while(((q/(1-q))*(y-x))>=0.000001)
    {
        it1++;
        x=y;
        y=fi(x);
    }
    return x;
    
}
double newton(double a,double b)
{
    double x,x1;
    if((f(a)*f2(a))>0)
    {
        x=x1=a;
    }
    else x=x1=b;
    x=x1;
    x1=x-f(x)/f1(x);
    it2++;
    while(mx2/2*mn1*pow((x1-x),2)>epsilon)
    {
        x=x1;
        x1=x-f(x)/f1(x);
        it2++;
    }
    return x1;
}

double secanta(double a,double b)
{
    int i = 0;
    double x, x1;
    if ((f(a) * f2(a)) > 0)
    {
        x = a;
        x1=a;
    }
    else
    {
        x = b;
        x1=b;
    }
    double c;
    it3++;
    if(x==b)
    {
        x=x1-f(x1)*((x1-a)/(f(x1)-f(a)));
        c=x-x1;
        while ((mx1 - mn1) / mn1 * abs(c) >= epsilon)
        {
            x=x1-f(x1)*((x1-a)/(f(x1)-f(a)));
            c=x-x1;
            x1=x;
            it3++;
        }
    }
    if(x==a) 
    {
        x=x1-f(x1)*((b-x1)/(f(b)-f(x1)));
        c=x-x1;
        while ((mx1 - mn1) / mn1 * abs(c) >= epsilon)
        {
            x=x1-f(x1)*((b-x1)/(f(b)-f(x1)));
            c=x-x1;
            x1=x;
            it3++;
        }
    }
    return x;
}


int main()
{
    double a=-0.25,b=0;
    m1(a,b);
    m2(a,b);
    cout<<"\n\nIntervalul (-0.25,0)"<<endl;
    cout<<"Metoda injumatatirii intervalului: "<<endl<<"x = "<<injumatatire(a,b)<<endl;
    cout<<"Numarul de iteratii: "<<it<<endl;
    cout<<"Metoda aproximarilor succesive: "<<endl<<"x =  "<<aproximare(a,b)<<endl;
    cout<<"Numarul de iteratii: "<<it1<<endl;
    cout<<"Metoda Newton: "<<endl<<"x = "<<newton(a,b)<<endl;
    cout<<"Numarul de iteratii: "<<it2<<endl;
    cout<<"Metoda secantei: "<<endl<<"x = "<<secanta(a,b)<<endl;
    cout<<"Numarul de iteratii: "<<it3<<endl;
    cout<<"M1="<<mx1<<endl;
    cout<<"m1="<<mn1<<endl;
    cout<<"M2="<<mx2<<endl;
    
    cout<<"q="<<q;
    return 0;
}
