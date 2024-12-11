#include <iostream>
//3.La return pui return pointer;

//4.
double returnare_valoare_de_la_adresa(double * pNumber)
{        
    double** number ;
    number=&pNumber;
    return **number;
}

//5.
int* returnare_adresa_intreg_urmator(int* pointer)

{
    int** address;
    pointer++;
    address=&pointer;
    return *address;

   
}
//6.
long returnare_adresa_long_precedent (long* pNumber)
{
    long number, pNumber;
    pNumber = &number; 
    number=2*sizeof(pNumber);
    pNumber= &number;
    return *pNumber;
}
//7,8
int returnare_diferenta_pointeri(int* pointer1, int* pointer2)
{
    int** x , **y;
    x=&pointer1;
    y=&pointer2;
   //Un if in care introducem adresele intr-un vector unde verificam ca valorile sa fie mai mari ca 0
   return ;
}
//9.
int returnare_valoare_adresa_de_adresa(int**pointer )
{
    int* pointer1;
    int pointer2,x;
    pointer=&pointer1;
    pointer1=&pointer2;
    
    
return *pointer1;
}
