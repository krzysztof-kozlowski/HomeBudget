#include "HomeBudget.h"

void HomeBudget::userRegistration() {
    userManager.userRegistration();
}

void HomeBudget::userLogin() {
    userManager.userLogin();
    if (userManager.getIdLoggedUser()) {
        //incomeManager = new IncomeManager(fileNameWithIncomes, userManager.getIdLoggedUser());
        //expenseManager = new ExpenseManager(fileNameWithExpenses, userManager.getIdLoggedUser());
    }
}

void HomeBudget::passwordChangeLoggedUser() {
    userManager.passwordChangeLoggedUser();
}

int HomeBudget::getIdLoggedUser() {
    return userManager.getIdLoggedUser();
}

int HomeBudget::userLogout() {
    userManager.userLogout();
    delete incomeManager;
    //delete expenseManager;
}
