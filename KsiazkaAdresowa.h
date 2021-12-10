#include <iostream>
#include <vector>

#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika; // w klasie nie ma inicjalizacji zmiennych, zmienne inicjalizujemy w konstruktorze
    int idOstatniegoAdresata ;
    int idUsunietegoAdresata ;

    vector <Uzytkownik> uzytkownicy;

public:
    //tworze metode rejestracja
    // rejestracja uzytkownika w naszym programie strukturalnym jako argument przyjmowala
    // wektor uzytkownicy, my rowniez bedziemy musieli stworzyc taki wektor
    //dodaj biblioteke <vector>
    // stworz klase Uzytkownik
    // dodaj klasê Uzytkonik #include "Uzytkownik.h"

    void rejestracjaUzytkownika();

};
