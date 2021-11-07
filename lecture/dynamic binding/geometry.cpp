#include "geometry.h"

using namespace std;

void Geometry::input(){
    cout << "Sorry, you didn't choose anything!";
}

void Triangle::input(){
    cout << "Enter A:";
    cin >> A.first >> A.second;
    cout << "Enter B:";
    cin >> B.first >> B.second;
    cout << "Enter C:";
    cin >> C.first >> C.second;
}

void Rectangle::input(){
    cout << "Enter top left:";
    cin >> topLeft.first >> topLeft.second;
    cout << "Enter width:";
    cin >> width;
    cout << "Enter height:";
    cin >> height;
}

void Circle::input(){
    cout << "Enter center:";
    cin >> center.first >> center.second;
    cout << "Enter radius:";
    cin >> radius;
}