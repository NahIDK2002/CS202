#include "date.h"

using namespace std;

bool MyDate::checkIsLeapYear(){
    return (!(year%400) || (!(year%4) && year%100));
}

bool MyDate::checkIsValid(){
    if (checkIsLeapYear()){
        if (month==2){
            return (0<day && day<=29);
        }
        else if (month==1 || month==3 || month==5 || month==7 || month==8 || month == 10 || month==12){
                return (0<day && day<=31);
        }
        else if (month==4 || month==6 || month == 9 || month==11){
            return (0<day && day<=30);
        }
        else return 0;
    }
    else{
        if (month==2){
            return (0<day && day<=28);
        }
        else if (month==1 || month==3 || month==5 || month==7 || month==8 || month == 10 || month==12){
                return (0<day && day<=31);
        }
        else if (month==4 || month==6 || month == 9 || month==11){
            return (0<day && day<=30);
        }
        else return 0;
    }
}

MyDate::MyDate(){
    time_t t=time(0);
    tm *now=localtime(&t);
    day = now->tm_mday;
    month = 1+now->tm_mon;
    year = 1900+now->tm_year;
}

MyDate::MyDate(int d){
    if (d<=0 || d>31){
        throw "Error! The date is invalid!";
    }
    time_t t=time(0);
    tm *now=localtime(&t);
    month = 1+now->tm_mon;
    year = 1900+now->tm_year;
    day = d;
    while (!checkIsValid()){
        month++;
        month%=12;
        month++;
    }
}

MyDate::MyDate(int d, int m){
    if (d<=0 || d>31 || m<0 || m>12){
        throw "Error! The date is not valid!";
    }
    time_t t=time(0);
    tm *now=localtime(&t);
    year = 1900+now->tm_year;
    month=m;
    day=d;

    if (d==29 && month==2){
        bool k=checkIsValid();
        while (!k){
            ++year;
            k=checkIsValid();
        }
    }
    else if (!checkIsValid()){
        throw "Error! The date is not valid!";
    }
}

MyDate::MyDate(int d, int m, int y){
    day=d;
    month=m;
    year=y;
    if (!checkIsValid()){
        throw "Error! The date is not valid!";
    }
}

MyDate::MyDate(const MyDate &other){
    day=other.day;
    month=other.month;
    year=other.year;
}

MyDate::~MyDate(){
    cout << "Delete successfully!\n";
}

void MyDate::display(){
    cout << "Year: " << year << "\n";
    cout << "Month: " << month << "\n";
    cout << "Day: " << day << "\n";
}