#include "UserManager.h"

void UserManager::userRegistration() {
    User user = enterDataOfNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

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

void UserManager::loadUsersFromFile() {
    this->idLoggedUser = 0;
    users = fileWithUsers.loadUsersFromFile();
}

int UserManager::userLogin() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    cin >> login;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                cin >> password;

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    this->idLoggedUser = users[i].getId();
                    system("pause");
                    return users[i].getId();
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

/*
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
