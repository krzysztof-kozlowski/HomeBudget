#include <iostream>
#include "HomeBudget.h"

using namespace std;

char selectOptionFromMainMenu();
char selectOptionFromUserMenu();

int main() {
    HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");
    char choice;

    while (true) {
        if (homeBudget.getIdLoggedUser() == 0) {
            choice = selectOptionFromMainMenu();

            switch (choice) {
            case '1':
                homeBudget.userRegistration();
                break;
            case '2':
                homeBudget.userLogin();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            do {
                choice = selectOptionFromUserMenu();

                switch (choice) {
                case '1':
                    homeBudget.addIncome();
                    break;
                case '2':
                    homeBudget.addExpense();
                    break;
                case '3':
                    homeBudget.checkCurrentMonthBalance();
                    break;
                case '4':
                    homeBudget.checkPreviousMonthBalance();
                    break;
                case '5':
                    ;
                    break;
                case '6':
                    homeBudget.passwordChangeLoggedUser();
                    break;
                case '7':
                    homeBudget.userLogout();
                    break;
                }
            } while (choice != '7');
        }
    }
    return 0;
}

char selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();

    return choice;
}

char selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    cin >> choice;
    cin.ignore();

    return choice;
}
