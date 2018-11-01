#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>

#include "Markup.h"
#include "User.h"
#include "AuxMethods.h"

using namespace std;

class FileWithUsers {
    const string fileNameWithUsers;

    void putDataUserIntoFile(User user, CMarkup& xml);

public:
    FileWithUsers(string FILENAMEWITHUSERS): fileNameWithUsers(FILENAMEWITHUSERS) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void saveAllUsersToFile(vector <User> &users);
};

#endif // FILEWITHUSERS_H
