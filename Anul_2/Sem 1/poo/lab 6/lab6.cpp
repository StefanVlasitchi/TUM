#include "bits/stdc++.h"
#include <iostream>
#include <fstream>
#include<direct.h>

using namespace std;
ofstream outfile;
ifstream infile;
fstream file;
string numele_persoanei,numele_albumului,name_of_person[100],name_of_album[100],nickname_of_album;
int pozitia_album,pozitia_track,numarul_de_albume,inceputul, sfarsitul,secunde,s[100],anul_aparitie[100],numarul_de_track[100],an,number_of_track,cautare[100],z=0,timp;
const char *artist="D:/Universitate/Anul 2/Sem 1/poo/lab6/Artisti";

template<class T>
T correct_input(const string&  prompt)
{
    for(;;)
    {
        cout << prompt;
        string  str_val;
        cin >> str_val;
        istringstream  ssin(str_val);
        T  val;
        if(ssin >> val)
        {
            std::string  tmp;
            if(!(ssin >> tmp))
                return  val;
            else
                cout << "Eroare! Trebuie sa fie un numar intreg! Mai introduceti inca o data" << endl;
        }
        else
            cout << "Eroare! Trebuie sa fie un numar intreg! Mai introduceti inca o data" << endl;
    }
};

class Track
{
private:
    string nume_track;
    int pozitia;
    int durata;
public:
    void citire_track();
    void afis_track();
    void delete_track();
    void schimbare_track();
    void c_m_lung_album();
};
void Track ::citire_track()
{
    cout<<"Introduceti numele track-lui: ";
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/" + numele_albumului;
    const char*result1 = combined1.c_str();
    cin>>nume_track;
    string combined2 = string(result1) + "/" + nume_track;
    const char*result2 = combined2.c_str();
    mkdir(result2);
    string combined3 = string(result2) + "/Informatie.txt";
    const char* informatie = combined3.c_str();
    outfile.open(informatie);
    pozitia = correct_input<int>("Introduceti pozitia din album: ");
    while(pozitia<=0)
    {
        cout<<"Pozitia nu poate fi mai mica ca 0!"<<endl;
        pozitia = correct_input<int>("Introduceti din nou pozitia din album: ");
    }
    outfile << pozitia <<endl;
    durata = correct_input<int>("Introduceti durata: ");
    while(durata<=0)
    {
        cout<<"Durata nu poate fi mai mica sau egala ca 0!"<<endl;
        durata = correct_input<int>("Introduceti din nou durata track-lui: ");
    }
    outfile << durata <<endl;
    outfile.close();
}

void Track::afis_track()
{
    cout<<"Nume track - "<<nume_track<<endl;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/" + numele_albumului;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/" + nume_track;
    const char*result2 = combined2.c_str();
    mkdir(result2);
    string combined3 = string(result2) + "/Informatie.txt";
    const char* informatie = combined3.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            cout<<"Pozitia in album - ";
        else
            cout<<"Durata - ";
        cout << myText<<endl;
        k++;
    }
    infile.close();
}

