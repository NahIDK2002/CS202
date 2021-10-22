#include "lecturer.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    Lecturer l1;
    l1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        Lecturer l2("Nguyen Van  A");
        l2.display();
        cout << "\n";
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        Lecturer l3(24,"Peanut");
        l3.display();
        cout << "\n";
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        Lecturer l4(12,"Red Bean","AA");
        l4.display();
        cout << "\n";
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    try{
        Lecturer l5(10,"Pancake","PhD",3);
        l5.display();
        cout << "\n";
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    return 0;
}