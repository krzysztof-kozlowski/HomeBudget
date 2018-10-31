#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>

#include "Markup.h"
#include "User.h"
//#include "Plik.h"
//#include "MetodyPomocnicze.h"

using namespace std;

class FileWithUsers /*: private Plik*/ {
    const string nazwaPlikuZUzytkownikami;

    void putDataUserIntoFile(User user, CMarkup& xml);
    int konwersjaStringNaInt(string liczba);
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    //PlikZUzytkownikami(string NAZWAPLIKUZUZYTKOWNIKAMI): nazwaPlikuZUzytkownikami(NAZWAPLIKUZUZYTKOWNIKAMI) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    //void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> &uzytkownicy);
};

#endif // FILEWITHUSERS_H
