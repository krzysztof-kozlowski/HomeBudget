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
        date = timeManager.enterDate();

    cout << "Wpisz czego dotyczy ten przychod: ";
    cin.sync();
    getline(cin, item);
    amount = enterAmount();

    Income income(incomeId, userId, date, AuxMethods::changeFirstLetterOnUpperRestOnLower(item), amount);

    return income;
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

void IncomeManager::showIncomesSummaryCurrentMonth() {
    int startDate = timeManager.calculateBeginOfCurrentMonth();
    int endDate = timeManager.getCurrentTime();

    system("cls");
    cout << " >>> LISTA PRZYCHODOW <<<" << endl << endl;
    showIncomesList(startDate, endDate);
    cout << endl;
    sumOfIncomes = calculateSumOfIncomes(startDate, endDate);
    cout << "Suma przychodow wynosi: " << sumOfIncomes << endl;
    cout << "---------------------------" << endl << endl;
}

void IncomeManager::showIncomesSummaryPreviousMonth() {
    int startDate = timeManager.calculateBeginOfPreviousMonth();
    int endDate = timeManager.calculateEndOfPreviuosMonth();

    system("cls");
    cout << " >>> LISTA PRZYCHODOW <<<" << endl << endl;
    showIncomesList(startDate, endDate);
    cout << endl;
    sumOfIncomes = calculateSumOfIncomes(startDate, endDate);
    cout << "Suma przychodow wynosi: " << sumOfIncomes << endl;
    cout << "---------------------------" << endl << endl;
}

void IncomeManager::showIncomesSummarySelectedPeriod(int startDate, int endDate) {
    cout << endl;
    cout << " >>> LISTA PRZYCHODOW <<<" << endl << endl;
    showIncomesList(startDate, endDate);
    cout << endl;
    sumOfIncomes = calculateSumOfIncomes(startDate, endDate);
    cout << "Suma przychodow wynosi: " << sumOfIncomes << endl;
    cout << "---------------------------" << endl << endl;
}

void IncomeManager::showIncomesList(int startDate, int endDate) {
    sort(incomes.begin(),incomes.end());

    for(int i = 0; i < incomes.size(); i++) {
        if ((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate)) {
            cout << incomes[i].getUserId() << "  /  ";
            cout << timeManager.calculateSecondsToManualDate(incomes[i].getDate()) << "  /  ";
            cout << incomes[i].getItem() << "  /  ";
            cout << incomes[i].getAmount() << endl;
        }
    }
}

bool operator<(Income &income1, Income &income2) {
    return income1.getDate() < income2.getDate();
}

double IncomeManager::calculateSumOfIncomes(int startDate, int endDate) {
    double sumOfIncomes = 0;

    for(int i = 0; i < incomes.size(); i++) {
        if ((incomes[i].getDate() >= startDate) && (incomes[i].getDate() <= endDate)) {
            sumOfIncomes += incomes[i].getAmount();
        }
    }
    return sumOfIncomes;
}

double IncomeManager::getSumOfIncomes() {
    return sumOfIncomes;
}
