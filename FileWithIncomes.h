#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>

#include "Income.h"

class FileWithIncomes { /*: private Plik*/
    const string fileNameWithIncomes;

    int getIdOfLastIncome();

public:
    FileWithIncomes(string FILENAMEWITHINCOMES): fileNameWithIncomes(FILENAMEWITHINCOMES) {};
    void addIncomeToFile();
    int checkIdOfLastIncome();
    void loadIncomesLoggedUserFromFile();
};

#endif // FILEWITHINCOMES_H
