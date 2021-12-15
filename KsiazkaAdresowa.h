#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "Uzytkownik.h"
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    //konstruktor z lista inicjalizacyjna
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami):uzytkownikMenedzer(nazwaPlikuZUzytkownikami){
    uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();
    int logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    int pobierzIdZalogowanegoUzytkownika();
    int wylogowanieUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    bool sprawdzCzyUzytkownikJestZalogowany();
};
#endif // KSIAZKAADRESOWA_H