void Track::delete_track()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/" + numele_albumului;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/" + nume_track;
    const char*result2 = combined2.c_str();
    mkdir(result2);
    string combined3 = string(result2) + "/Informatie.txt";
    const char* informatie = combined3.c_str();
    char *modificare=(char*)informatie;
    char *modificare1=(char*)result2;
    //remove( informatie );
    if( remove( informatie ) != 0 )
        perror( "Error deleting file. Inchideti mai intai fisierul" );
    else
        puts( "File successfully deleted" );
    rmdir( modificare1 );
}
void Track::schimbare_track()
{
    string new_name;
    cout<<"Numele vechi - "<<nume_track<<endl;
    cout<<"Introduceti noul nume - ";
    cin>>new_name;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/" + numele_albumului;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/" + nume_track;
    const char*result2 = combined2.c_str();
    mkdir(result2);
    string combined3 = string(result2) + "/Informatie.txt";
    const char* informatie = combined3.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Pozitia veche in album - ";
            cout << myText<<endl;
            int new_position;
            new_position=correct_input<int>("Introduceti pozitia noua in album - ");
            while(new_position<=0)
            {
                cout<<"Pozitia nu poate fi mai mica ca 0!"<<endl;
                new_position = correct_input<int>("Introduceti din nou pozitia din album: ");
            }
            pozitia=new_position;
        }
        else
        {
            cout<<"Durata de track-uri - ";
            cout << myText<<endl;
            int new_durata;
            new_durata=correct_input<int>("Introduceti durata noua a track-ului - ");
            while(new_durata<=0)
            {
                cout<<"Durata nu poate fi mai mica sau egala ca 0!"<<endl;
                new_durata = correct_input<int>("Introduceti din nou durata track-lui: ");
            }
            durata=new_durata;
        }
        k++;
    }
    infile.close();
    remove( informatie );

    ofstream outfile (informatie);
    outfile << pozitia <<endl;
    outfile << durata <<endl;
    outfile.close();
    combined3 = string(result1) + "/" + new_name;
    const char* result3 = combined3.c_str();
    char *modificare1=(char*)result1;
    rename(result2,result3);
    cout<<"Old name of Track = "<<result1<<endl;
    cout<<"New name of Track = "<<result2<<endl;
    nume_track=new_name;
}
void Track::c_m_lung_album()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/" + numele_albumului;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/" + nume_track;
    const char*result2 = combined2.c_str();
    mkdir(result2);
    string combined3 = string(result2) + "/Informatie.txt";
    const char* informatie = combined3.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            pozitia=stoi(myText);
        else
            durata=stoi(myText);
        k++;
    }
    infile.close();
    secunde+=durata;
}

class Album:public Track
{
protected:
    string nume_album;
    int an_aparitie;
    int nr_track;
    Track *track[100];
public:
    void citire_album();
    void afisare_album();
    void afisare_albumulelor_persoanei_dorite();
    void afisare_albumulelor_persoanei_cronologice();
    void introducerea_datelor_cronologice();
    void schimbare_album();
    void stergere_album();
    void afisarea_track_dorite();
    void adaugare_track();
    void remove_track();
    void editare_track();
    void search_album();
    void search_album_1();
    void s_long_album();
    void introducere_c_m_l_album();
};

void Album::citire_album()
{
    cout<<"Introduceti numele albumului: ";
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    cin>>nume_album;
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    mkdir(result1);
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    outfile.open(informatie);
    an_aparitie = correct_input<int>("Introduceti anul aparitiei: ");
    while(an_aparitie<=1990 || an_aparitie>=2022)
    {
        cout<<"Dati un an al aparitie intre 1990-2022!"<<endl;
        an_aparitie = correct_input<int>("Introduceti din nou anul aparitie albumului: ");
    }
    outfile << an_aparitie <<endl;
    nr_track = correct_input<int>("Introduceti numarul de track-uri din album: ");
    while(nr_track<=0 || nr_track>=20)
    {
        cout<<"Dati un numar de track-uri intre 1-20!"<<endl;
        nr_track = correct_input<int>("Introduceti din nou numarul de track-uri: ");
    }
    outfile << nr_track <<endl;
    outfile.close();
    for(int i=0; i<nr_track; i++)
    {
        cout<<"Introduceti datele despre track-ul "<<i+1<<endl;
        track[i]=new Track;
        track[i]->citire_track();
    }
}

void Album::afisare_album()
{
    cout<<"Numele - "<<nume_album<<endl;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            cout<<"Anul aparitiei - ";
        else
            cout<<"Numarul de track-uri - ";
        cout << myText<<endl;
        k++;
    }
    infile.close();
    for(int i=0; i<nr_track; i++)
    {
        cout<<"Track-ul "<<i+1<<endl;
        track[i]->afis_track();
    }
}

void Album::afisare_albumulelor_persoanei_dorite()
{
    cout<<"Numele - "<<nume_album<<endl;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Anul aparitiei - ";
            cout << myText<<endl;
            an=stoi(myText);
        }
        else
        {
            cout<<"Numarul de track-uri - ";
            cout << myText<<endl;
            number_of_track=stoi(myText);
        }
        k++;
    }
    infile.close();
}

void Album::afisare_albumulelor_persoanei_cronologice()
{
    cout<<"Numele - "<<nume_album<<endl;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Anul aparitiei - ";
            cout << myText<<endl;
            an_aparitie=stoi(myText);
            an=an_aparitie;
        }
        else
        {
            cout<<"Numarul de track-uri - ";
            cout << myText<<endl;
        }
        k++;
    }
    infile.close();
}

