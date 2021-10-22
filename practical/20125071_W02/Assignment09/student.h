#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <cstring>

using namespace std;

class Student{
    private:
        int id;
        char* fullname;
        char* address;
        double gpa;
        bool checkIsValid(int ID, char *name, char *adr, double GPA);

    public:
        Student();
        Student(char *name);
        Student(int ID, char *name);
        Student(int ID, char *name, char *adr);
        Student(int ID, char *name, char *adr, double GPA);
        ~Student();
        void display();
};

#endif