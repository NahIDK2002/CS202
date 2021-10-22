#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

class MyTime{
    private:
        int hour;
        int minute;
        int second;

    public:
        MyTime();
        MyTime(int h, int m);
        MyTime(int h, int m, int s);
        MyTime(int totalSec);
        MyTime(const MyTime &other);
        ~MyTime();
        void display();
};

#endif