#include "intarray.h"

using namespace std;

IntArray::IntArray(int size, int val){
    if (!size){
        a=0;
    }
    else{
       n=size; 
        a = new int [n];
        for (int i=0;i<n;++i){
            a[i]=val;
        }
    }
}

IntArray::IntArray(int arr[], int size){
    if (!size){
        a=0;
    } 
    else{
        n=size;
        a = new int [n];
        for (int i=0;i<n;++i){
            a[i]=arr[i];
        }
    }
}

IntArray::IntArray(const IntArray &other){
    n=other.n;
    a=new int[n];
    for (int i=0;i<n;++i){
        a[i]=other.a[i];
    }
}

IntArray::~IntArray(){
    delete[] a;
    cout << "Delete successfully!\n";
}

const IntArray& IntArray::operator=(const IntArray &other){
    if (&other==this) return *this;
    delete[] a;
    n=other.n;
    a=new int [n];
    for (int i=0;i<n;++i){
        a[i]=other.a[i];
    }

    return *this;
}

int& IntArray::operator[](const int &pos){
    if (pos<0 || pos>=n){
        cout << "Error! Accessing array out of bound!\n";
        exit(0);
    }
    return a[pos];
}

IntArray::operator int() const{
    return n;
}

istream& operator>>(istream &is, IntArray &newArr){
    is >> newArr.n;
    newArr.a = new int [newArr.n];
    for (int i=0;i<newArr.n;++i){
        is >> newArr.a[i];
    }
    return is;
}

ostream& operator<<(ostream &os, const IntArray &arr){
    os << "Size: " << arr.n << "\n";
    os << "Elements: ";
    for (int i=0;i<arr.n;++i){
        os << arr.a[i] << " ";
    }
    return os;
}