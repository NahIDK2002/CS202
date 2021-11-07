#include "geometry.h"

using namespace std;

int main(){
    Geometry *p=0;
    int c;
    cout << "Choice: ";
    cin >> c;
    switch (c)
    {
    case 1:
        p = new Triangle;
        break;

    case 2:
        p = new Rectangle;
        break;

    case 3:
        p = new Circle;
        break;
    
    default:
        break;
    }

    p->input();

    delete p;

    system("pause");

    return 0;
}