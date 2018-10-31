#include "Income.h"

Income::Income(int incomeId, int userId, int date, string item, double amount) {
    if (incomeId > 0)
        this->incomeId = incomeId;
    else {
        cout << "ID nie moze byc mniejsze, badz rowne 0. Blad krytyczny - nastapi wyjscie z programu.";
        system("pause");
        exit(0);
    }

    if (userId > 0)
        this->userId = userId;
    else {
        cout << "ID nie moze byc mniejsze, badz rowne 0. Blad krytyczny - nastapi wyjscie z programu.";
        system("pause");
        exit(0);
    }

    if (date > 0)
        this->date = date;
    else {
        cout << "Szkoda, ze nie mozna cofnac czasu... Nastapi wyjscie z programu.";
        system("pause");
        exit(0);
    }

    this->item = item;
    this->amount = amount;
}

void Income::setIncomeId(int newIncomeId) {
    if (newIncomeId > 0)
        incomeId = newIncomeId;
}

void Income::setUserId(int newUserId) {
    if (newUserId > 0)
        userId = newUserId;
}

void Income::setDate(int newDate) {
    if (newDate > 0)
        date = newDate;
}

void Income::setItem(string newItem) {
    item = newItem;
}

void Income::setAmount(double newAmount) {
    amount = newAmount;
}

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

int Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

double Income::getAmount() {
    return amount;
}

