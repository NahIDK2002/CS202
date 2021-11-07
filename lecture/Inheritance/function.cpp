#include "header.h"

using namespace std;

Base::Base(){
    b1=0;
}

Base::Base(int b){
    b1=b;
}

Base::Base(const Base &other){
    b1=other.b1;
}

const Base& Base::operator=(const Base &other){
    b1=other.b1;

    return *this;
}

void Base::display(){
    cout << "b1 = " << b1 << "\n";
}

Derived::Derived() : Base(), d2(0), n(0), arr(0) {}

Derived::Derived(int t) : Base(2*t) {
    d2=t;
    n=t;
    arr = new int[t];
    for(int i=0;i<n;++i){
        arr[i]=0;
    }
}

Derived::Derived(const Derived &other) : Base(other){
    d2=other.d2;
    n=other.n;
    arr = new int[n];
    for (int i=0;i<n;++i){
        arr[i]=other.arr[i];
    }
}

Derived::~Derived(){
    delete[] arr;
    n=0;
    arr=0;
}

const Derived& Derived::operator=(const Derived &other){
    if (this==&other) return *this;
    Base::operator=(other);
    d2=other.d2;
    
    delete[] arr;
    n=other.n;
    arr=new int [n];
    for (int i=0;i<n;++i){
        arr[i]=other.arr[i];
    }

    return *this;
}

void Derived::display(){
    Base::display();
    cout << "d2 = " << d2 << "\n";
    cout << "n = " << n << "\n";
    for (int i=0;i<n;++i){
        cout << arr[i] << " ";
    }
    cout << "\n";
}