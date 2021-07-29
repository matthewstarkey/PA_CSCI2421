//
// Created by Kai Marshall on 7/29/21.
//

#ifndef PA_CSCI2421_DATE_H
#define PA_CSCI2421_DATE_H


class Date {
private:
    int month;
    int day;
    int year;

public:
    Date(int aMonth, int aDay, int aYear);
    int getMonth();
    int getDay();
    int getYear();

    void setMonth(int aMonth);
    void setDay(int aDay);
    void setYear(int aYear);

};

#include "Date.cpp"
#endif //PA_CSCI2421_DATE_H
