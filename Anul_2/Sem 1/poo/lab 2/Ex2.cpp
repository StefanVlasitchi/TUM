#include <iostream>
#include<conio.h>
const int i = 3;
using namespace std;


// Student Class Declaration
class StudentClass {
private://Access - Specifier
   //Member Variable Declaration
   char name[20];
   int  sub1, sub2, sub3, temp[2];
   float total, avg;

public://Access - Specifier
   //Member Functions read() and print() Declaration

   void read() {
      //Get Input Values For Object Variables
      cout << "Introdu numele Studentului :";
      cin >> name;

      

      cout << "Introdu notele(3 note) :" << endl;
      cin >> sub1 >> sub2>> sub3;
   }

   float media() {
      total = sub1 + sub2 + sub3;
      avg = total / 3;
      return avg;
   }

   
   void print() {
      //Show the Output
      cout << "Nume :" << name << endl;
      cout << "Nota :" << sub1 << " , " << sub2 << " , " << sub3 << endl;
      cout << "Media :" << avg << endl;
   }
};

int main() {
   // Object Creation For Class
   StudentClass stu1, stu2 , stu3, M;
    

   cout << "Afisarea rezultatelor finale:\n";

   cout << "\n Student 1" << endl;
   stu1.read();
   stu1.media();
   stu1.print();

   cout << "\n Student 2" << endl;
   stu2.read();
   stu2.media();
   stu2.print();

cout << "\n  Student 3" << endl;
   stu3.read();
   stu3.media();
   stu3.print();

   

   if (stu1.media()>stu2.media() && stu1.media()> stu3.media())
   {
      cout << "Studentul 1 are media cea mai mare"<<endl;
   }
   if(stu1.media()<stu2.media() && stu1.media()> stu3.media())
   {
      cout << "Studentul 2 are media cea mai mare"<<endl;
   }
   else
      cout << "Studentul 3 are media cea mai mare"<<endl;

   getch();
   return 0;
}