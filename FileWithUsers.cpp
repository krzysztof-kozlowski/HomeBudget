#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;

    if (xml.Load("users.xml") == false) {
        xml.AddElem("USER");
        putDataUserIntoFile(user, xml);
        xml.Save("users.xml");
    } else {
        putDataUserIntoFile(user, xml);
        xml.Save("users.xml");
    }
}

void FileWithUsers::putDataUserIntoFile(User user, CMarkup& xml) {
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INFO");
    xml.IntoElem();
    xml.AddElem("ID", user.getId());
    xml.AddElem("LOGIN", user.getLogin());
    xml.AddElem("PASSWORD", user.getPassword());
    xml.AddElem("NAME", user.getName());
    xml.AddElem("SURNAME", user.getSurname());
}

vector <User> FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    vector <User> users;

    xml.Load("users.xml");
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while ( xml.FindElem("INFO") ) {
        xml.IntoElem();
        xml.FindElem("ID");
        MCD_STR strId = xml.GetData();
        int id = AuxMethods::conversionStringToInt(strId);
        xml.FindElem("LOGIN");
        MCD_STR login = xml.GetData();
        xml.FindElem("PASSWORD");
        MCD_STR password = xml.GetData();
        xml.FindElem("NAME");
        MCD_STR name = xml.GetData();
        xml.FindElem("SURNAME");
        MCD_STR surname = xml.GetData();
        xml.OutOfElem();

        User user(id, login, password, name, surname);
        users.push_back(user);
    }
    return users;
}
/*
string PlikZUzytkownikami::zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik) {
    string liniaZDanymiUzytkownika = "";
    liniaZDanymiUzytkownika += MetodyPomocnicze::konwerjsaIntNaString(uzytkownik.pobierzId())+ '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzLogin() + '|';
    liniaZDanymiUzytkownika += uzytkownik.pobierzHaslo() + '|';
    return liniaZDanymiUzytkownika;
}
vector <Uzytkownik> PlikZUzytkownikami::wczytajUzytkownikowZPliku(){
    fstream plikTekstowy;
    vector <Uzytkownik> uzytkownicy;
    string daneJednegoUzytkownikaOddzielonePionowymiKreskami = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::in);
    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoUzytkownikaOddzielonePionowymiKreskami))
        {
            Uzytkownik uzytkownik = pobierzDaneUzytkownika(daneJednegoUzytkownikaOddzielonePionowymiKreskami);
            uzytkownicy.push_back(uzytkownik);
        }
        plikTekstowy.close();
    }
    return uzytkownicy;
}
Uzytkownik PlikZUzytkownikami::pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami)
{
    int id;
    string login, haslo;
    string pojedynczaDanaUzytkownika = "";
    int numerPojedynczejDanejUzytkownika = 1;
    for (int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoUzytkownikaOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaUzytkownika += daneJednegoUzytkownikaOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejUzytkownika)
            {
            case 1:
                id = atoi(pojedynczaDanaUzytkownika.c_str());
                break;
            case 2:
                login = pojedynczaDanaUzytkownika;
                break;
            case 3:
                haslo = pojedynczaDanaUzytkownika;
                break;
            }
            pojedynczaDanaUzytkownika = "";
            numerPojedynczejDanejUzytkownika++;
        }
    }
    Uzytkownik uzytkownik(id, login, haslo);
    return uzytkownik;
}
void PlikZUzytkownikami::zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy){
    fstream plikTekstowy;
    string liniaZDanymiUzytkownika = "";
    plikTekstowy.open(nazwaPlikuZUzytkownikami.c_str(), ios::out);
    if (plikTekstowy.good() == true){
        for (int i = 0; i < uzytkownicy.size(); i++){
                liniaZDanymiUzytkownika = zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(uzytkownicy[i]);
                if (i > uzytkownicy.size()) {
                    plikTekstowy << liniaZDanymiUzytkownika;
                } else {
                    plikTekstowy << liniaZDanymiUzytkownika << endl;
                }
                liniaZDanymiUzytkownika = "";
        }
        plikTekstowy.close();
    } else {
        cout << "Nie mozna otworzyc pliku " << nazwaPlikuZUzytkownikami << endl;
    }
}
*/
