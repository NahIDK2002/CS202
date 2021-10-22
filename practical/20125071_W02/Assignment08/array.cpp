#include "array.h"

using namespace std;

MyIntArray::MyIntArray(){
    n=0;
    a=0;
}

MyIntArray::MyIntArray(int size){
    if (size<0){
        throw "Error! The size can't be a negative number!";
    }
    n=size;
    a = new int[n];
    for (int i=0;i<n;++i) a[i]=0;
}

MyIntArray::MyIntArray(int size, int val){
    if (size<0){
        throw "Error! The size can't be a negative number!";
    }
    n=size;
    a = new int[n];
    for (int i=0;i<n;++i) a[i]=val;
}

MyIntArray::MyIntArray(int size, int array[]){
    n=size;
    a=new int[n];
    for (int i=0;i<n;++i) a[i]=array[i];
}

MyIntArray::MyIntArray(const MyIntArray &other){
    n=other.n;
    a=new int[n];
    for (int i=0;i<n;++i) a[i]=other.a[i];
}

MyIntArray::~MyIntArray(){
    delete[] a;
    cout << "Delete successfully!\n";
}

void MyIntArray::display(){
    cout << "Size: " << n << "\nValue: ";
    for (int i=0;i<n;++i) cout << a[i] << " ";
    cout << "\n";
}