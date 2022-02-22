#include <iostream>

using namespace std;

class MyClass{
private:
    int val;
    MyClass(int t) : val(t){}
    const MyClass& operator=(const MyClass &other){
        val=other.val;
        return *this;
    }

public:
    static MyClass getInstance(int val){
        static MyClass tmp(val);
        return tmp;
    }

    void print(){
        cout << "val = " << val << "\n";
    }
};

int main(){
    MyClass m=MyClass::getInstance(6);
    m.print();
    MyClass n=MyClass::getInstance(1);
    n.print();

    return 0;
}