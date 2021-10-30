#include "date.h"

using namespace std;

bool Date::isLeapYear(int y){
    return (!(y%400) || (!(y%4) && y%100));
}

int Date::numDaysInMonth(int y, int m){
    if (m==2){
        if (isLeapYear(y)) return 29;
        else return 28;
    }
    else if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
        return 31;
    }
    else return 30;
}

Date:: Date(){
    time_t now= time(0);
    tm *ltm=localtime(&now);

    year=1900+ltm->tm_year;
    month=1+ltm->tm_mon;
    day = ltm->tm_mday;
}

Date::Date(int y){
    year=y;
    month=1;
    day=1;
}

Date::Date(int y, int m){
    if (m<=0 || m>12){
        cout << "Error! The month is invalid!\n";
        exit(0);
    }
    year=y;
    month=m;
    day=1;
}

Date::Date(int y, int m, int d){
    if (m<=0 || m>12){
        cout << "Error! The month is invalid!\n";
        exit(0);
    }
    if (d<=0 && d>numDaysInMonth(y,m)){
        cout << "Error! The day in invalid!\n";
        exit(0);
    }
    year=y;
    month=m;
    day=d;
}

Date::Date(const Date &other){
    year=other.year;
    month=other.month;
    day=other.day;
}

const Date& Date::operator=(const Date &other){
    year=other.year;
    month=other.month;
    day=other.day;

    return *this;
}

const Date Date::Tomorrow(){
    Date tomorrow=*this;
    if (day==numDaysInMonth(year,month)){
        if (month==12){
            tomorrow.year++;
            tomorrow.month=1;
        }
        else tomorrow.month++;
        tomorrow.day=1;
    }
    else tomorrow.day++;

    return tomorrow;
}

const Date Date::Yesterday(){
    Date yesterday=*this;
    if (day==1){
        if (month=1){
            yesterday.year--;
            yesterday.month=12;
        }
        else yesterday.month--;
        yesterday.day=numDaysInMonth(yesterday.year,yesterday.month);
    }
    else yesterday.day--;

    return yesterday;
}

bool Date::operator==(const Date &other){
    return (year==other.year) && (month=other.month) && day==other.day;
}

bool Date::operator!=(const Date &other){
    return (year!=other.year || month!=other.year || day!=other.day);
}

bool Date::operator>(const Date &other){
    if (year>other.year){
        return 1;
    }
    else if (year<other.year){
        return 0;
    }

    if (month>other.month){
        return 1;
    }
    else if (month<other.month){
        return 0;
    }

    return (day>other.day);
}

bool Date::operator>=(const Date &other){
    if (year>other.year){
        return 1;
    }
    else if (year<other.year){
        return 0;
    }

    if (month>other.month){
        return 1;
    }
    else if (month<other.month){
        return 0;
    }

    return day>=other.day;
}

bool Date::operator<(const Date &other){
    if (year<other.year){
        return 1;
    }
    else if (year>other.year){
        return 0;
    }
    
    if (month<other.month){
        return 1;
    }
    else if (month>other.month){
        return 0;
    }

    return (day<other.day);
}

bool Date::operator<=(const Date &other){
    if (year<other.year){
        return 1;
    }
    else if (year>other.year){
        return 0;
    }

    if (month<other.month){
        return 1;
    }
    else if (month>other.month){
        return 0;
    }

    return day<=other.day;
}

const Date Date::operator+(const int &n){
    Date newDate=*this;
    int days=n;
    int k=numDaysInMonth(newDate.year,newDate.month);
    while (newDate.day+days>k){
        days-=k-newDate.day+1;
        newDate.day=1;
        newDate.month++;
        if (newDate.month>=13){
            newDate.year++;
            newDate.month=1;
        }
        k=numDaysInMonth(newDate.year,newDate.month);
    }
    newDate.day+=days;

    return newDate;
}

const Date Date::operator-(const int &n){
    Date newDate=*this;
    int days=n;
    while (newDate.day-days<=0){
        days-=newDate.day;
        newDate.month--;
        if (newDate.month<=0){
            newDate.year--;
            newDate.month=12;
        }
        newDate.day=numDaysInMonth(newDate.year,newDate.month);
    }
    
    return newDate;
}

const Date& Date::operator+=(const int &n){
    *this=*this+n;
    return *this;
}

const Date& Date::operator-=(const int &n){
    *this=*this-n;
    return *this;
}

const Date Date::operator++(){
    day++;
    if (day>this->numDaysInMonth(year,month)){
        day=1;
        month++;
        if (month>=13){
            month=1;
            year++;
        }
    }

    return *this;
}

const Date Date::operator++(int){
    Date d=*this;
    day++;
    if (day>numDaysInMonth(year,month)){
        day=1;
        month++;
        if (month>=13){
            month=1;
            year++;
        }
    }

    return d;
}

const Date Date::operator--(){
    day--;
    if (day<=0){
        month--;
        if (month<=0){
            month=12;
            year--;
        }
        day=numDaysInMonth(year,month);
    }

    return *this;
}

const Date Date::operator--(int){
    Date d=*this;
    day--;
    if (day<=0){
        month--;
        if (month<=0){
            month=12;
            year--;
        }
        day=numDaysInMonth(year,month);
    }

    return d;
}

Date::operator int(){
    int ans=0;
    int tDay=day, tMon=month;
    while (tMon>1){
        ans+=numDaysInMonth(year,tMon);
        tMon--;
    }
    return ans+tDay-1;
}

Date::operator long(){
    long ans=0;
    long tDay=day, tMon=month, tYear=year;
    while (tYear>1){
        ans += isLeapYear(tYear) ? 366:365;
        tYear--;
    }
    
    while (tMon>1){
        ans+= numDaysInMonth(tYear,tMon);
        tMon--;
    }

    return ans+tDay-1;
}

ostream& operator<< (ostream&os, const Date &d){
    os << d.day << "/" << d.month << "/" << d.year;

    return os;
}

istream& operator>> (istream &is, Date &d){
    is >> d.day >> d.month >> d.year;

    return is;
}