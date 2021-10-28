#ifndef INTARRAY_H_
#define INTARRAY_H_

#include <iostream>

using namespace std;

class IntArray{
    private:
        int n;
        int *a;

    public:
        IntArray(int size=0, int val=0);
        IntArray(int arr[], int size=0);
        IntArray(const IntArray &other);
        ~IntArray();

        const IntArray& operator=(const IntArray &other);

        const int& operator int()();
        const int& operator [](const int &pos);

        friend istream& operator>>(istream &is, IntArray &newArr);
        friend ostream& operator<<(ostream &os, const IntArray &arr);
};

#endif