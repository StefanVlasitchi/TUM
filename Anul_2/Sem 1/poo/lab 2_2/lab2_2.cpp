#include <iostream>
#include <iomanip>
#include <string>
#include <bits/stdc++.h>

using namespace std;
  
class Student
{
public:
    string Name;
    string Surrname;
    float nota1;
    float nota2;
    float nota3;
    float media;

    Student()
    {
        cout << "Introduceti numele si prenumele: ";
        cin >> Name >> Surrname;
        cout << "Introduceti nota la nota1: ";
        cin >> nota1;
        cout << "Introduceti nota la nota2: ";
        cin >> nota2;
        cout << "Introduceti nota la nota3: ";
        cin >> nota3;
    }
    Student(string name, string surrname, float nota11, float nota22, float nota33)
    {
        Name = name;
        Surrname = surrname;
        nota1 = nota11;
        nota2 = nota22;
        nota3 = nota33;

    }
    Student(float nota11, float nota22, float nota33)
    {
        nota1 = nota11;
        nota2 = nota22;
        nota3 = nota33;
    }
    Student(const Student &student1)
    {
        Name = student1.Name;
        Surrname = student1.Surrname;
        nota1 = student1.nota1;
        nota2 = student1.nota2;
        nota3 = student1.nota3;
        media = student1.media;
        //cout<<"Obiect copiat"<<endl;
    }
    ~Student()
    {
        // cout << "\nDestructor called" << endl;
    }
    void getName()
    {
        cout << "Introduceti numele si prenumele: ";
        cin >> Name >> Surrname;
    }
    float Average()
    {
        media = (nota1 + nota2 + nota3) / 3;
        cout << "Media este: " << media << endl;
        return media;
    }
    void Display()
    {
        cout << "\nPrenume: " << Surrname;
        cout << "\nNume: " << Name;
        cout << "\nNota nota1: " << nota1;
        cout << "\nNota nota2: " << nota2;
        cout << "\nNota nota3: " << nota3;
        cout << "\nMedia: " << media << "\n";
    }
};

int main()
{
    int i = 0;
    float media1, media2, media3, media4;

    Student student1;
    student1.Average();
    
    Student student2;
    student2.Average();
    
    Student student3;
    student3.Average();
    Student student4(student1);
    student4.Average();
    cout << "\nLista studentilor inainte de sortare:" << endl;
    student1.Display();
    student2.Display();
    student3.Display();
    student4.Display();
    vector<Student> sort_vect;
    sort_vect.push_back(student1);
    sort_vect.push_back(student2);
    sort_vect.push_back(student3);
    sort_vect.push_back(student4);
    sort(sort_vect.begin(), sort_vect.end(), [](const Student &a, const Student &b)
         { return (a.media > b.media) ; });
    cout << "\nLista studentilor dupa sortare: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << "\nNume:" << sort_vect[i].Name << endl;
        cout << "Prenume:" << sort_vect[i].Surrname << endl;
        cout << "Medie:" << setprecision(3)<< sort_vect[i].media << endl;
        cout << "\n";
    }
}
