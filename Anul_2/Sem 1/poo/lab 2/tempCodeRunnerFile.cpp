#include <iostream>
#include <math.h>
using namespace std;

unsigned long long i,j,k,h,t;
unsigned long long it1=0,it2=0,it3=0;
 unsigned long long fib1(unsigned long long n)
{
    if (n<2)
    {
        return n;
    }
    else
    {
        it1 = it1 + 4;
        return(fib1(n-1)+fib1(n-2));
    }
}

 unsigned long long fib2(unsigned long long n)
{
    long a=0;
    long b=1;
    long fib2    ;
   if (n == 0) {
	    fib2 = 0;
			
	};
	if (n == 1) {
		fib2 = 1;
		it2 = it2 + 3;
	};

	if (n >= 2) {
		it2 = it2 + 1;
		for (int i = 2; i <= n; i++) {
			it2 = it2 + 7;
			fib2 = a + b;
			a = b;
			b = fib2;
		}
	};

    return a;
}
 unsigned long long fib3(unsigned long long n)
{
    i=1;
    j=0;
    k=0;
    h=1;
    it3=5;
    while(n>0)
    {
        if (n%2!=0)
        {
            t=j*h;
            j=i*h+j*k+t;
            i=i*k+t;
            it3 = it3 + 12;
            

        }
        t=h*h;
        h=2*k*h+t;
        k=k*k+t;
        n=n/2;
        it3 = it3 + 11;
    }
    return j;
}

int main()
{
    long a,b,c;
    int x=0,y=0;

    cin>>x;
    y=x+1;
    a=fib1(x);
    b=fib2(y);
    c=fib3(x);
    //cout<<a<<" "<<it1<<endl<<b<<" "<<it2<<endl<<c<<" "<<it3;
    cout<<"Prin recursie nr. fib "<<a<<" are "<<it1<<"iteratii"<<endl;
    cout<<"Prin ciclu nr. fib "<<b<<" are "<<it2<<"iteratii"<<endl;
    cout<<"Prin formula nr. fib "<<c<<" are "<<it3<<"iteratii"<<endl;
}
