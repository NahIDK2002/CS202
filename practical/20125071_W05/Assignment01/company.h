#ifndef COMPANY_H
#define COMPANY_H

#include <iostream>
#include <string>
#include <vector>

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
    virtual ~Employee();
    virtual const long long salary() const;
    virtual void input();
    virtual void output() const;
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
    const long long salary() const;
    void input();
    void output() const;
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
    const long long salary() const;
    void input();
    void output() const;
};

class Company{
private:
    vector<Employee*> employee;

public:
    ~Company();
    void input();
    void output() const;
    const long long totalSalary() const;
    const vector<Employee*> mostPaidEmployee() const;
};

#endif