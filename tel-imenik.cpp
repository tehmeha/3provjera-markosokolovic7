#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
    int i=0;
    int brojOsoba = 0;
    int izbor;
    int MAX = 50;
    string prezimeIme[MAX];
    string adresa[MAX];
    unsigned long long brTelefona[MAX];
    ofstream datotekaUpisivanje;
    ifstream datotekaUcitavanje;
    datotekaUcitavanje.open("imenik.txt");
    datotekaUcitavanje >> prezimeIme[i];
    datotekaUcitavanje >> brTelefona[i];
    datotekaUcitavanje >> adresa[i];

    while(1)
    {
        cout << "Glavni izbornik" << endl;
        cout << "1. Unos nove osobe" << endl;
        cout << "2. Ispisi sve podatke" << endl;
        cout << "3. Pretraga prema telefosnkom broju" << endl;
        cout << "4. Pretraga prema prezimenu i imenu" << endl;
        cout << "5. Izmjena podataka prema telefonskom broju" << endl;
        cout << "6. Ispisi sortirano prema prezimenu i imenu" << endl;
        cout << "7. Izlaz iz programa" << endl;
        cout << "Upisite broj iz izbornika: ";
        cin >> izbor;
        if( izbor == 1 )
        {
            cout << "Unesite ime i prezime: ";
            cin.ignore();
            getline(cin, prezimeIme[brojOsoba]);
            cout<<"Unesite broj telefona: ";
            cin>>brTelefona[brojOsoba];
            cout<<"Unesite adresu: ";
            cin.ignore();
            getline(cin,adresa[brojOsoba]);
             datotekaUpisivanje.open("imenik.txt", ios::app);
             datotekaUpisivanje<<prezimeIme[brojOsoba]<<endl;
            datotekaUpisivanje<<brTelefona[brojOsoba]<<endl;
            datotekaUpisivanje<<adresa[brojOsoba]<<endl;
            datotekaUpisivanje.close();
            brojOsoba++;
        }
        else if( izbor == 2 )
        {
            cout << "prezime i ime" << "\t" << "broj telefona" << "\t" << "adresa" << endl;
            for( int i = 0; i < brojOsoba; i++ )
            {
                cout << prezimeIme[i] <<"\t"<<brTelefona[i]<<"\t"<<adresa[i]<<endl;
            }

        }
        else if( izbor == 3 )
        {
            unsigned long long int brtelefona;
            cout<<"Upisite broj telefona: ";
            cin>>brtelefona;
            bool postoji=false;
            for(int i=0;i<brojOsoba;i++)
            {
                if(brtelefona==brTelefona[i])
                {
                    cout<<"Broj se nalazi u imeniku"<<endl;
                    cout << prezimeIme[i] <<"\t"<<brTelefona[i]<<"\t"<<adresa[i]<<endl;
                    postoji=true;
                    break;
                }
            }
            if(postoji==false)
                cout<<" nepostoji u imeniku!"<<endl;

        }
        else if( izbor == 4 )
        {
              string prezimeime;
            cout<<"Unesi Prezime I ime koje zelite pretraziti ";
            cin.ignore();
            getline(cin,prezimeime);
            cout<<endl<<prezimeime;
            bool postoji=false;
            for(int i=0;i<brojOsoba;i++)
            {
                if(prezimeime==prezimeIme[brojOsoba])
                {
                    cout<<"Osoba se nalazi u imeniku"<<endl;
                    cout << prezimeIme[i] <<"\t"<<brTelefona[i]<<"\t"<<adresa[i]<<endl;
                    postoji=true;
                    break;
                }
            }
            if(postoji==false)
                cout<<" nepostoji u imeniku!"<<endl;
        }
        else if( izbor == 5 )
        {
        }
        else if( izbor == 6 )
        {
            sort (prezimeIme,prezimeIme+brojOsoba);
            cout << "prezime i ime" << "\t" << "broj telefona" << "\t" << "adresa" << endl;
            for( int i = 0; i < brojOsoba; i++ )
            {
                cout << prezimeIme[i] <<"\t"<<brTelefona[i]<<"\t"<<adresa[i]<<endl;
            }
        }
        else if( izbor == 7 )
        {
            cout << "Kraj rada" << endl;
            break;
        }
        else
        {
            cout << "Unijeli ste krivi broj." << endl;
        }
        cout << endl;
    }
}
