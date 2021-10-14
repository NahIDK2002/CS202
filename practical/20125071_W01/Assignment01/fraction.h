#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Fraction{
    private:
        int num,denom;

        int gcd(int a, int b);
        void reduce();

    public:
        void input(int n, int d);
        void output(int &n, int &d);
        void display();
        void add(Fraction other);
        void substract(Fraction other);
        void multiply(Fraction other);
        void divide(Fraction other);
        int compare(Fraction other);
        bool isPositive();
        bool isNegative();
        bool isZero();
};

void readFile(Fraction &a, Fraction &b, string file);

#endif