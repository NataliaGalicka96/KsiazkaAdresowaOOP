#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}
void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}
int KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
        if (uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}
int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}
int KsiazkaAdresowa::wylogowanieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieUzytkownika();
}
char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    uzytkownikMenedzer.wybierzOpcjeZMenuGlownego();
}
char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    uzytkownikMenedzer.wybierzOpcjeZMenuUzytkownika();
}
bool KsiazkaAdresowa::sprawdzCzyUzytkownikJestZalogowany()
{
    uzytkownikMenedzer.sprawdzCzyUzytkownikJestZalogowany();
}
void KsiazkaAdresowa::dodajAdresata()
{

    adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    adresatMenedzer -> dodajAdresata();

}
void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    adresatMenedzer->wyswietlWszystkichAdresatow();
}
Adresat KsiazkaAdresowa::podajDaneNowegoAdresata()
{
    adresatMenedzer->podajDaneNowegoAdresata();
}
void KsiazkaAdresowa::wyswietlDaneAdresata(Adresat adresat)
{
    adresatMenedzer->wyswietlDaneAdresata(adresat);
}
void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    adresatMenedzer->wyszukajAdresatowPoImieniu();
}
void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    adresatMenedzer->wyszukajAdresatowPoNazwisku();
}
void KsiazkaAdresowa::usunAdresata()
{
    adresatMenedzer->usunAdresata();
}
void KsiazkaAdresowa::edytujAdresata()
{
    adresatMenedzer->edytujAdresata();
}
