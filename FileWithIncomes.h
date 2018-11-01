#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>

#include "Markup.h"
#include "Income.h"
#include "AuxMethods.h"

class FileWithIncomes {
    const string fileNameWithIncomes;

    int getIdOfLastIncome();
    void putDataIncomeIntoFile(Income income, CMarkup& xml);

public:
    FileWithIncomes(string FILENAMEWITHINCOMES): fileNameWithIncomes(FILENAMEWITHINCOMES) {};
    void addIncomeToFile(Income income);
    int checkIdOfLastIncome();
    void loadIncomesLoggedUserFromFile();
};

#endif // FILEWITHINCOMES_H
