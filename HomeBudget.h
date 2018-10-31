#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
//#include "IncomeManager.h"
//#include "ExpenseManager.h"

using namespace std;

class HomeBudget {
    UserManager userManager;
    //IncomeManager *incomeManager;
    //ExpenseManager *expenseManager;
    const string fileNameWithIncomes;
    const string fileNameWithExpenses;

public:
    /*HomeBudget(string fileNameWithUsers, string FILENAMEWITHINCOMES, string FILENAMEWITHEXPENSES) :
        userManager(fileNameWithUsers), fileNameWithIncomes(FILENAMEWITHINCOMES), fileNameWithExpenses(FILENAMEWITHEXPENSES){};*/
    void userRegistration();
    void userLogin();
    void passwordChangeLoggedUser();
    int getIdLoggedUser();
    int userLogout();
};

#endif // HOMEBUDGET_H