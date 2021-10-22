#include "student.h"

using namespace std;

bool Student::checkIsValid(int ID, char *name, char *adr, double GPA){
    if (ID<0 || !name || name[0]==0 || !adr || adr[0]==0 || GPA<0) return 0;
    else return 1;
}

Student::Student(){
    id=0;
    fullname = "unknown";
    address = "unknown";
    gpa=0;
}

Student::Student(char *name){
    if (!checkIsValid(1,name,"unknown",1)){
        throw "Error! The information is invalid!";
    }
    
    id=0;
    address = "unknown";
    gpa=0;
    fullname = name;
}

Student::Student(int ID, char *name){
    if (!checkIsValid(ID,name,"unknown",1)){
        throw "Error! The information is invalid!";
    }

    address="unknown";
    gpa=0;
    id=ID;
    fullname=name;
}

Student::Student(int ID, char *name, char *adr){
    if (!checkIsValid(ID,name,adr,1)){
        throw "Error! The information is invalid!";
    }

    gpa=0;
    id=ID;
    fullname=name;
    address=adr;
}

Student::Student(int ID, char *name, char *adr, double GPA){
    if (!checkIsValid(ID,name,adr,GPA)){
        throw "Error! The information is invalid!";
    }

    id=ID;
    fullname=name;
    address=adr;
    gpa=GPA;
}

Student::~Student(){
    delete[] fullname;
    delete[] address;
    cout << "Delete successfully!\n";
}

void Student::display(){
    cout << "The information of Student:\n";
    cout << "      ID: " << id << "\n";
    cout << "Fullname: " << fullname << "\n";
    cout << " Address: " << address << "\n";
    cout << "     GPA: " << gpa << "\n";
}