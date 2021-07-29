//
// Created by Kai Marshall on 7/29/21.
//

#include "Date.h"
Date::Date(int aMonth, int aDay, int aYear) : month(aMonth), day(aDay), year(aYear) {}

int Date::getMonth() {
    return month;
}

int Date::getDay(){
    return day;
}
int Date::getYear(){
    return year;
}

void Date::setMonth(int aMonth){
    month = aMonth;
}
void Date::setDay(int aDay){
    day = aDay;
}
void Date::setYear(int aYear){
    year = aYear;
}