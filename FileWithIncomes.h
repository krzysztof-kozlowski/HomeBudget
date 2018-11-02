#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Markup.h"
#include "Income.h"
#include "AuxMethods.h"

class FileWithIncomes {
    const string fileNameWithIncomes;

    int getIdOfLastIncome();
    void putDataIncomeIntoFile(Income income, CMarkup& xml);
    Income getIncomeInfoFromFile(CMarkup& xml);

public:
    FileWithIncomes(string FILENAMEWITHINCOMES): fileNameWithIncomes(FILENAMEWITHINCOMES) {};
    void addIncomeToFile(Income income);
    int checkIdOfLastIncome();
    void loadIncomesLoggedUserFromFile(vector <Income> &incomes, int idLoggedUser);
};

#endif // FILEWITHINCOMES_H
