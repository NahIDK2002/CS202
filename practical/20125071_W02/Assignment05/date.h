#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <ctime>

class MyDate{
    private:
        int day;
        int month;
        int year;
        bool checkIsValid();
        bool checkIsLeapYear();

    public:
        MyDate();
        MyDate(int d);
        MyDate(int d, int m);
        MyDate(int d, int m, int y);
        MyDate(const MyDate &other);
        ~MyDate();
        void display();
};

#endif