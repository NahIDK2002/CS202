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
        cout << "Error! The denominator can't be a 0!";
        exit(0);
    }
    num=n;
    denom=d;
    reduce();
}

Fraction::Fraction(const Fraction &other){
    num=other.num;
    denom=other.denom;
}

// Fraction& Fraction::operator=(const Fraction &other){
//     num=other.num;
//     denom=other.denom;

//     return *this;
// }

Fraction& Fraction::operator+=(const Fraction &other){
    num*=other.denom;
    num+=other.num*denom;

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

// const Fraction Fraction::operator+(const Fraction other){
//     return Fraction(num*other.denom + other.num*denom,denom*other.denom);
// }

const Fraction Fraction::operator/(Fraction other){
    if (other.isZero()){
        throw "Error! Can't divided by 0!";
    }
    return Fraction(num*other.denom,denom*other.num);
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

// const Fraction operator+ (const int &x, const Fraction &f){
//      return Fraction(x*f.denom+f.num,f.denom);
// }

Fraction operator+(Fraction a, Fraction b){
    Fraction result(a);
    result+=b;

    return result;
}

ostream& Fraction::display(ostream &os){
    os << num << "/" << denom;
    return os;
}

ostream& operator<< (ostream &os,Fraction f){
    f.display(os);
    return os;
}