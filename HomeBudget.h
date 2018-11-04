#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "TimeManager.h"

using namespace std;

class HomeBudget {
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    TimeManager *timeManager;

    const string fileNameWithIncomes;
    const string fileNameWithExpenses;

public:
    HomeBudget(string fileNameWithUsers, string FILENAMEWITHINCOMES, string FILENAMEWITHEXPENSES) :
        userManager(fileNameWithUsers), fileNameWithIncomes(FILENAMEWITHINCOMES), fileNameWithExpenses(FILENAMEWITHEXPENSES) {};

    void userRegistration();
    void userLogin();
    void passwordChangeLoggedUser();
    int getIdLoggedUser();
    int userLogout();

    void addIncome();
    void addExpense();
    void checkCurrentMonthBalance();
    void checkPreviousMonthBalance();
    void checkSelectedPeriodBalance();
};

#endif // HOMEBUDGET_H
