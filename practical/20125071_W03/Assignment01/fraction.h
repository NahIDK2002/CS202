#ifndef FRACION_H_
#define FRACTION_H_

#include <iostream>
#include <math.h>

using namespace std;

class Fraction{
    private:
        int num;
        int denom;
        int gcd(int a, int b);
        void reduce();

    public:
        Fraction(int n=0, int denom=1);
        Fraction(const Fraction &other);
        Fraction& operator=(const Fraction &other);

        const Fraction operator+(const Fraction &other);
        const Fraction operator-(const Fraction &other);
        const Fraction operator*(const Fraction &other);
        const Fraction operator/(const Fraction &other);

        const Fraction operator+(const int &n);
        friend const Fraction operator+(const int &n, const Fraction &f);
        const Fraction operator-(const int &n);
        friend const Fraction operator-(const int &n, const Fraction &f);
        const Fraction operator* (const int &n);
        friend const Fraction operator*(const int &n, const Fraction &f);
        const Fraction operator/ (const int &n);
        friend const Fraction operator/ (const int &n, const Fraction &f);

        bool operator==(const Fraction &other);
        bool operator>(const Fraction &other);
        bool operator<(const Fraction &other);

        const Fraction& operator+=(const Fraction &other);
        const Fraction& operator-=(const Fraction &other);
        const Fraction& operator*=(const Fraction &other);
        const Fraction& operator/=(const Fraction &other);

        const Fraction& operator++();
        const Fraction operator++(int);
        const Fraction& operator--();
        const Fraction operator--(int);

        operator float() const;

        friend ostream& operator<<(ostream& os, const Fraction &dt);
};

#endif