#include "array.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    MyIntArray a1;
    a1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        MyIntArray a2(5);
        a2.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        MyIntArray a3(7,2);
        a3.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    int a[4]={1,2,3,4};
    MyIntArray a4(0,a);
    a4.display();
    cout << "\n";

    cout << "5th constructor:\n";
    MyIntArray a5(a4);
    a5.display();
    cout << "\n";

    return 0;
}