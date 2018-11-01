#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Income.h"
#include "UserManager.h"
#include "FileWithIncomes.h"
#include "AuxMethods.h"

class IncomeManager {
    const int idLoggedUser;
    FileWithIncomes fileWithIncomes;
    vector <Income> incomes;
    //TimeManager timeManager;

    Income enterDataOfNewIncome();
    int enterDate();
    double enterAmount();

public:
    IncomeManager(string fileNameWithIncomes, int IDLOGGEDUSER) : fileWithIncomes(fileNameWithIncomes), idLoggedUser(IDLOGGEDUSER) {
        //fileNameWithIncomes.loadIncomesFromFile(idLoggedUser, users);
    };
    void addIncome();
    void loadIncomesLoggedUserFromFile();
    double calculateSumOfIncomes();
    void showIncomesList();
    int getStartBorderPeriod();
    int getEndBorderPeriod();
};
#endif // INCOMEMANAGER_H
