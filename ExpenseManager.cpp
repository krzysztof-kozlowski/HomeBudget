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

void ExpenseManager::showExpensesSummaryCurrentMonth() {
    int startDate = timeManager.calculateBeginOfCurrentMonth();
    int endDate = timeManager.getCurrentTime();

    cout << " >>> LISTA WYDATKOW <<<" << endl << endl;
    showExpensesList(startDate, endDate);
    cout << endl;
    sumOfExpenses = calculateSumOfExpenses(startDate, endDate);
    cout << "Suma wydatkow wynosi: " << sumOfExpenses << endl;
    cout << "---------------------------" << endl << endl;
}

void ExpenseManager::showExpensesSummaryPreviousMonth(){
;
}

void ExpenseManager::showExpensesList(int startDate, int endDate) {
    sort(expenses.begin(),expenses.end());

    for(int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <= endDate)) {
            cout << timeManager.calculateSecondsToManualDate(expenses[i].getDate()) << "  /  ";
            cout << expenses[i].getItem() << "  /  ";
            cout << expenses[i].getAmount() << endl;
        }
    }
}

bool operator<(Expense &expense1, Expense &expense2) {
    return expense1.getDate() < expense2.getDate();
}

double ExpenseManager::calculateSumOfExpenses(int startDate, int endDate) {
    double sumOfExpenses = 0;

    for(int i = 0; i < expenses.size(); i++) {
        if ((expenses[i].getDate() >= startDate) && (expenses[i].getDate() <= endDate)) {
            sumOfExpenses += expenses[i].getAmount();
        }
    }
    return sumOfExpenses;
}

double ExpenseManager::getSumOfExpenses() {
    return sumOfExpenses;
}

