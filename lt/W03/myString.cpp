#include "myString.h"

using namespace std;

MyString::MyString():pStr(0){}

MyString::MyString(const char *s){
    pStr = new char [strlen(s)+1];
    strcpy(pStr,s);
}

MyString::MyString(const MyString &other){
    if (!other.pStr){
        pStr=0;
        return;
    }
    strcpy(pStr,other.pStr);
}

MyString::~MyString(){
    delete[] pStr;
}

void MyString::display(){
    cout << "My string: " << pStr << "\n";
}

void MyString::operator=(const MyString &other){
    if (!other.pStr){
        pStr = 0;
        return;
    }
    delete[] pStr;
    pStr = new char [strlen(other.pStr)+1];
    strcpy(pStr,other.pStr);
}