#include<iostream>
#include <string>
using namespace std;

class Coperta
{
   
    protected:
    string Titlu ="";
    string setTitlu()
    {
        cout <<"Introdu denumirea cartii:"<<endl;
        getline (cin >> ws,Titlu);
        return Titlu;
    }

    string getTitlu() const
    {
        cout << "Denumirea cartii:" << Titlu << endl;
        return Titlu ;
    }

};

class Autor
{
        protected:
        string nAuthor ="",fAuthor="";
        string setAuthor()
        {
            cout <<"Introdu numele autorului:"<<endl;
            getline (cin >> ws,nAuthor);
            cout <<"Introdu familia autorului:"<<endl;
            getline (cin >> ws,fAuthor);
            return nAuthor,fAuthor;
        }

        string getAuthor()const
        {
        cout << "Numele autorului:" << nAuthor << endl;
        cout << "Familia autorului:" << nAuthor << endl;
        return nAuthor,fAuthor ;
        }

};

class NrCapitole
{
protected:
       int nrCapitole=0;
        virtual int  setCapitole()
        {
            cout <<"Introdu numarul de capitole:"<<endl;
            cin >> nrCapitole;
            return nrCapitole;
        }
        
        virtual int  getCapitole() const
        {
            cout << "Numarul de capitole:" << nrCapitole << endl;
            return nrCapitole ;
        }

        virtual ~NrCapitole()
        {}
};

class FisaCarte:public Coperta,public Autor,virtual public NrCapitole
{   
    private:
    int nrP = 0 ;
    double pret = 0 ;
    string genul = "";
    string editura = "";
    public:
        void initialiare()
        {
            setTitlu();
            setAuthor();
            setCapitole();
            cout <<"Numar de pagini:"<<endl;
            cin >> nrP;
            cout <<"Pretul :"<<endl;
            cin >> pret;
            cout <<"Genul:"<<endl;
            cin >> genul;
            cout <<"Editura:"<<endl;
            cin >> editura;

        }
        void afisare()
        {
            getTitlu();
            getAuthor();
            getCapitole();
            cout<<"Numarul de pagini:"<<nrP<<endl;
            cout<<"Pretul:"<<pret<<endl;
            cout<<"Genul:"<<genul<<endl;
            cout<<"Editura:"<<editura<<endl;
        }
    FisaCarte() 
    :NrCapitole()
       
        {}
    virtual ~FisaCarte()
    {}

    void acum()
    {
        initialiare();
        afisare();
    }
};

// class Random : public FisaCarte
// {
//     public:
//         string setTitlu() 
//         {
//            return Titlu = "POO";
//         }
//          string getTitlu() 
//         {
//             cout <<"Denumirea cartii:"<<endl;
//            return Titlu ;
//         }

//         Random()
//          : FisaCarte()
//          {}
// };
int main()
    
    {
        FisaCarte* x1 = new FisaCarte();
        x1->acum();
        delete x1;


    }    

