#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

class MyIntArray{
    private:
        int n;
        int *a;

    public:
        MyIntArray();
        MyIntArray(int size);
        MyIntArray(int size, int val);
        MyIntArray(int size, int array[]);
        MyIntArray(const MyIntArray &other);
        ~MyIntArray();
        void display();
};

#endif