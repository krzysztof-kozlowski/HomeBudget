#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>
#include <time.h>

#include "AuxMethods.h"

using namespace std;

class TimeManager {
    int currentTime;
    int startBorderPeriod;
    int endBorderPeriod;

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
};

#endif // TIMEMANAGER_H
