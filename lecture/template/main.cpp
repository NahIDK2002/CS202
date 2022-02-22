#include <iostream>

using namespace std;

class Test{
private:
    static int count;

public:

    Test(){
        count++;
    }

    Test(const Test &other){
        count++;
    }

    ~Test(){
        count--;
    }

    int getCount(){
        return count;
    }
};

void foo(Test a){
    Test b;
    cout << b.getCount() << "\n";
}

int Test::count =0;

int main(){
    Test a;
    cout << a.getCount() << "\n";
    foo(a);
    cout << a.getCount() << "\n";

    return 0;
}