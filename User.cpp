#include "User.h"

User::User(int id, string login, string password, string name, string surname) {
    if (id > 0)
        this->id = id;
    else {
        cout << "ID nie moze byc mniejsze, badz rowne 0. Blad krytyczny - nastapi wyjscie z programu.";
        system("pause");
        exit(0);
    }

    this->login = login;
    this->password = password;
    this->name = name;
    this->surname = surname;
}

void User::setId(int newId) {
    if (newId >= 0)
        id = newId;
}

void User::setLogin(string newLogin) {
    login = newLogin;
}

void User::setPassword(string newPassword) {
    password = newPassword;
}

void User::setName(string newName) {
    name = newName;
}

void User::setSurname(string newSurname) {
    surname = newSurname;
}

int User::getId() {
    return id;
}

string User::getLogin() {
    return login;
}

string User::getPassword() {
    return password;
}

string User::getName() {
    return name;
}

string User::getSurname() {
    return surname;
}

