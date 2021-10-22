#include "time.h"

using namespace std;

MyTime::MyTime(){
    second=minute=hour=0;
}

MyTime::MyTime(int h, int m){
    if (h<0 || m<0){
        throw "Error! The time is invalid!";
    }
    h+=(m/60);
    m%=60;

    hour=h;
    minute=m;
    second=0;
}

MyTime::MyTime(int h, int m, int s){
    if (h<0 || m<0 || s<0){
        throw "Error! The time is invalid!";
    }

    m+=s/60;
    s%=60;

    h+=m/60;
    m%=60;

    hour=h;
    minute=m;
    second=s;
}

MyTime::MyTime(int s){
    if (s<0){
        throw "Error! The time is invalid!";
    }
    second = s;
    minute=second/60;
    second%=60;

    hour=minute/60;
    minute%=60;
}

MyTime::MyTime(const MyTime &other){
    hour=other.hour;
    minute=other.minute;
    second=other.second;
}

MyTime::~MyTime(){
    cout << "Delete successfully!\n";
}

void MyTime::display(){
    if (hour<10){
        cout << "0";
    }
    cout << hour << "::";
    if (minute<10){
        cout << "0";
    }
    cout << minute << "::";
    if (second<10){
        cout << "0";
    }
    cout << second << "\n";
}