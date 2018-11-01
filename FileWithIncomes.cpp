#include "FileWithIncomes.h"

void FileWithIncomes::addIncomeToFile(Income income) {
    CMarkup xml;

    if (xml.Load("incomes.xml") == false) {
        xml.AddElem("INCOME");
        putDataIncomeIntoFile(income, xml);
        xml.Save("incomes.xml");
    } else {
        putDataIncomeIntoFile(income, xml);
        xml.Save("incomes.xml");
    }
}

void FileWithIncomes::putDataIncomeIntoFile(Income income, CMarkup& xml) {
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INFO");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeId());
    xml.AddElem("USERID", income.getUserId());
    xml.AddElem("DATE", income.getDate());
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", income.getAmount());
}




/*
    string liniaZDanymiAdresata = "";
fstream plikTekstowy;
plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

if (plikTekstowy.good() == true) {
    liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

    if (czyPlikJestPusty(plikTekstowy) == true) {
        plikTekstowy << liniaZDanymiAdresata;
    } else {
        plikTekstowy << liniaZDanymiAdresata ;
    }
    plikTekstowy << endl;
    plikTekstowy.close();
} else {
    cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
}
system("pause");*/

int FileWithIncomes::checkIdOfLastIncome() {
    ;
}

void FileWithIncomes::loadIncomesLoggedUserFromFile() {
    ;
}


