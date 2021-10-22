#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Fraction{
    private:
        int numerator;
        int denominator;
        int convertStrToInt(string s, int &pos);
        bool isNumber(char c);
        int gcd(int a, int b);
        void reduce();

    public:
        Fraction();
        Fraction(int n);
        Fraction(int n, int d);
        Fraction(Fraction &other);
        Fraction(string f);
        void display();
        ~Fraction();
};

#endif