void Album::introducerea_datelor_cronologice()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            an_aparitie=stoi(myText);
            an=an_aparitie;
        }
        else
        {
            nr_track=stoi(myText);
            number_of_track=nr_track;
        }
        k++;
    }
    infile.close();
}


void Album::afisarea_track_dorite()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            an_aparitie=stoi(myText);
        }
        else
        {
            nr_track=stoi(myText);
        }
        k++;
    }
    infile.close();
    for(int i=0; i<nr_track; i++)
    {
        cout<<"\nTrack-ul "<<i+1<<endl;
        track[i]->afis_track();
    }
}
void Album::schimbare_album()
{
    string new_name;
    cout<<"Numele vechi - "<<nume_album<<endl;
    cout<<"Introduceti noul nume - ";
    cin>>new_name;
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Anul aparitiei vechi - ";
            cout << myText<<endl;
            int new_an;
            new_an=correct_input<int>("Introduceti noul an al aparitiei - ");
            while(new_an<=1990 || new_an>=2022)
            {
                cout<<"Dati un an al aparitie intre 1990-2022!"<<endl;
                new_an = correct_input<int>("Introduceti din nou anul aparitie albumului: ");
            }
            an_aparitie=new_an;
        }
        else
        {
            cout<<"Numarul de track-uri - ";
            cout << myText<<endl;
            nr_track=stoi(myText);
        }
        k++;
    }
    infile.close();
    remove( informatie );
    ofstream outfile (informatie);
    outfile << an_aparitie <<endl;
    outfile << nr_track <<endl;
    outfile.close();
    string combined3 = string(result) + "/" + new_name;
    const char*result2 = combined3.c_str();
    char *modificare1=(char*)result1;
    rename(result1,result2);
    nume_album=new_name;

}

void Album::stergere_album()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    remove( informatie );
    for(int i=0; i<nr_track; i++)
    {
        track[i]->delete_track();
    }
    rmdir( modificare );
}

void Album::adaugare_track()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    cout<<"Cate track-uri doriti sa adaugati?"<<endl;
    int n;
    n=correct_input<int>("Optiune - ");
    int m=nr_track+n;
    for(int i=nr_track; i<m; i++)
    {
        track[i]=new Track;
        track[i]->citire_track();
    }
    nr_track=nr_track+n;
    remove(informatie);
    outfile.open(informatie);
    outfile << an_aparitie <<endl;
    outfile << nr_track <<endl;
    outfile.close();
}
void Album::remove_track()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    track[pozitia_track-1]->delete_track();
    int i=pozitia_track-1;
    for(i; i<nr_track; i++)
    {
        track[i]=track[i+1];
    }
    //delete track[nr_track];
    nr_track--;
    cout<<"Numarul de track-uri "<<nr_track<<endl;
    remove(informatie);
    outfile.open(informatie);
    outfile << an_aparitie <<endl;
    outfile << nr_track <<endl;
    outfile.close();
}
void Album::editare_track()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    track[pozitia_track-1]->schimbare_track();
}
void Album::search_album()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            an_aparitie=stoi(myText);
            an=an_aparitie;
        }
        else
        {
            nr_track=stoi(myText);
            number_of_track=nr_track;
        }
        k++;
    }
    infile.close();
    if(inceputul<=an_aparitie && an_aparitie<=sfarsitul)
    {
        cout<<"Numele artistului - "<<numele_persoanei<<endl;
        cout<<"Nume - "<<nume_album<<endl;
        cout<<"Anul aparitiei - "<<an_aparitie<<endl;
        cout<<"Numarul de track-uri - "<<nr_track<<endl<<endl;
    }
}
void Album::search_album_1()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            an_aparitie=stoi(myText);
            an=an_aparitie;
        }
        else
        {
            nr_track=stoi(myText);
            number_of_track=nr_track;
        }
        k++;
    }
    infile.close();
    ostringstream str1,str2;
    str1<<inceputul;
    string geek = str1.str();
    str2<<sfarsitul;
    string geek1 = str2.str();
    string combined3 = string(artist) + "/"+geek+"-"+geek1+".txt";
    const char*informatie1 = combined3.c_str();
    outfile.open(informatie1,ofstream::app);
    if(inceputul<=an_aparitie && an_aparitie<=sfarsitul)
    {
        outfile<<"Numele artistului - "<<numele_persoanei<<endl;
        outfile<<"Nume - "<<nume_album<<endl;
        outfile<<"Anul aparitiei - "<<an<<endl;
        outfile<<"Numarul de track-uri - "<<number_of_track<<endl<<endl;
    }
    outfile.close();
    if(inceputul<=an_aparitie && an_aparitie<=sfarsitul)
    {
        cout<<"Numele artistului - "<<numele_persoanei<<endl;
        cout<<"Nume - "<<nume_album<<endl;
        cout<<"Anul aparitiei - "<<an_aparitie<<endl;
        cout<<"Numarul de track-uri - "<<nr_track<<endl;
    }
}
void Album::s_long_album()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    for(int i=0; i<nr_track; i++)
    {
        track[i]->c_m_lung_album();
    }
}

