#include "fraction.h"

using namespace std;

bool Fraction::isNumber(char c){
    return ('0'<=c && c<='9');
}

int Fraction::convertStrToInt(string s, int &pos){
    if (pos>=s.length()){
        throw "Converting to int fail!\n";
    }
    int ans=0;
    int sign=1;
    if (s[pos]=='-'){
        sign=-1;
        pos++;
    }
    else if (s[pos]=='+') {
        pos++;
    }

    while (pos<s.length() && isNumber(s[pos])){
        ans*=10;
        ans+=s[pos]-'0';
        ++pos;
    }
    if (pos>=s.length()){
        return ans*sign;
    }
    if (s[pos]=='/'){
        return ans*sign;
    }
    else{
        throw "Converting to int fail!\n";
    }
    return 0;
}

int Fraction::gcd(int a, int b){
    if (!a || !b) return 1;
    a=abs(a); b=abs(b);
    while (a!=b){
        if (a<b) b-=a;
        else a-=b;
    }
    
    return a;
}

void Fraction::reduce(){
    int GCD=gcd(numerator,denominator);
    numerator/=GCD;
    denominator/=GCD;

    if (numerator==0){
        denominator=abs(denominator);
    }
    else if (numerator>0){
        if (denominator<0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }
    else{
        if (denominator<0){
            numerator=-numerator;
            denominator=-denominator;
        }
    }
}

Fraction::Fraction(){
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int n){
    numerator=n;
    denominator=1;
}

Fraction::Fraction(int n, int d){
    if (!d){
        throw "Error! Denominator can't be 0!\n";
    }
    numerator=n;
    denominator=d;
    reduce();
}

Fraction::Fraction(string s){
    int pos=0;
    numerator = 0;
    denominator=1;
    try{
        numerator=convertStrToInt(s,pos);
        pos++;
        denominator=convertStrToInt(s,pos);
        if (!denominator){
            throw "Error! Denominator can't be 0!\n";
        }
    }
    catch (const char *msg){
        numerator=0;
        denominator=1;
        cout << msg;
        return;
    }
    reduce();
}

Fraction::Fraction(Fraction &other){
    numerator=other.numerator;
    denominator=other.denominator;
}

void Fraction::display(){
    cout << "Fraction: " << numerator << "/" << denominator << "\n";
}

Fraction::~Fraction(){
    cout << "Delete successfully\n";
}