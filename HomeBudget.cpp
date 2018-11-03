#include "HomeBudget.h"

void HomeBudget::userRegistration() {
    userManager.userRegistration();
}

void HomeBudget::userLogin() {
    userManager.userLogin();
    if (userManager.getIdLoggedUser()) {
        incomeManager = new IncomeManager(fileNameWithIncomes, userManager.getIdLoggedUser());
        expenseManager = new ExpenseManager(fileNameWithExpenses, userManager.getIdLoggedUser());
    }
}

void HomeBudget::passwordChangeLoggedUser() {
    userManager.passwordChangeLoggedUser();
}

int HomeBudget::getIdLoggedUser() {
    return userManager.getIdLoggedUser();
}

int HomeBudget::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    delete expenseManager;
}

void HomeBudget::addIncome() {
    incomeManager->addIncome();
}

void HomeBudget::addExpense() {
    expenseManager->addExpense();
}

void HomeBudget::checkCurrentMonthBalance() {
    incomeManager->showIncomesSummaryCurrentMonth();
    expenseManager->showExpensesSummaryCurrentMonth();

    cout << "SALDO wynosi: " << incomeManager->getSumOfIncomes() - expenseManager->getSumOfExpenses() << endl << endl;
    system("pause");
}

void HomeBudget::checkPreviousMonthBalance() {
    incomeManager->showIncomesSummaryPreviousMonth();
    expenseManager->showExpensesSummaryPreviousMonth();

    cout << "SALDO wynosi: " << incomeManager->getSumOfIncomes() - expenseManager->getSumOfExpenses() << endl << endl;
    system("pause");
}
