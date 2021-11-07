#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

const string unknown = "unknown";

class Employee{
private:
    string id="";
    string name;
    string hireDate=unknown;
    string address=unknown;

    string normalized(string s);

public:
    Employee(string ID, string fullName, string hireDat, string adr);
    long long salary(long long num, long long ratePay);
    void input();
    void output();
};

class OfficeEmployee : public Employee{
private:
    long long workingDays;
    long long ratePay=300000;

public:
    OfficeEmployee();
    OfficeEmployee(string fullName);
    OfficeEmployee(string fullName, long long numDays);
    OfficeEmployee(string ID, string fullName, long long numDays);
    OfficeEmployee(string ID, string fullName, string hireDat, long long numDays);
    OfficeEmployee(string ID, string fullName, string hireDate, string adr, long long numDays);
    long long salary();
    void input();
    void output();
};

class Worker : public Employee{
private:
    long long items;
    long long ratePay=20000;

public:
    Worker();
    Worker(string fullName);
    Worker(string fullName, long long numItems);
    Worker(string ID, string fullName, long long numItems);
    Worker(string ID, string fullName, string hireDat, long long numItems);
    Worker(string ID, string fullName, string hireDate, string adr, long long numItems);
    long long salary();
    void input();
    void output();
};


#endif