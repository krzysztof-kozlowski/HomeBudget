#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <stdexcept>

#include "FileWithIncomes.h"
#include "Income.h"
#include "UserManager.h"
#include "TimeManager.h"
#include "AuxMethods.h"

class IncomeManager {
    const int idLoggedUser;
    double sumOfIncomes;
    FileWithIncomes fileWithIncomes;
    TimeManager timeManager;
    vector <Income> incomes;

    Income enterDataOfNewIncome();
    int enterDate();
    double enterAmount();
    double checkValueOfAmount(string amount);

public:
    IncomeManager(string fileNameWithIncomes, int IDLOGGEDUSER) : fileWithIncomes(fileNameWithIncomes), idLoggedUser(IDLOGGEDUSER) {
        fileWithIncomes.loadIncomesLoggedUserFromFile(incomes, idLoggedUser);
    };
    void addIncome();

    void showIncomesSummaryCurrentMonth();
    void showIncomesSummaryPreviousMonth();
    void showIncomesList(int startDate, int endDate);
    double calculateSumOfIncomes(int startDate, int endDate);
    double getSumOfIncomes();
};

bool operator<(Income &income1, Income &income2);

#endif // INCOMEMANAGER_H
