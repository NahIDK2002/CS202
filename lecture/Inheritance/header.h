#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <cstring>

using namespace std;

class Base{
private:
    int b1;
    
public:
    Base();
    Base(int b);
    Base(const Base &other);
    const Base& operator=(const Base &other);
    void display();
};

class Derived : public Base{
private:
    int d2;
    int n;
    int *arr;

public:
    Derived();
    Derived(int t);
    Derived(const Derived &other);
    ~Derived();
    const Derived& operator=(const Derived &other);
    void display();
    
};

#endif