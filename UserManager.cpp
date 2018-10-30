#include "UserManager.h"

void UserManager::userRegistration() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterDataOfNewUser() {
    int id = getIdOfNewUser();

    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
    } while (isExistLogin(login) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;

    string name;
    cout << "Podaj imie: ";
    cin >> name;

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;

    User user(id, login, password, name, surname);
    return user;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isExistLogin(string login) {
    for (int i = 0; i < users.size(); i++) {
        if(users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

/*
void UzytkownikMenadzer::wypiszWszystkichUzytkownikow() {
    for (int i = 0; i < uzytkownicy.size(); i++) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenadzer::wczytajUzytkownikowZPliku(){
    this->idZalogowanegoUzytkownika = 0;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenadzer::logowanieUzytkownika(){
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;

                if (uzytkownicy[i].pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    this->idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    system("pause");
                    return uzytkownicy[i].pobierzId();
                }
            }
            cout << endl << "Wpisales 3 razy zle haslo." << endl;
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenadzer::zmianaHaslaZalogowanegoUzytkownika(){
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (int i = 0; i < uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika){
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzytkownikMenadzer::pobierzIdZalogowanegoUzytkownika(){
    return idZalogowanegoUzytkownika;
}

int UzytkownikMenadzer::wyloguj(){
    this->idZalogowanegoUzytkownika = 0;
}
*/
