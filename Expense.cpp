#include "Expense.h"

Expense::Expense(int expenseId, int userId, int date, string item, double amount) {
    if (expenseId > 0)
        this->expenseId = expenseId;
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

void Expense::setExpenseId(int newExpenseId) {
    if (newExpenseId > 0)
        expenseId = newExpenseId;
}

void Expense::setUserId(int newUserId) {
    if (newUserId > 0)
        userId = newUserId;
}

void Expense::setDate(int newDate) {
    if (newDate > 0)
        date = newDate;
}

void Expense::setItem(string newItem) {
    item = newItem;
}

void Expense::setAmount(double newAmount) {
    amount = newAmount;
}

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

double Expense::getAmount() {
    return amount;
}

