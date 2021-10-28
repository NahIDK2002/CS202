#include "fraction.h"

using namespace std;

int Fraction::gcd(int a, int b){
    if (!b) return 1;
    while (a!=b){
        if (a<b) b-=a;
        else a-=b;
    }

    return a;
}

void Fraction::reduce(){
    int GCD=gcd(abs(num),abs(denom));
    num/=GCD;
    denom/=GCD;
}

bool Fraction::isZero(){
    return (!num);
}

Fraction::Fraction(int n, int d){
    if (!d){
        throw "Error! The denominator can't be a 0!";
    }
    num=n;
    denom=d;
}

Fraction::Fraction(const Fraction &other){
    num=other.num;
    denom=other.denom;
}

Fraction& Fraction::operator=(const Fraction &other){
    num=other.num;
    denom=other.denom;

    return *this;
}

Fraction& Fraction::operator+=(const Fraction &other){
    num*=other.denom;
    num+=other.num;

    denom*=other.denom;

    reduce();

    return *this;
}

Fraction& Fraction::operator/=(Fraction other){
    if (other.isZero()){
        throw "Error! Can't be divided by 0!";
    }

    num*=other.denom;
    denom*=other.num;

    reduce();
    return *this;
}

const Fraction Fraction::operator+(const Fraction other){
    return Fraction(num*other.denom + other.num*denom,denom*other.denom);
}

const Fraction Fraction::operator/(Fraction other){
    if (other.isZero()){
        throw "Error! Can't divided by 0!";
    }
    return Fraction(num*other.denom,denom*other.num);
}

const Fraction Fraction::operator+(const int x){
    return Fraction(num + x*denom,denom);
}

const Fraction& Fraction::operator++(){
    num+=denom;
    reduce();
    return *this;
}

const Fraction Fraction::operator++(int){
    Fraction f=*this;
    this->num+=f.denom;
    this->reduce();

    return f;
}

const Fraction& Fraction::operator--(){
    num-=denom;
    reduce();

    return *this;
}

const Fraction Fraction::operator--(int){
    Fraction f=*this;
    this->num-=f.denom;
    this->reduce();

    return f;
}

const bool Fraction::operator==(const Fraction &other){
    return (num*other.denom==other.num*denom);
}

const bool Fraction::operator>(const Fraction &other){
    return (num*other.denom>other.num*denom);
}

const bool Fraction::operator>=(const Fraction &other){
    return (num*other.denom>=other.num*denom);
}

const bool Fraction::operator<(const Fraction &other){
    return (num*other.denom<other.num*denom);
}

const bool Fraction::operator<=(const Fraction &other){
    return (num*other.denom<=other.num*denom);
}

ostream& operator<< (ostream &os,const Fraction &f){
    os << "Fraction: " << f.num << "/" << f.denom << "\n";

    return os;
}

const Fraction operator+ (const int &x, const Fraction &f){
    return Fraction(x*f.denom+f.num,f.denom);
}