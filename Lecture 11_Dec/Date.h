#pragma once

class Date{
public:
    Date() = default;
    Date(int day, int month, int year);
    ~Date() = default;
    bool operator>(Date const& date);
    Date& operator+(Date const& date);
    Date& operator+(int);
    void f_date();

private:
    int _day = 1;
    int _month = 1;
    int _year = 1;

};


