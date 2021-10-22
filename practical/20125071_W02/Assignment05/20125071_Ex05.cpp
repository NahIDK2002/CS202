#include "date.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    MyDate d1;
    d1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        MyDate d2(-1);
        d2.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        MyDate d3(12,6);
        d3.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        MyDate d4(23,1,2012);
        d4.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    MyDate d5(d1);
    d5.display();
    cout <<"\n";

    return 0;
}