void Album::introducere_c_m_l_album()
{
    const char* str = numele_persoanei.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    numele_albumului=nume_album;
    string combined1 = string(result) + "/" + nume_album;
    const char*result1 = combined1.c_str();
    char *modificare=(char*)result1;
    string combined2 = string(result1) + "/Informatie.txt";
    const char* informatie = combined2.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            an_aparitie=stoi(myText);
        else
            nr_track=stoi(myText);
        k++;
    }
    infile.close();
    string combined3 = string(result) + "/CMLAlbum.txt";
    const char*informatie1 = combined3.c_str();
    outfile.open(informatie1);
    outfile<<"Artistul - "<<numele_persoanei<<endl;
    outfile<<"Nume album - "<<nume_album<<endl;
    outfile<<"Anul aparitiei - "<<an_aparitie<<endl;
    outfile<<"Numarul de track-uri - "<<nr_track<<endl;
    outfile<<"Timpul este de "<<timp<<" secunde"<<endl;
    outfile.close();
}

class Persoana:public Album
{
protected:
    string nume_persoana;
    int varsta;
    int nr_albume;
    Album *album[100];
public:
    void citire_persoana();
    void afisare_persoana();
    void afisare_artisti();
    void afisare_persoana_dorita();
    void afisare_persoana_cronologic();
    void adaugare_album();
    void editare_album();
    void remove_album();
    void afisare_album_dorit();
    void cautare_album();
    void find_album();
    void introducere_album_gasit();
    void c_lung_album();
};

void Persoana::citire_persoana()
{
    cout<<"Introduceti numele artistului: ";
    cin>>nume_persoana;
    numele_persoanei=nume_persoana;
    const char* str = nume_persoana.c_str();
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    mkdir(result);
    string combined1 = string(result) + "/Informatie.txt";
    const char* informatie = combined1.c_str();
    outfile.open(informatie);
    varsta = correct_input<int>("Introduceti varsta: ");
    while(varsta<=0 || varsta>=90)
    {
        cout<<"Dati o varsta intre 0-90!"<<endl;
        varsta = correct_input<int>("Introduceti din nou varsta artistului: ");
    }
    outfile << varsta <<endl;
    nr_albume = correct_input<int>("Introduceti numarul de albume: ");
    while(nr_albume<=0 || nr_albume>=10)
    {
        cout<<"Dati un numar de albume intre 1-10!"<<endl;
        varsta = correct_input<int>("Introduceti din nou numarul de albume ale artistului: ");
    }
    outfile << nr_albume <<endl;
    outfile.close();
    for(int i=0; i<nr_albume; i++)
    {
        cout<<"Introduceti datele despre albumul "<<i+1<<endl;
        album[i]=new Album;
        album[i]->citire_album();
    }
}

void Persoana::afisare_persoana()
{
    cout<<"Nume - "<<nume_persoana<<endl;
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            cout<<"Varsta - ";
        else
            cout<<"Numarul de albume - ";
        cout << myText<<endl;
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
    {
        cout<<"\nAlbumul "<<i+1<<endl;
        album[i]->afisare_album();
    }
}

