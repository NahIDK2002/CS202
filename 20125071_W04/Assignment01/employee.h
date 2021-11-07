#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

class Employee{
private:
    string id="";
    string name;
    string hireDate="unknown";
    string address="unknown";

public:
    Employee(string fullName);
    Employee(string ID, string fullName);
    Employee(string ID, string fullName, string hireDat);
    Employee(string ID, string fullName, string hireDat, string adr);
    long long salary(long long num, long long ratePay);
    void input();
    void output();
};

class OfficeEmployee : public Employee{
private:
    long long workingDays;
    long long ratePay = 300000;

public:
    OfficeEmployee(string ID, string fullName, string hireDate, string adr, long long numDays);
    void input();
    void output();
};

class Worker : public Employee{
private:
    long long items;
    long long ratePay = 20000;

public:
    Worker(string ID, string fullName, string hireDate, string adr, long long numItems);
    void input();
    void output();
};


#endif