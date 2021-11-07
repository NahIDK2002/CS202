#include "employee.h"

using namespace std;

long long Employee::salary(long long num, long long ratePay){
    return num*ratePay;
}

Employee::Employee(string fullName){
    name=fullName;
}

Employee::Employee(string ID, string fullName){
    id=ID;
    name=fullName;
}

Employee::Employee(string ID, string fullName, string hireDat){
    id=ID;
    name=fullName;
    hireDate=hireDat;
}

Employee::Employee(string ID, string fullName, string hireDat, string adr){
    id=ID;
    name=fullName;
    hireDate = hireDat;
    address=adr;
}

void Employee::input(){
    cout << "Input ID: ";
    getline(cin,id);
    cout << "Input full name: ";
    getline(cin,name);
    cout << "Input hire date: ";
    getline(cin,hireDate);
    cout << "Input address: ";
    getline(cin,address);
}

void Employee::output(){
    cout << "ID: " << id << "\n";
    cout << "Full name: " << name << "\n";
    cout << "Hire date: " << hireDate << "\n";
    cout << "Address: " << address << "\n";
}

OfficeEmployee::OfficeEmployee(string ID, string fullName, string hireDate, string adr, long long numDays) :
                Employee(ID, fullName, hireDate, adr), workingDays(numDays){}

void OfficeEmployee::input(){
    Employee::input();
    cout << "Number of working days: ";
    cin >> workingDays;
}

void OfficeEmployee::output(){
    cout << "Information of office employee:\n";
    Employee::output();
    cout << "Number of working days: " << workingDays << "\n";
}

Worker::Worker(string ID, string fullName, string hireDate, string adr, long long numItems):
        Employee(ID, fullName, hireDate, adr), items(numItems){}

void Worker::input(){
    Employee::input();
    cout << "Number of items: ";
    cin >> items;
}

void Worker::output(){
    cout << "Information of worker:\n";
    Employee::output();
    cout << "Number of items: " << items << "\n";
}