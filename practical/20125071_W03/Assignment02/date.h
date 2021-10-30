#ifndef DATE_H_
#define DATE_H_

#include <iostream>
#include <ctime>

using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;
        bool isLeapYear(int y);
        int numDaysInMonth(int y, int m);

    public:
        Date();
        Date(int y);
        Date(int y, int m);
        Date(int y, int m, int d);
        Date(const Date &other);

        const Date& operator=(const Date &other);

        const Date Tomorrow();
        const Date Yesterday();

        bool operator==(const Date &other);
        bool operator!=(const Date &other);
        bool operator>(const Date &other);
        bool operator>=(const Date &other);
        bool operator<(const Date &other);
        bool operator<=(const Date &other);

        const Date operator+(const int &n);
        const Date operator-(const int &n);

        const Date operator++();
        const Date operator++(int);
        const Date operator--();
        const Date operator--(int);

        friend ostream& operator<< (ostream &os, const Date &d);
        friend istream& operator>>(istream &is, Date &d);
};



#endif