#include "employee.h"

using namespace std;

string Employee::normalized(string s){
    return (s=="") ? unknown : s;
}

long long Employee::salary(long long num, long long ratePay){
    return num*ratePay;
}

Employee::Employee(string ID, string fullName, string hireDat, string adr){
    id = normalized(ID);
    name = normalized(fullName);
    hireDate = normalized(hireDat);
    address = normalized(adr);
}

void Employee::input(){
    cin.clear();
    fflush(stdin);

    cout << "Input ID: ";
    getline(cin,id);
    id = normalized(id);

    cout << "Input full name: ";
    getline(cin,name);
    name = normalized(name);

    cout << "Input hire date: ";
    getline(cin,hireDate);
    hireDate = normalized(hireDate);

    cout << "Input address: ";
    getline(cin,address);
    address = normalized(id);

    cin.clear();
    fflush(stdin);
}

void Employee::output(){
    cout << "ID: " << id << "\n";
    cout << "Full name: " << name << "\n";
    cout << "Hire date: " << hireDate << "\n";
    cout << "Address: " << address << "\n";
}

OfficeEmployee::OfficeEmployee() :
                Employee("", "", "", ""), workingDays(0){}

OfficeEmployee::OfficeEmployee(string fullName) : 
                Employee("",fullName,"", ""), workingDays(0){}

OfficeEmployee::OfficeEmployee(string fullName, long long numDays) :
                Employee("", fullName, "", ""), workingDays(numDays){}

OfficeEmployee::OfficeEmployee(string ID, string fullName, long long numDays) : 
                Employee(ID, fullName, "", ""), workingDays(numDays){}
                
OfficeEmployee::OfficeEmployee(string ID, string fullName, string hireDat, long long numDays) :
                Employee(ID, fullName, hireDat, ""), workingDays(numDays){}

OfficeEmployee::OfficeEmployee(string ID, string fullName, string hireDate, string adr, long long numDays) :
                Employee(ID, fullName, hireDate, adr), workingDays(numDays){}

long long OfficeEmployee::salary(){
    return Employee::salary(workingDays,ratePay);
}

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

Worker::Worker() :
        Employee("", "", "", ""), items(0){}

Worker::Worker(string fullName) :
        Employee("", fullName, "", ""), items(0){};

Worker::Worker(string fullName, long long numItems) :
        Employee("", fullName, "", ""), items(numItems){}

Worker::Worker(string ID, string fullName, long long numItems) :
        Employee(ID, fullName, "", ""), items(numItems){}

Worker::Worker(string ID, string fullName, string hireDat, long long numItems) :
        Employee(ID, fullName, hireDat, ""), items(numItems){}

Worker::Worker(string ID, string fullName, string hireDate, string adr, long long numItems):
        Employee(ID, fullName, hireDate, adr), items(numItems){}

long long Worker::salary(){
    return Employee::salary(items,ratePay);
}

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