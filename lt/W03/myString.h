#ifndef MYSTRING_H_
#define MYSTRING_H_

#include <iostream>
#include <cstring>

class MyString{
    private:
        char *pStr;

    public:
        MyString();
        MyString(const char *s);
        MyString(const MyString &other);
        ~MyString();
        void display();
        MyString& operator=(MyString *other);
};

#endif