#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    int idZalogowanegoUzytkownika = 0;
    int idOstatniegoAdresata = 0;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");
    char wybor;
    while (true)
    {

        if (idZalogowanegoUzytkownika == 0)
        {
            cin.sync();
            wybor=ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                idZalogowanegoUzytkownika=ksiazkaAdresowa.logowanieUzytkownika();
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
                idOstatniegoAdresata = ksiazkaAdresowa.dodajAdresata(idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                //ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                //ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':

                ksiazkaAdresowa.wyswietlWszystkichAdresatow(idZalogowanegoUzytkownika);
                break;
            case '5':
                //ksiazkaAdresowa.usunAdresata();
                break;
            case '6':
                //ksiazkaAdresowa.edytujAdresata();
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika(idZalogowanegoUzytkownika);
                break;
            case '8':
                idZalogowanegoUzytkownika=ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
    return 0;
}
