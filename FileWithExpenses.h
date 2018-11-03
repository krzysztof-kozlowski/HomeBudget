#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <sstream>
#include <iomanip>

#include "Markup.h"
#include "Expense.h"
#include "AuxMethods.h"

class FileWithExpenses {
    const string fileNameWithExpenses;

    int getIdOfLastExpense();
    void putDataExpenseIntoFile(Expense expense, CMarkup& xml);
    Expense getExpenseInfoFromFile(CMarkup& xml);

public:
    FileWithExpenses(string FILENAMEWITHEXPENSES): fileNameWithExpenses(FILENAMEWITHEXPENSES) {};
    void addExpenseToFile(Expense expense);
    int checkIdOfLastExpense();
    void loadExpensesLoggedUserFromFile(vector <Expense> &expenses, int idLoggedUser);
};

#endif // FILEWITHEXPENSES_H
