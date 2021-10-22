#include "circle.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    Circle c1;
    c1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    try{
        Circle c2(Point2D(0,1),2);
        c2.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "3rd constructor:\n";
    try{
        Circle c3(Point2D(5,3),4.2);
        c3.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        Circle c4(Point2D(4,6),Point2D(1,2));
        c4.display();
    }
    catch(const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    Circle c5(c1);
    c5.display();
    cout << "\n";

    return 0;
}