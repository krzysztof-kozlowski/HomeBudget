#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <time.h>

#include "AuxMethods.h"

using namespace std;

class TimeManager {
    bool isWellFormatted(string date);
    bool isCorrectDateValues(string date);
    bool isCorrectPeriod(string date);

    int getYearFromManualDate(string date);
    int getMonthFromManualDate(string date);
    int getDayFromManualDate(string date);

public:
    int getCurrentTime();
    bool isCorrectDate(string date);
    int calculateManualDateToSeconds(string date);
    string calculateSecondsToManualDate(int seconds);
    int calculateBeginOfCurrentMonth();
    string setBeginCurrentMonth(int seconds);
};

#endif // TIMEMANAGER_H
