#include "company.h"

using namespace std;

string Employee::normalized(string s){
    return (s=="") ? unknown : s;
}

Employee::Employee(string ID, string fullName, string hireDat, string adr){
    id = normalized(ID);
    name = normalized(fullName);
    hireDate = normalized(hireDat);
    address = normalized(adr);
}

Employee::~Employee(){}

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
    address = normalized(address);

    cin.clear();
    fflush(stdin);
}

void Employee::output() const{
    cout << "ID: " << id << "\n";
    cout << "Full name: " << name << "\n";
    cout << "Hire date: " << hireDate << "\n";
    cout << "Address: " << address << "\n";
}

const long long Employee::salary() const{
    return 0;
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

const long long OfficeEmployee::salary() const{
    return workingDays*ratePay;
}

void OfficeEmployee::input(){
    Employee::input();
    cout << "Number of working days: ";
    cin >> workingDays;
}

void OfficeEmployee::output() const{
    cout << "Information of office employee:\n";
    Employee::output();
    cout << "Number of working days: " << workingDays << "\n";
    cout << "Salary: " << salary() << "\n";
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

const long long Worker::salary() const{
    return items*ratePay;
}

void Worker::input(){
    Employee::input();
    cout << "Number of items: ";
    cin >> items;
}

void Worker::output() const{
    cout << "Information of worker:\n";
    Employee::output();
    cout << "Number of items: " << items << "\n";
    cout << "Salary: " << salary() << "\n";
}

Company::~Company(){
    int n=employee.size();
    for (int i=0;i<n;++i) delete employee[i];
}

void Company::input(){
    int n;
    cout << "Input number of employee: ";
    cin >> n;
    if (!n) return;
    for (int i=0;i<n;++i){
        int choice;
        Employee *tmp=0;
        do{
            cout << "Input type of employee (0: Office employee, 1: Worker): ";
            cin >> choice;
            if (!choice){
                tmp=new OfficeEmployee;
            }
            else if (choice==1){
                tmp=new Worker;
            }
            else cout << "Sorry! I don't understand.";
        }
        while (choice!=1 && choice!=0);
        tmp->input();
        employee.push_back(tmp);
    }
}

void Company::output() const{
    cout << "Information of all employee:\n";
    int n = employee.size();
    for (int i=0;i<n;++i){
        cout << "Information of employee number " << i+1 << ":\n";
        cout << "\n";
        employee[i]->output();
        cout << "\n";
    }

    cout << "\n\n";
}

const long long Company::totalSalary() const{
    long long sum=0;
    for (auto e:employee){
        sum+=e->salary();
    }

    return sum;
}

const vector<Employee *> Company::mostPaidEmployee() const{
    vector<Employee *> mostPaid;
    mostPaid.push_back(employee[0]);
    long long highestSalary=employee[0]->salary();
    int n=employee.size();
    for (int i=1;i<n;++i){
        long long salary=employee[i]->salary();
        if (salary>highestSalary){
            mostPaid.clear();
            highestSalary=salary;
        }
        if (salary==highestSalary){
            mostPaid.push_back(employee[i]);
        }
    }

    return mostPaid;
}