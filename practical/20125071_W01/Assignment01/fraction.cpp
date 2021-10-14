#include "fraction.h"

using namespace std;

void readFile(Fraction &a, Fraction &b, string file){
    ifstream f;
    f.open(file);
    if (!f.is_open()){
        f.close();
        throw "Error! Can't open file!";
    }

    int num,denom;
    f >> num >> denom;
    a.input(num,denom);
    
    f >> num >> denom;
    b.input(num,denom);

    f.close();
}

int Fraction::gcd(int a, int b){
    if (!a || !b){
        return !a ? b:a;
    }

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

void Fraction::input(int n, int d){
    if (!d){
        throw "Error! The denominator can't be 0!";
    }
    num=n;
    denom=d;

    reduce();
}

void Fraction::output(int &n, int &d){
    n=num;
    d=denom;
}

void Fraction::display(){
    cout << num << "/" << denom;
}

void Fraction::add(Fraction other){
    num*=other.denom;
    num+=other.num*denom;
    denom*=other.denom;

    reduce();
}

void Fraction::substract(Fraction other){
    num*=other.denom;
    num-=other.num*denom;
    denom*=other.denom;

    reduce();
}

void Fraction::multiply(Fraction other){
    num*=other.num;
    denom*=other.denom;

    reduce();
}

void Fraction::divide(Fraction other){
    if (other.isZero()){
        throw "Error! Divided by 0!";
    }

    num*=other.denom;
    denom*=other.num;

    reduce();
}

int Fraction::compare(Fraction other){
    int a=num*other.denom, b=other.num*denom;
    if (a<b) return -1;
    else if (a==b) return 0;
    else return 1;
}

bool Fraction::isPositive(){
    return ((num>0 && denom>0) || (num<0 && denom<0));
}

bool Fraction::isNegative(){
    return ((num<0 && denom>0) || (num>0 && denom<0));
}

bool Fraction::isZero(){
    return !num;
}