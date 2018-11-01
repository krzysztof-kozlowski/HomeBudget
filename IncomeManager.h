#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Income.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "TimeManager.h"
#include "AuxMethods.h"

class IncomeManager {
    const int idLoggedUser;
    FileWithIncomes fileWithIncomes;
    TimeManager timeManager;
    vector <Income> incomes;

    Income enterDataOfNewIncome();
    int enterDate();
    double enterAmount();
    double checkValueOfAmount(string amount);

public:
    IncomeManager(string fileNameWithIncomes, int IDLOGGEDUSER) : fileWithIncomes(fileNameWithIncomes), idLoggedUser(IDLOGGEDUSER) {
        //fileNameWithIncomes.loadIncomesLoggedUserFromFile(idLoggedUser, users);
    };
    void addIncome();
    void loadIncomesLoggedUserFromFile();
    double calculateSumOfIncomes();
    void showIncomesList();
    int getStartBorderPeriod();
    int getEndBorderPeriod();
};
#endif // INCOMEMANAGER_H
