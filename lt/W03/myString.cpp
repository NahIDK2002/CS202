#include "myString.h"

using namespace std;

MyString::MyString():pStr(0){}

MyString::MyString(const char *s){
    pStr = new char [strlen(s)+1];
    strcpy(pStr,s);
}


MyString::~MyString(){
    delete[] pStr;
}

void MyString::display(){
    cout << "My string: " << pStr << "\n";
}

MyString::MyString(const MyString &other){
    if (!other.pStr){
        pStr=0;
        return;
    }
    strcpy(pStr,other.pStr);
}

MyString& MyString::operator=(MyString *other){
    // if (this==&other) return *this;
    // if (!other.pStr){
    //     pStr = 0;
    //     return *this;
    // }
    // delete[] pStr;
    // pStr = new char [strlen(other.pStr)+1];
    // strcpy(pStr,other.pStr);
    // return *this;

    swap(pStr,other->pStr);
    return *this;
}