void Persoana::afisare_persoana_dorita()
{
    cout<<"Nume - "<<nume_persoana<<endl;
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            cout<<"Varsta - ";
        else
            cout<<"Numarul de albume - ";
        cout << myText<<endl;
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
    {
        cout<<"\nAlbumul "<<i+1<<endl;
        album[i]->afisare_albumulelor_persoanei_dorite();
    }
}


void Persoana::afisare_persoana_cronologic()
{
    cout<<"Nume - "<<nume_persoana<<endl;
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Varsta - ";
            cout<<myText<<endl;
            varsta=stoi(myText);
        }
        else
        {
            cout<<"Numarul de albume - ";
            cout << myText<<endl;
            nr_albume=stoi(myText);
        }
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
    {
        cout<<"\nAlbumul "<<i+1<<endl;
        album[i]->afisare_albumulelor_persoanei_cronologice();
        anul_aparitie[i]=an;
    }
    Album *auxiliar;
    auxiliar=new Album;
    for(int i = 0 ; i < nr_albume - 1 ; i ++)
        for(int j = i + 1 ; j < nr_albume ; j ++)
            if(anul_aparitie[i] > anul_aparitie[j])
            {
                int aux = anul_aparitie[i];
                anul_aparitie[i] = anul_aparitie[j];
                anul_aparitie[j] = aux;
                auxiliar = album[i];
                album[i] = album[j];
                album[j] = auxiliar;
            }
    string combined2 = string(result) + "/AlbumeSortate.txt";
    const char*informatie1 = combined2.c_str();
    outfile.open(informatie1);
    for(int i=0; i<nr_albume; i++)
    {
        album[i]->introducerea_datelor_cronologice();
        outfile<<"Nume - "<<numele_albumului<<endl;
        outfile<<"An aparitie - "<<an<<endl;
        outfile<<"Numarul de track-uri - "<<number_of_track<<endl<<endl;
    }
    outfile.close();
}

void Persoana::afisare_album_dorit()
{
    cout<<"Nume - "<<nume_persoana<<endl;
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
        {
            cout<<"Varsta - ";
            cout << myText<<endl;
            varsta=stoi(myText);
        }
        else
        {
            cout<<"Numarul de albume - ";
            cout << myText<<endl;
            nr_albume=stoi(myText);
        }
        k++;
    }
    infile.close();
    cout<<"\nAfisarea albumelor artistului dorit"<<endl;
    for(int i=0; i<nr_albume; i++)
    {
        cout<<"\nAlbumul "<<i+1<<endl;
        album[i]->afisare_albumulelor_persoanei_dorite();
    }
    cout<<"In care album doriti sa efectuati modificari?"<<endl;
    int n;
    n=correct_input<int>("Optiune - ");
    album[n-1]->afisarea_track_dorite();
    int option;
    printf("\nCe doriti sa modificati?\n");
    printf("1. Vreau sa adaug track-uri\n");
    printf("2. Vreau sa modific un track.\n");
    printf("3. Vreau sa sterg un track.\n");
    option=correct_input<int>("\nOptiunea - ");;
    switch (option)
    {
    case 1:
        album[n-1]->adaugare_track();
        break;
    case 2:
        cout<<"Care track doiriti sa-l modificati?"<<endl;
        pozitia_track=correct_input<int>("Optiune - ");
        album[n-1]->editare_track();
        break;
    case 3:
        cout<<"Care track doiriti sa-l stergeti?"<<endl;
        pozitia_track=correct_input<int>("Optiune - ");
        album[n-1]->remove_track();
        break;
    }
}

void Persoana::afisare_artisti()
{
    cout<<"Nume - "<<nume_persoana<<endl;
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            cout<<"Varsta - ";
        else
            cout<<"Numarul de albume - ";
        cout << myText<<endl;
        k++;
    }
    infile.close();
}

void Persoana::adaugare_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    cout<<"Cate albume doriti sa adaugati?"<<endl;
    int n;
    n=correct_input<int>("Optiune - ");
    int m=nr_albume+n;
    for(int i=nr_albume; i<m; i++)
    {
        album[i]=new Album;
        album[i]->citire_album();
    }
    nr_albume=nr_albume+n;
    remove(informatie);
    outfile.open(informatie);
    outfile << varsta <<endl;
    outfile << nr_albume <<endl;
    outfile.close();
}

