#include "triangle.h"

using namespace std;

int main(){
    Triangle ABC;
    try{
        readFile(ABC,"input.txt");

        //display
        ABC.display();
        cout << "\n\n";

        //type of triangle
        cout << "Type: ";
        switch (ABC.typeOfTriangle())
        {
            case 0:
                cout << "scalene triangle\n\n";
                break;

            case 1:
                cout << "isosceles triangle\n\n";
                break;

            case 2:
                cout << "right triangle\n\n";
                break;

            case 3:
                cout << "isosceles right triangle\n\n";
                break;
            
            default:
                cout << "equilateral triangle\n\n";
                break;
        }

        cout << "Perimeter: " << ABC.perimeter() << "\n\n";
        cout << "Area: " << ABC.area() << "\n\n";

        ABC.centerG().display();
    }
    catch (const char* msg){
        cout << msg;
    }

    return 0;
}