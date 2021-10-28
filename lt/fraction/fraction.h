#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>
#include <math.h>

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

        Fraction& operator= (const Fraction &other);

        Fraction& operator+=(const Fraction &other);
        Fraction& operator/=(Fraction other);
        
        const Fraction operator+(const Fraction other);
        const Fraction operator/(const Fraction other);

        const Fraction operator+(const int x);
        friend const Fraction operator+(const int &x, const Fraction &f);

        const Fraction& operator++();
        const Fraction operator++(int);
        const Fraction& operator--();
        const Fraction operator--(int);

        const bool operator==(const Fraction& other);
        const bool operator>(const Fraction& other);
        const bool operator>=(const Fraction& other);
        const bool operator<(const Fraction& other);
        const bool operator<=(const Fraction& other);

        friend ostream& operator<<(ostream &os, const Fraction &f);
};

#endif