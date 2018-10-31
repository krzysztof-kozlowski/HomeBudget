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
    const string fileNameWithUsers;

    void putDataUserIntoFile(User user, CMarkup& xml);
    //string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    //Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    FileWithUsers(string FILENAMEWITHUSERS): fileNameWithUsers(FILENAMEWITHUSERS) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif // FILEWITHUSERS_H
