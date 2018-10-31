#include "AuxMethods.h"

int AuxMethods::conversionStringToInt(string word) {
    int number;
    istringstream iss(word);
    iss >> number;

    return number;
}

string AuxMethods::changeFirstLetterOnUpperRestOnLower(string content) {
    if (!content.empty()) {
        transform(content.begin(), content.end(), content.begin(), ::tolower);
        content[0] = toupper(content[0]);
    }
    return content;
}
