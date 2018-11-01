#include "IncomeManager.h"

void IncomeManager::addIncome() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Income income = enterDataOfNewIncome();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile();
}

Income IncomeManager::enterDataOfNewIncome() {
    int incomeId = fileWithIncomes.checkIdOfLastIncome() + 1;
    int userId = idLoggedUser;

    int date;
    string item;
    double amount;
    char dateDecision;

    cout << "Czy przychod dotyczy dzisiejszej daty: <t/n> ";
    cin >> dateDecision;
    if (dateDecision == 't')
        ;//date = timeManager.getCurrentTime();
    else
        ;//date = enterDate();

    cout << "Wpisz czego dotyczy ten przychod: ";
    cin.sync();
    getline(cin, item);

    amount = enterAmount();

    Income income(incomeId, userId, date, AuxMethods::changeFirstLetterOnUpperRestOnLower(item), amount);

    return income;
}

int IncomeManager::enterDate() {
    cout << "Wpisz wysokosc przychodu: ";
}

double IncomeManager::enterAmount() {
    ;
}

void IncomeManager::loadIncomesLoggedUserFromFile() {
    ;
}

double IncomeManager::calculateSumOfIncomes() {
    ;
}

void IncomeManager::showIncomesList() {
    ;
}

int IncomeManager::getStartBorderPeriod() {
    ;
}

int IncomeManager::getEndBorderPeriod() {
    ;
}


