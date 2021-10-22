#include "student.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    Student s1;
    s1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        Student s2("Nguyen Van A");
        s2.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        Student s3(123456, "Le Thi B");
        s3.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        Student s4(654321, "Tran Van C", "123 Nguyen Van Cu");
        s4.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    try{
        Student s5(234567, "Pham Thi D", "321 Nguyen Van Cu", 5.3);
        s5.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    return 0;
}