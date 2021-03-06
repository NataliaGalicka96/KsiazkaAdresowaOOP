#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika()
{


    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    Sleep(2000);

}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login, haslo;
    do
    {

        system("cls");
        cout<<">>> REJESTRACJA UZYTKOWNIKA <<<"<<endl<<endl;
        //
        cout <<  "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login);

    }
    while(czyIstniejeLogin(uzytkownik.pobierzLogin())==true);

    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId()+1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {

            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            Sleep(3000);
            system("cls");
            return true;
        }

    }
    return false;

}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for(int i=0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;

    }
}


int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";


    system("cls");
    cout<<">>> LOGOWANIE UZYTKOWNIKA <<<"<<endl;

    cout << endl << "Podaj login: ";
    cin>>login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    while (itr != uzytkownicy.end())
    {
        if (itr -> pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin>>haslo;

                if (itr -> pobierzHaslo() == haslo)
                {
                    idZalogowanegoUzytkownika = itr -> pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    Sleep(2000);
                   // return 0;
                   return idZalogowanegoUzytkownika;

                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;

            Sleep(3000);
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{

    system("cls");
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin>> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        //if (itr -> pobierzId() == pobierzIdZalogowanegoUzytkownika())
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");

        }
    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    zapiszWszystkichUzytkownikowDoPliku();
}
void UzytkownikMenedzer::zapiszWszystkichUzytkownikowDoPliku()
{
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}
char UzytkownikMenedzer::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char UzytkownikMenedzer::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}
void UzytkownikMenedzer::wylogowanieUzytkownika()
{
    idZalogowanegoUzytkownika=0;
}

bool UzytkownikMenedzer::sprawdzCzyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}






