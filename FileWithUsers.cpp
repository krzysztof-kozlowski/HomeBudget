#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    CMarkup xml;

    if (xml.Load(fileNameWithUsers) == false) {
        xml.AddElem("USER");
        putDataUserIntoFile(user, xml);
        xml.Save(fileNameWithUsers);
    } else {
        putDataUserIntoFile(user, xml);
        xml.Save(fileNameWithUsers);
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

    xml.Load(fileNameWithUsers);
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("INFO")) {
        xml.IntoElem();
        xml.FindElem("ID");
        string strId = xml.GetData();
        int id = AuxMethods::conversionStringToInt(strId);
        xml.FindElem("LOGIN");
        string login = xml.GetData();
        xml.FindElem("PASSWORD");
        string  password = xml.GetData();
        xml.FindElem("NAME");
        string name = xml.GetData();
        xml.FindElem("SURNAME");
        string surname = xml.GetData();
        xml.OutOfElem();

        User user(id, login, password, name, surname);
        users.push_back(user);
    }
    return users;
}

void FileWithUsers::saveAllUsersToFile(vector <User> &users) {
    CMarkup xml;

    xml.Load(fileNameWithUsers);
    xml.ResetPos();
    xml.FindElem();
    xml.RemoveElem();
    xml.AddElem("USER");
    xml.IntoElem();

    for(int i = 0; i < users.size(); i++) {
        xml.AddElem("INFO");
        xml.IntoElem();
        xml.AddElem("ID", users[i].getId());
        xml.AddElem("LOGIN", users[i].getLogin());
        xml.AddElem("PASSWORD", users[i].getPassword());
        xml.AddElem("NAME", users[i].getName());
        xml.AddElem("SURNAME", users[i].getSurname());
        xml.OutOfElem();
    }
    xml.Save(fileNameWithUsers);
}
