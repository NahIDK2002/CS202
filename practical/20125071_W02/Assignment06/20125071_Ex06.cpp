#include "time.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    MyTime t1;
    t1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        MyTime t2(15,4);
        t2.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        MyTime t3(2,45,17);
        t3.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        MyTime t4(123456);
        t4.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    MyTime t5(t1);
    t5.display();

    return 0;
}