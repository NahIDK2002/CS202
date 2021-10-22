#include "colorPixel.h"

using namespace std;

int main(){
    cout << "1st constructor:\n";
    ColorPixel p1;
    p1.display();
    cout << "\n";

    cout << "2nd constructor:\n";
    ColorPixel p2(12,34,123);
    p2.display();
    cout << "\n";

    cout << "3rd constructor:\n";
    ColorPixel p3(0x0cFF80);
    p3.display();
    cout << "\n";

    cout << "4th constructor:\n";
    try{
        ColorPixel p4("blue");
        p4.display();
    }
    catch (const char *msg){
        cout << msg << "\n";
    }
    cout << "\n";

    cout << "5th constructor:\n";
    ColorPixel p5(p2);
    p5.display();

    return 0;
}