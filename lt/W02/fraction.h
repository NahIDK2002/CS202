#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fraction{
    private:
        int num;
        int denom;
        bool isZero();
        int gcd(int a, int b);
        void reduce();

    public:
        Fraction(int n=0, int d=1);
        Fraction(const Fraction &other);
        void output(int &n, int &d);
        void print();
        void add(Fraction other);
        void divide(Fraction other);
};

#endif