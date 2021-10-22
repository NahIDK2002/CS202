#include "lecturer.h"

using namespace std;

bool Lecturer::checkIsValid(int ID, string name, string deg, int n){
    if (ID<=0 || name=="" || n<0) return 0;
    vector<string> listOfDegrees={"unknown","AA","AS","BA","BS","MA","MS","PhD","MD"};
    bool flag=0;
    for (auto s:listOfDegrees){
        if (deg==s){
            return 1;
        }
    }

    return 0;
}

Lecturer::Lecturer(){
    id=0;
    fullname="unknown";
    degree="unknown";
    numberTakenCourses=0;
}

Lecturer::Lecturer(string name){
    if (!checkIsValid(1,name,"unknown",0)){
        throw "Error! The information is invalid!";
    }

    id=0;
    degree="unknow";
    numberTakenCourses=0;
    fullname=name;
}

Lecturer::Lecturer(int ID, string name){
    if (!checkIsValid(ID,name,"unknown",0)){
        throw "Error! The information is invalid!";
    }

    degree="unknow";
    numberTakenCourses=0;

    id=ID;
    fullname=name;
}

Lecturer::Lecturer(int ID, string name, string deg){
    if (!checkIsValid(ID,name,deg,0)){
        throw "Error! The information is invalid!";
    }

    id=ID;
    fullname=name;
    degree=deg;
    numberTakenCourses=0;
}

Lecturer::Lecturer(int ID, string name, string deg, int n){
    if (!checkIsValid(ID,name,deg,n)){
        throw "Error! The information is invalid!";
    }

    id=ID;
    fullname=name;
    degree=deg;
    numberTakenCourses=n;
}

Lecturer::~Lecturer(){
    cout << "Delete successfully!\n";
}

void Lecturer::display(){
    cout << "The information of lecturer:\n";
    cout << "                     ID: " << id << "\n";
    cout << "               Fullname: " << fullname << "\n";
    cout << "                 Degree: " << degree << "\n";
    cout << "Number of taken courses: " << numberTakenCourses << "\n";
}