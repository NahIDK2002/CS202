#include "triangle.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    Triangle tri1;
    tri1.display();
    cout << "\n";
    
    cout << "2nd constructor:\n";
    try{
        Point2D A(0,0), B(3,0), C(0,4);
        Triangle tri2(A,B,C);
        tri2.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        Triangle tri3(0, 0, 8, 4, 1, 9);
        tri3.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    Triangle tri4(tri1);
    tri4.display();
    cout << "\n";

    cout << "5th constructor:\n";
    try{
        Triangle tri5(3,4,5);
        tri5.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    return 0;
}