#include "UzytkownikMenedzer.h"


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik; // funkcja tworzy uzytkownika

   // uzytkownik.id = pobierzIdNowegoUzytkownika(); //pobiera id uzytkownika, wiec musimy te funkcje tez zaimplementowac
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    //zmienna pomocnicza
    string login, haslo;
    do
    {
        cout <<  "Podaj login: ";
       // cin >>uzytkownik.login;
       //tworzê zmienn¹ pomocnicz¹
       cin>>login;
       uzytkownik.ustawLogin(login);

    } //while (czyIstniejeLogin(uzytkownik.login) == true);
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
        //return uzytkownicy.back().id + 1;
        return uzytkownicy.back().pobierzId()+1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
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
void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    //wykonujemy metode wczytajUzytkownikowZPLiku na obiekcie plikZUzytkownikai
       uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}




