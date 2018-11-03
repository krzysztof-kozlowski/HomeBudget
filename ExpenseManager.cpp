#include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    Expense expense = enterDataOfNewExpense();

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);
}

Expense ExpenseManager::enterDataOfNewExpense() {
    int expenseId = fileWithExpenses.checkIdOfLastExpense() + 1;
    int userId = idLoggedUser;

    int date;
    string item;
    double amount;
    char dateDecision;

    cout << "Czy wydatek dotyczy dzisiejszej daty <t/n>: ";
    cin >> dateDecision;
    if (dateDecision == 't')
        date = timeManager.getCurrentTime();
    else if (dateDecision == 'n')
        date = enterDate();

    cout << "Wpisz czego dotyczy ten wydatek: ";
    cin.sync();
    getline(cin, item);
    amount = enterAmount();

    Expense expense(expenseId, userId, date, AuxMethods::changeFirstLetterOnUpperRestOnLower(item), amount);

    return expense;
}

int ExpenseManager::enterDate() {
    string date;

    do {
        cout << "Wpisz date <rrrr-mm-dd>: ";
        cin.sync();
        getline(cin, date);
    } while(!timeManager.isCorrectDate(date));

    return timeManager.calculateManualDateToSeconds(date);
}

double ExpenseManager::enterAmount() {
    string strAmount;

    cout << "Wpisz kwote wydatku: ";
    cin.sync();
    getline(cin, strAmount);

    return checkValueOfAmount(strAmount);
}

double ExpenseManager::checkValueOfAmount(string strAmount) {
    for(int i = 0; i < strAmount.length(); i++) {
        if (strAmount[i] == ',')
            strAmount[i] = '.';
    }

    string::size_type sz;
    double doubleAmount = stod(strAmount, &sz);

    return doubleAmount;
}

double ExpenseManager::calculateSumOfExpenses() {
    ;
}

void ExpenseManager::showExpensesList() {
    ;
}

int ExpenseManager::getStartBorderPeriod() {
    ;
}

int ExpenseManager::getEndBorderPeriod() {
    ;
}


