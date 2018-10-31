#include "AuxMethods.h"

int AuxMethods::conversionStringToInt(string word) {
    int number;
    istringstream iss(word);
    iss >> number;

    return number;
}

