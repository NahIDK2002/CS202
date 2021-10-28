#include "intarray.h"

using namespace std;

IntArray::IntArray(int size, int val){
    n=size;
    if (!n){
        a=0;
    }
    else{
        a = new int [n];
        for (int i=0;i<n;++i){
            a[i]=val;
        }
    }
}

IntArray::IntArray(int arr[], int size){
    n=size;
    if (!n){
        a=0;
    } 
    else{
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