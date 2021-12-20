#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;


class PlikZAdresatami
{
    int idOstatniegoAdresata;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    bool czyPlikJestPusty(fstream &plikTekstowy);

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPlikuZAdresatami):NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami){
    idOstatniegoAdresata=0;
    };

    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzZPlikuIdOstatniegoAdresata();


};
#endif // PLIKZADRESATAMI_H
