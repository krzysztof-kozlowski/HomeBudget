#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xml;

    if (xml.Load(fileNameWithIncomes) == false) {
        xml.AddElem("INCOME");
        putDataIncomeIntoFile(income, xml);
        xml.Save(fileNameWithIncomes);
    } else {
        putDataIncomeIntoFile(income, xml);
        xml.Save(fileNameWithIncomes);
    }
}

void FileWithIncomes::putDataIncomeIntoFile(Income income, CMarkup& xml) {
    stringstream stream;
    stream << fixed << setprecision(2) << income.getAmount();
    string strAmount = stream.str();

    string amount = to_string(income.getAmount());

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INFO");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeId());
    xml.AddElem("USERID", income.getUserId());
    xml.AddElem("DATE", income.getDate());
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", strAmount);
}

int FileWithIncomes::checkIdOfLastIncome() {
    CMarkup xml;
    int lastIncomeId = 0;

    if (xml.Load(fileNameWithIncomes) == false)
        return lastIncomeId;
    else {
        xml.Load(fileNameWithIncomes);
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("INFO")) {
            xml.IntoElem();
            xml.FindElem("INCOMEID");
            lastIncomeId = AuxMethods::conversionStringToInt(xml.GetData());
            xml.OutOfElem();
        }
    }
    return lastIncomeId;
}

void FileWithIncomes::loadIncomesLoggedUserFromFile(vector <Income> &incomes, int idLoggedUser) {
    CMarkup xml;

    if (xml.Load(fileNameWithIncomes) == false)
        cout << "Nie udalo sie otworzyc pliku: " << fileNameWithIncomes << endl;
    else {
        xml.Load(fileNameWithIncomes);
        xml.FindElem();
        xml.IntoElem();

        while ( xml.FindElem("INFO") ) {
            xml.IntoElem();
            xml.FindElem( "USERID" );
            string userId = xml.GetData();
            if (AuxMethods::conversionStringToInt(userId) == idLoggedUser) {
                Income income = getIncomeInfoFromFile(xml);
                incomes.push_back(income);
            } else
                xml.OutOfElem();
        }
    }
}

Income FileWithIncomes::getIncomeInfoFromFile(CMarkup& xml) {
    xml.ResetMainPos();
    xml.FindElem("INCOMEID");
    string strIncomeId = xml.GetData();
    xml.FindElem("USERID");
    string strUserId = xml.GetData();
    xml.FindElem("DATE");
    string strDate = xml.GetData();
    xml.FindElem("ITEM");
    string item = xml.GetData();
    xml.FindElem("AMOUNT");
    string strAmount = xml.GetData();
    xml.OutOfElem();

    int incomeId = AuxMethods::conversionStringToInt(strIncomeId);
    int userId = AuxMethods::conversionStringToInt(strUserId);
    int date = AuxMethods::conversionStringToInt(strDate);

    string::size_type sz;
    double amount = stod(strAmount, &sz);

    Income income(incomeId, userId, date, item, amount);

    return income;
}
