#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class UserManager {
    int idLoggedUser;
    vector <User> users;
    //FileWithUsers fileWithUsers;

    User enterDataOfNewUser();
    int getIdOfNewUser();
    bool isExistLogin(string login);

public:
    /*UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        idLoggedUser = 0;
        users = fileWithUsers.loadUsersFromFile();
    };*/
    void userRegistration();
    void loadUsersFromFile();
    int userLogin();
    void passwordChangeLoggedUser();
    int getIdLoggedUser();
    int userLogout();
};

#endif // USERMANAGER_H
