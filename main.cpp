#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct uczen
{
        string imie, nazwisko, adres, PESEL;
        int numer;
};

class klasa
{
        vector <struct uczen> spis;

        public:
                void wprowadz();
                void wypisz();
                void zapiszDoPliku(const char *);
                void wczytajZPliku(const char *);
};

void klasa::wprowadz()
{
        int iloscUczniow;
        struct uczen wprowadzany;
        cout << "Ilosc uczniow: ";
        cin  >> iloscUczniow;
        for (int i=0; i<iloscUczniow; i++)
        {
                cout << "Nr Imie Nazwisko: ";
                cin >> wprowadzany.numer
                        >> wprowadzany.imie
                        >> wprowadzany.nazwisko
                        >> wprowadzany.adres
                        >> wprowadzany.PESEL;
                spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord
        }
}


void klasa::wypisz()
{
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                cout << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
                         << it->adres << " "
                         << it->PESEL << "\n";
        }
}



void klasa::zapiszDoPliku(const char *nazwa)
{
        ofstream plik;
        plik.open(nazwa);
        for (vector<struct uczen>::iterator it = spis.begin(); it != spis.end(); ++it)
        {
                plik << it->numer << " "
                         << it->imie << " "
                         << it->nazwisko << " "
                         << it->adres << " "
                         << it->PESEL << "\n";
        }
        plik.close();
}


void klasa::wczytajZPliku(const char *nazwa) {


    struct uczen wprowadzany;

    ifstream plik("a.txt");

    int numer;
    string imie, nazwisko, adres, PESEL;
    while (plik >> numer >> imie >> nazwisko >> adres >> PESEL)
    {
        wprowadzany.numer = numer;
        wprowadzany.imie = imie;
        wprowadzany.nazwisko = nazwisko;
        wprowadzany.adres = adres;
        wprowadzany.PESEL = PESEL;

        spis.push_back(wprowadzany); //TU WSTAW do tablicy nowy rekord

        /* do something with name, var1 etc. */
        cout<<"Odczytano 1 linie: \n";
        cout << numer << " " << imie << " " << nazwisko << " " << adres << " " << PESEL << "\n";
    }

    plik.close();
}



int main(int argc, char** argv) {
        klasa TI;
        //TI.wprowadz();
        //TI.wypisz();
        //TI.zapiszDoPliku("a.txt");



        while(1) {
            cout<<"=====Menu=====\n1. Wprowadz\n2. Wypisz\n3. Zapisz do pilku\n4. Wczytaj z pliku\n\n";
            char wybor;
            wybor = getch();

            switch(wybor) {
                case '1':
                    //system("CLS");
                    TI.wprowadz();
                break;
                case '2':
                    //system("CLS");
                    TI.wypisz();
                break;
                case '3':
                    //system("CLS");
                    TI.zapiszDoPliku("a.txt");
                break;
                case '4':
                    //system("CLS");
                    TI.wczytajZPliku("a.txt");
                break;
            }
        }




        return 0;
}
