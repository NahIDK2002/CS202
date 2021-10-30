#include "fraction.h"

using namespace std;

int Fraction::gcd(int a, int b){
    if (!a || !b) return b;
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

    if (denom<0){
        num=-num;
        denom=-denom;
    }
}

Fraction::Fraction(int n, int d){
    if (!d){
        throw "Error! The denominator can't be 0!";
    }
    num=n;
    denom=d;

    reduce();
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

const Fraction Fraction::operator+(const Fraction &other){
    return Fraction(num*other.denom+other.num*denom,denom*other.denom);
}

const Fraction Fraction::operator-(const Fraction &other){
    return Fraction(num*other.denom-other.num*denom,denom*other.denom);
}

const Fraction Fraction::operator*(const Fraction &other){
    return Fraction(num*other.num,denom*other.denom);
}

const Fraction Fraction::operator/(const Fraction &other){
    if (!other.num){
        throw "Error! Can't divided by 0!";
    }
    return Fraction(num*other.denom,denom*other.num);
}

const Fraction Fraction::operator+(const int &n){
    return Fraction(num+n*denom,denom);
}

const Fraction operator+(const int &n, const Fraction &f){
    return Fraction(n*f.denom+f.num,f.denom);
}

const Fraction Fraction::operator-(const int &n){
    return Fraction(num-n*denom,denom);
}

const Fraction operator-(const int &n, const Fraction &f){
    return Fraction(f.num-n*f.denom,f.denom);
}

const Fraction Fraction::operator*(const int &n){
    return Fraction(num*n,denom);
}

const Fraction operator*(const int &n, const Fraction &f){
    return Fraction(f.num*n,f.denom);
}

const Fraction Fraction::operator/(const int &n){
    if (!n){
        cout << "Error! Can't divided by 0!\n";
        exit(0);
    }
    return Fraction(num,denom*n);
}

const Fraction operator/(const int &n, const Fraction &f){
    if (!f.num){
        cout << "Error! Can't divided by 0!\n";
        exit(0);
    }
    return Fraction(n*f.denom,f.num);
}

bool Fraction::operator==(const Fraction &other){
    return (num*other.denom==denom*other.num);
}

bool Fraction::operator>(const Fraction &other){
    return (num*other.denom>other.num*denom);
}

bool Fraction::operator<(const Fraction &other){
    return (num*other.denom<other.num*denom);
}

const Fraction& Fraction::operator+=(const Fraction &other){
    num*=other.denom;
    num+=other.num*denom;

    denom*=other.denom;
    reduce();

    return *this;
}

const Fraction& Fraction::operator-=(const Fraction &other){
    num*=other.denom;
    num-=other.num*denom;

    denom*=other.denom;
    reduce();

    return *this;
}

const Fraction& Fraction::operator*=(const Fraction &other){
    num*=other.num;
    denom*=other.denom;
    reduce();

    return *this;
}

const Fraction& Fraction::operator/=(const Fraction &other){
    if (!other.num){
        throw "Error! Can't divided by 0!";
    }
    num*=other.denom;
    denom*=other.num;
    reduce();

    return *this;
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

Fraction::operator float() const{
    return float(num)/float(denom);
}

ostream& operator<<(ostream &os, const Fraction &f){
    os << f.num << "/" << f.denom;

    return os;
}