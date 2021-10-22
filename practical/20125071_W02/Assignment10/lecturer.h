#ifndef LECTURER_H_
#define LECTURER_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Lecturer{
    private:
        int id;
        string fullname;
        string degree;
        int numberTakenCourses;
        bool checkIsValid(int id, string name, string deg, int n);

    public:
        Lecturer();
        Lecturer(string name);
        Lecturer(int ID, string name);
        Lecturer(int ID, string name, string deg);
        Lecturer(int ID, string name, string deg, int n);
        ~Lecturer();
        void display();
};

#endif