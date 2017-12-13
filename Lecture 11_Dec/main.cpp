#include <iostream>
#include "Date.h"

Date::Date(int day, int month, int year) {
    _day = day;
    _month = month;
    _year = year;
}

bool Date::operator>(Date const& date) {
    if(_year > date._year){
        return true;
    }
    if(_month > date._month){
        return true;
    }
    if (_day > date._day) {
        return true;
    }
}

Date& Date::operator+(Date const& date) {
    _day += date._day;
    _month += date._month;
    _year += date._year;
    f_date();
    return *this;
}

Date& Date::operator+(int) {
    _day += _day;
    _month += _month;
    _year += _year;
    f_date();
    return *this;
}

void Date::f_date() {
    if(_day > 30){
        _day += _day%30;
        _month +=_day/30;
    }
    if(_month > 12){
        _month += _month%12;
        _year += _month/12;
    }
}


int main() {
    Date d1(12, 12, 1999);
    Date d2(1, 9, 2012);
    Date temp;
    temp=d1+d2;
    return 0;
}