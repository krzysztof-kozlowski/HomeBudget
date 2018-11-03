#include "FileWithExpenses.h"

void FileWithExpenses::addExpenseToFile(Expense expense) {
    CMarkup xml;

    if (xml.Load(fileNameWithExpenses) == false) {
        xml.AddElem("EXPENSE");
        putDataExpenseIntoFile(expense, xml);
        xml.Save(fileNameWithExpenses);
    } else {
        putDataExpenseIntoFile(expense, xml);
        xml.Save(fileNameWithExpenses);
    }
}

void FileWithExpenses::putDataExpenseIntoFile(Expense expense, CMarkup& xml) {
    stringstream stream;
    stream << fixed << setprecision(2) << expense.getAmount();
    string strAmount = stream.str();

    string amount = to_string(expense.getAmount());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INFO");
    xml.IntoElem();
    xml.AddElem("EXPENSEID", expense.getExpenseId());
    xml.AddElem("USERID", expense.getUserId());
    xml.AddElem("DATE", expense.getDate());
    xml.AddElem("ITEM", expense.getItem());
    xml.AddElem("AMOUNT", strAmount);
}

int FileWithExpenses::checkIdOfLastExpense() {
    CMarkup xml;
    int lastExpenseId = 0;

    if (xml.Load(fileNameWithExpenses) == false)
        return lastExpenseId;
    else {
        xml.Load(fileNameWithExpenses);
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("INFO")) {
            xml.IntoElem();
            xml.FindElem("EXPENSEID");
            lastExpenseId = AuxMethods::conversionStringToInt(xml.GetData());
            xml.OutOfElem();
        }
    }
    return lastExpenseId;
}

void FileWithExpenses::loadExpensesLoggedUserFromFile(vector <Expense> &expenses, int idLoggedUser) {
    CMarkup xml;

    if (xml.Load(fileNameWithExpenses) == false)
        cout << "Nie udalo sie otworzyc pliku: " << fileNameWithExpenses << endl;
    else {
        xml.Load(fileNameWithExpenses);
        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("INFO") ) {
            xml.IntoElem();
            xml.FindElem( "USERID" );
            string userId = xml.GetData();
            if (AuxMethods::conversionStringToInt(userId) == idLoggedUser) {
                Expense expense = getExpenseInfoFromFile(xml);
                expenses.push_back(expense);
            }
        }
    }
}

Expense FileWithExpenses::getExpenseInfoFromFile(CMarkup& xml) {
    xml.ResetMainPos();
    xml.FindElem("EXPENSEID");
    string strExpenseId = xml.GetData();
    xml.FindElem("USERID");
    string strUserId = xml.GetData();
    xml.FindElem("DATE");
    string strDate = xml.GetData();
    xml.FindElem("ITEM");
    string item = xml.GetData();
    xml.FindElem("AMOUNT");
    string strAmount = xml.GetData();
    xml.OutOfElem();

    int expenseId = AuxMethods::conversionStringToInt(strExpenseId);
    int userId = AuxMethods::conversionStringToInt(strUserId);
    int date = AuxMethods::conversionStringToInt(strDate);

    string::size_type sz;
    double amount = stod(strAmount, &sz);

    Expense expense(expenseId, userId, date, item, amount);

    return expense;
}