void Persoana::editare_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    album[pozitia_album-1]->schimbare_album();
}
void Persoana::remove_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    album[pozitia_album-1]->stergere_album();
    int i=pozitia_album-1;
    for(i; i<nr_albume; i++)
    {
        album[i]=album[i+1];
    }
    delete album[nr_albume];
    nr_albume--;
    cout<<"Numarul de albume "<<nr_albume<<endl;
    remove(informatie);
    outfile.open(informatie);
    outfile << varsta <<endl;
    outfile << nr_albume <<endl;
    outfile.close();

}
void Persoana::cautare_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
        cautare[i]=-1;
    for(int i=0; i<nr_albume; i++)
    {
        album[i]->search_album();
        if(inceputul<=an && an<=sfarsitul)
        {
            cautare[i]=i;
        }
    }
    ostringstream str1,str2;
    str1<<inceputul;
    string geek = str1.str();
    str2<<sfarsitul;
    string geek1 = str2.str();
    string combined2 = string(result) + "/"+geek+"-"+geek1+".txt";
    const char*informatie1 = combined2.c_str();
    outfile.open(informatie1);
    for(int i=0; i<nr_albume; i++)
    {
        if(cautare[i]!=-1)
        {
            album[i]->introducerea_datelor_cronologice();
            outfile<<"Nume artist - "<<nume_persoana<<endl;
            outfile<<"Nume - "<<numele_albumului<<endl;
            outfile<<"An aparitie - "<<an<<endl;
            outfile<<"Numarul de track-uri - "<<number_of_track<<endl<<endl;
        }
    }
    outfile.close();
}

void Persoana::find_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
        cautare[i]=-1;
    for(int i=0; i<nr_albume; i++)
    {
        album[i]->search_album_1();
    }
}

void Persoana::c_lung_album()
{
    const char* str = nume_persoana.c_str();
    numele_persoanei=nume_persoana;
    string combined = string(artist) + str;
    const char*result = combined.c_str();
    string combined1 = string(result) + "/Informatie.txt";
    const char*informatie = combined1.c_str();
    infile.open(informatie);
    string myText;
    int k=0;
    while (getline (infile, myText))
    {
        if (k==0)
            varsta=stoi(myText);
        else
            nr_albume=stoi(myText);
        k++;
    }
    infile.close();
    for(int i=0; i<nr_albume; i++)
    {
        secunde=0;
        album[i]->s_long_album();
        s[i]=secunde;
    }
    Album *auxiliar;
    auxiliar=new Album;
    for(int i = 0 ; i < nr_albume - 1 ; i ++)
        for(int j = i + 1; j < nr_albume ; j ++)
            if(s[i] > s[j])
            {
                int aux = s[i];
                s[i] = s[j];
                s[j] = aux;
                auxiliar = album[i];
                album[i] = album[j];
                album[j] = auxiliar;
            }
    cout<<"Artistul "<<nume_persoana<<endl;
    cout<<"Datele despre albumul cel mai lung"<<endl;
    album[nr_albume-1]->afisare_albumulelor_persoanei_dorite();
    cout<<"Timpul este de "<<s[nr_albume-1]<<endl;
    for(int i=0; i<nr_albume; i++)
        //cout<<s[i]<<" ";
        cout<<endl;
    timp=s[nr_albume-1];
    album[nr_albume-1]->introducere_c_m_l_album();
}


Persoana *persoana[100];
int n;

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
    printf("\n1. Introduceti date despre artist.");
    printf("\n2. Afisarea informatiei.");
    printf("\n3. Modificarea unui album al unui artist.");
    printf("\n4. Modificarea unui track din album.");
    printf("\n5. Afisarea in ordine cronologica.");
    printf("\n6. Cautarea unui album dupa perioade.");
    printf("\n7. Cautarea celui mai lung album al fiecarui artist.");
    printf("\n0. Iesire.");
    fflush(stdin);
    int opt=correct_input<int>("\nOptiunea - ");
    *m=opt;
}

