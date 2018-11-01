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
    xml.AddElem("AMOUNT", amount);
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

void FileWithIncomes::loadIncomesLoggedUserFromFile() {
    ;
}


