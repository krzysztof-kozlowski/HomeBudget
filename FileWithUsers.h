#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "AuxMethods.h"
//#include "Plik.h"


using namespace std;

class FileWithUsers /*: private Plik*/ {
    const string nazwaPlikuZUzytkownikami;

    void putDataUserIntoFile(User user, CMarkup& xml);
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    //PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI): nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif // FILEWITHUSERS_H
