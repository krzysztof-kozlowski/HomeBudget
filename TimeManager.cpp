#include "TimeManager.h"

int TimeManager::getCurrentTime() {
    time_t seconds;
    seconds = time(NULL);

    return seconds;
}

bool TimeManager::isCorrectDate(string date) {
    if ((isWellFormatted(date) == true) && (isCorrectDateValues(date) == true) && (isCorrectPeriod(date) == true))
        return true;
    else
        return false;
}

bool TimeManager::isWellFormatted(string date) {
    if ((date.length() == 10) &&
            (date[4] == '-' && date[7] == '-') &&
            (date[1] >= 48 && date[1] <= 57) &&
            (date[2] >= 48 && date[2] <= 57) &&
            (date[3] >= 48 && date[3] <= 57) &&
            (date[5] >= 48 && date[5] <= 57) &&
            (date[6] >= 48 && date[6] <= 57) &&
            (date[8] >= 48 && date[8] <= 57) &&
            (date[9] >= 48 && date[9] <= 57))
        return true;
    else
        return false;
}

bool TimeManager::isCorrectDateValues(string date) {
    int year = getYearFromManualDate(date);
    int month = getMonthFromManualDate(date);
    int day = getDayFromManualDate(date);

    if ((year >= 1970) && (month >= 1 && month <= 12) && (day >= 1 && day <= 31)) {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day <= 31))
            return true;
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && (day <= 30))
            return true;
        else if (month == 2) {
            if ((((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) && day <= 29)
                return true;
            else if (day <= 28)
                return true;
        }
    }
    return false;
}

bool TimeManager::isCorrectPeriod(string date) {
    int startBorderPeriod = calculateManualDateToSeconds("2000-01-01");
    int endBorderPeriod = getCurrentTime();

    int selectedDate = calculateManualDateToSeconds(date);

    if (selectedDate >= startBorderPeriod && selectedDate <= endBorderPeriod)
        return true;
    else
        return false;
}

int TimeManager::getYearFromManualDate(string date) {
    //yyyy-mm-dd
    string year;

    for(int i = 0; i < 4; i++) {
        year += date[i];
    }
    return AuxMethods::conversionStringToInt(year);
}

int TimeManager::getMonthFromManualDate(string date) {
    //yyyy-mm-dd
    string month;

    for(int i = 5; i < 7; i++) {
        month += date[i];
    }
    return AuxMethods::conversionStringToInt(month);
}

int TimeManager::getDayFromManualDate(string date) {
    //yyyy-mm-dd
    string day;

    for(int i = 8; i < 10; i++) {
        day += date[i];
    }
    return AuxMethods::conversionStringToInt(day);
}

int TimeManager::calculateManualDateToSeconds(string date) {
    int year = getYearFromManualDate(date);
    int month = getMonthFromManualDate(date);
    int day = getDayFromManualDate(date);
    int seconds = 0;

    for (int i = 1970; i < year; i++) {
        if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
            seconds += 366 * 60 * 60 * 24;
        else
            seconds += 365 * 60 *60 * 24;
    }

    for (int i = 1; i < month; i++) {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
            seconds += 31 * 60 * 60 * 24;
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            seconds += 30 * 60 * 60 * 24;
        else if (i == 2) {
            if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
                seconds += 29 * 60 *60 * 24;
            else
                seconds += 28 * 60 *60 * 24;
        }
    }
    for (int i = 1; i < day; i++) {
        seconds += 60 * 60 * 24;
    }
    return seconds;
}

string TimeManager::calculateSecondsToManualDate(int seconds) {
    string strYear = "";
    string strMonth = "";
    string strDay = "";

    time_t rawtime = seconds;
    struct tm * timeinfo;

    timeinfo = localtime ( &rawtime );

    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;
    int day = timeinfo->tm_mday;

    strYear = to_string(year);

    if (month < 10)
        strMonth = "0" + to_string(month);
    else
        strMonth = to_string(month);

    if (day < 10)
        strDay = "0" + to_string(day);
    else
        strDay = to_string(day);

    string date = strYear + "-" + strMonth + "-" + strDay;

    return date;
}

int TimeManager::calculateBeginOfCurrentMonth() {
    int currentTime = getCurrentTime();
    string date = setBeginCurrentMonth(currentTime);

    return calculateManualDateToSeconds(date);
}

string TimeManager::setBeginCurrentMonth(int seconds) {
    string strYear = "";
    string strMonth = "";

    time_t rawtime = seconds;
    struct tm * timeinfo;

    timeinfo = localtime ( &rawtime );

    int year = timeinfo->tm_year + 1900;
    int month = timeinfo->tm_mon + 1;

    strYear = to_string(year);
    if (month < 10)
        strMonth = "0" + to_string(month);
    else
        strMonth = to_string(month);

    string date = strYear + "-" + strMonth + "-01";
    return date;
}



