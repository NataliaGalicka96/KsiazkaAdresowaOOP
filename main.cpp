#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    char wybor;

    while (true)
    {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0)
        {
            cin.sync();
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            cin.sync();
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor)
            {
            case '1':
               // ksiazkaAdresowa.dodajAdresata();
                break;
            case '2':
               // ksiazkaAdresowa.wyszukajAdresataPoImieniu();
                break;
            case '3':
               // ksiazkaAdresowa.wyszukajAdresataPoNazwisku();
                break;
            case '4':
                //ksiazkaAdresowa.listaAdresatow();
                break;
            case '5':
               // ksiazkaAdresowa.usuniecieAdresata();
                break;
            case '6':
               // ksiazkaAdresowa.edycjaAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
