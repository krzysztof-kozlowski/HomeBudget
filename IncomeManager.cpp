#include "IncomeManager.h"

void IncomeManager::addIncome() {
    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    Income income = enterDataOfNewIncome();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);
}

Income IncomeManager::enterDataOfNewIncome() {
    int incomeId = fileWithIncomes.checkIdOfLastIncome() + 1;
    int userId = idLoggedUser;

    int date;
    string item;
    double amount;
    char dateDecision;

    cout << "Czy przychod dotyczy dzisiejszej daty <t/n>: ";
    cin >> dateDecision;
    if (dateDecision == 't')
        date = timeManager.getCurrentTime();
    else if (dateDecision == 'n')
        date = enterDate();

    cout << "Wpisz czego dotyczy ten przychod: ";
    cin.sync();
    getline(cin, item);
    amount = enterAmount();

    Income income(incomeId, userId, date, AuxMethods::changeFirstLetterOnUpperRestOnLower(item), amount);

    return income;
}

int IncomeManager::enterDate() {
    string date;

    do {
        cout << "Wpisz date <rrrr-mm-dd>: ";
        cin.sync();
        getline(cin, date);
    } while(!timeManager.isCorrectDate(date));

    return timeManager.calculateManualDateToSeconds(date);
}

double IncomeManager::enterAmount() {
    string strAmount;

    cout << "Wpisz kwote przychodu: ";
    cin.sync();
    getline(cin, strAmount);

    return checkValueOfAmount(strAmount);
}

double IncomeManager::checkValueOfAmount(string strAmount) {
    for(int i = 0; i < strAmount.length(); i++) {
        if (strAmount[i] == ',')
            strAmount[i] = '.';
    }

    string::size_type sz;
    double doubleAmount = stod(strAmount, &sz);

    return doubleAmount;
}

void IncomeManager::showIncomesSummary() {
    system("cls");
    cout << " >>> LISTA PRZYCHODOW <<<" << endl << endl;
    showIncomesList();

}

void IncomeManager::showIncomesList() {
    int startDate = timeManager.calculateBeginOfCurrentMonth();
    int endDate = timeManager.getCurrentTime();

    sort(incomes.begin(),incomes.end());

    for(int i = 0; i < incomes.size(); i++){
        cout << incomes[i].getItem() << endl;
        cout << timeManager.calculateSecondsToManualDate(incomes[i].getDate()) << endl;
    }

    system("pause");

}

bool operator<(Income &income1, Income &income2) {
    return income1.getDate() < income2.getDate();
}

double IncomeManager::calculateSumOfIncomes() {
    ;
}

double IncomeManager::getSumOfIncomes() {
    return sumOfIncomes;
}