void citire()
{
    n=correct_input<int>("Introduceti numarul de artisti - ");;
    for(int i=0; i<n; i++)
    {
        cout<<"Introduceti datele depsre artistul "<<i+1<<endl;
        persoana[i]=new Persoana;
        persoana[i]->citire_persoana();
    }
}
void afisare()
{
    cout<<"\n\nAfisarea datelor"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nDatele despre artistul "<<i+1<<endl;
        persoana[i]->afisare_persoana();
    }
}
void afisare_album(int a)
{
    cout<<"\n\nAfisarea interpretului dorit"<<endl;
    persoana[a]->afisare_persoana_dorita();
}
void afisare_album_cronologic(int a)
{
    cout<<"\n\nAfisarea interpretului dorit cronologic"<<endl;
    persoana[a]->afisare_persoana_cronologic();
}
void afisare_track(int a)
{
    int i=a;
    persoana[a]->afisare_album_dorit();
}

void modificare_album()
{
    int option;
    int k;
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nDatele despre artistul "<<i+1<<endl;
        persoana[i]->afisare_artisti();
    }
    cout<<"La care artist doriti sa efectuati modificari?"<<endl;
    k = correct_input<int>("Optiune - ");
    afisare_album(k-1);
    printf("\nCe doriti sa modificati?\n");
    printf("1. Vreau sa adaug albumuri\n");
    printf("2. Vreau sa modific un album.\n");
    printf("3. Vreau sa sterg un album.\n");
    option=correct_input<int>("\nOptiunea - ");;
    switch (option)
    {
    case 1:
        persoana[k-1]->adaugare_album();
        break;
    case 2:
        cout<<"Care album doiriti sa-l modificati?"<<endl;
        pozitia_album=correct_input<int>("Optiune - ");
        persoana[k-1]->editare_album();
        break;
    case 3:
        cout<<"Care album doiriti sa-l stergeti?"<<endl;
        pozitia_album=correct_input<int>("Optiune - ");
        persoana[k-1]->remove_album();
        break;
    }
}
void modificare_track()
{
    int option;
    int k;
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nDatele despre artistul "<<i+1<<endl;
        persoana[i]->afisare_artisti();
    }
    cout<<"La care artist doriti sa efectuati modificari?"<<endl;
    k = correct_input<int>("Optiune - ");
    afisare_track(k-1);
}
void cronologie()
{
    int k;
    for(int i=0; i<n; i++)
    {
        cout<<"\n\nDatele despre artistul "<<i+1<<endl;
        persoana[i]->afisare_artisti();
    }
    cout<<"La care artist doriti sa efectuati modificari?"<<endl;
    k = correct_input<int>("Optiune - ");
    afisare_album_cronologic(k-1);
}
void search_perioada()
{
    cout<<"Introduceti perioada dorita!"<<endl;
    inceputul=correct_input<int>("Inceptul - ");
    sfarsitul=correct_input<int>("Sfarsitul - ");
    int option;
    int k;
    printf("\nCe doriti sa gaseasca?\n");
    printf("1. Albumele unui artist anume in perioada introdusa?\n");
    printf("2. Albumele tuturor artistilor in perioada introdusa?\n");
    option = correct_input<int>("Optiune - ");
    switch (option)
    {
    case 1:
        for(int i=0; i<n; i++)
        {
            cout<<"\n\nDatele despre artistul "<<i+1<<endl;
            persoana[i]->afisare_artisti();
        }
        cout<<"La care artist doriti sa gasiti albumele?"<<endl;
        k = correct_input<int>("Optiune - ");
        persoana[k-1]->cautare_album();
        break;
    case 2:
        for(int i=0; i<n; i++)
        {
            persoana[i]->find_album();
        }
        break;
    }

}
void cel_mai_lung_album()
{
    for(int i=0; i<n; i++)
    {
        persoana[i]->c_lung_album();
    }
}
int main()
{
    int m;
    do
    {
        Menu(&m);
        switch (m)
        {
        case 1:
            citire();
            break;
        case 2:
            afisare();
            break;
        case 3:
            modificare_album();
            break;
        case 4:
            modificare_track();
            break;
        case 5:
            cronologie();
            break;
        case 6:
            search_perioada();
            break;
        case 7:
            cel_mai_lung_album();
            break;
        default:
            break;
        }
    }
    while (m);
    for(int i=0; i<n; i++)
    {
        delete persoana[i];
    }
}
