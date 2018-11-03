#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "FileWithExpenses.h"
#include "Expense.h"
#include "UserManager.h"
#include "TimeManager.h"
#include "AuxMethods.h"

class ExpenseManager {
    const int idLoggedUser;
    FileWithExpenses fileWithExpenses;
    TimeManager timeManager;
    vector <Expense> expenses;

    Expense enterDataOfNewExpense();
    int enterDate();
    double enterAmount();
    double checkValueOfAmount(string amount);

public:
    ExpenseManager(string fileNameWithExpenses, int IDLOGGEDUSER) : fileWithExpenses(fileNameWithExpenses), idLoggedUser(IDLOGGEDUSER); {
        fileWithExpenses.loadExpensesLoggedUserFromFile(expenses, idLoggedUser);
    };
    void addExpense();
    double calculateSumOfExpenses();
    void showExpensesList();
    int getStartBorderPeriod();
    int getEndBorderPeriod();
};
#endif // EXPENSEMANAGER_H
