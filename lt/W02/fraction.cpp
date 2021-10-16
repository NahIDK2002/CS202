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
    int GCD=gcd(num,denom);
    num/=GCD;
    denom/=GCD;
}

bool Fraction::isZero(){
    return (!num);
}

Fraction::Fraction(int n, int d){
    if (!d) return;
    num=n;
    denom=d;
}

Fraction::Fraction(const Fraction &other){
    num=other.num;
    denom=other.denom;
}

void Fraction::output(int &n, int &d){
    n=num;
    d=denom;
}

void Fraction::print(){
    cout << "Fraction: " << num << "/" << denom << "\n";
}

void Fraction::add(Fraction other){
    num*=other.denom;
    num+=other.num;

    denom*=other.denom;

    reduce();
}

void Fraction::divide(Fraction other){
    if (other.isZero()) return;

    num*=other.denom;
    denom*=other.num;

    reduce();
}