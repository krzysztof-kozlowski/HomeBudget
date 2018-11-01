#ifndef TIMEMANAGER_H
#define TIMEMANAGER_H

#include <iostream>

class TimeManager {
    int currentTime;
    int startBorderPeriod;
    int endBorderPeriod;

public:
    int getCurrentTime();
    int calculateStartBorderPeriod();
    int calculateEndBorderPeriod();
};

#endif // TIMEMANAGER_H
