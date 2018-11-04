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
        cin.sync();
        getline(cin, login);
    } while (isExistLogin(login) == true);

    string password;
    cout << "Podaj haslo: ";
    cin.sync();
    getline(cin, password);

    string name;
    cout << "Podaj imie: ";
    cin.sync();
    getline(cin, name);

    string surname;
    cout << "Podaj nazwisko: ";
    cin.sync();
    getline(cin, surname);

    User user(id, login, password, AuxMethods::changeFirstLetterOnUpperRestOnLower(name), AuxMethods::changeFirstLetterOnUpperRestOnLower(surname));
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
    cin.sync();
    getline(cin, login);

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int attemptsNumber = 3; attemptsNumber > 0; attemptsNumber--) {
                cout << "Podaj haslo. Pozostalo prob: " << attemptsNumber << ": ";
                cin.sync();
                getline(cin, password);

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

void UserManager::passwordChangeLoggedUser(){
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    cin.sync();
    getline(cin, newPassword);

    for (int i = 0; i < users.size(); i++){
        if (users[i].getId() == idLoggedUser){
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

int UserManager::getIdLoggedUser(){
    return idLoggedUser;
}

int UserManager::userLogout(){
    this->idLoggedUser = 0;
}
