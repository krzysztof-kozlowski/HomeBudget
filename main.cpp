#include <iostream>
#include "UserManager.h"

using namespace std;

int main() {
    UserManager userManager;

    //userManager.userRegistration();
    userManager.loadUsersFromFile();
    userManager.userLogin();

    return 0;
}
