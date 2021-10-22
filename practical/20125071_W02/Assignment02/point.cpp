#include "point.h"

using namespace std;

Point2D::Point2D(){
    x=0;
    y=0;
}

Point2D::Point2D(double x, double y){
    this->x=x;
    this->y=y;
}
Point2D::Point2D(Point2D &other){
    x=other.x;
    y=other.y;
}

Point2D::Point2D(Point2D &p1, Point2D &p2){
    x=(p1.x+p2.x)/2.0;
    y=(p1.y+p2.y)/2.0;
}

Point2D::Point2D(string s){
    int pos = s.find(',');
    if (pos>=s.length() || pos==s.length()-1) throw "Sorry! I don't understand.";
    x=stod(s.substr(0,pos));
    y=stod(s.substr(pos+1,s.size()-pos));
}

void Point2D::display(){
    cout << "Point2D: " << x << ", " << y << "\n";
}

Point2D::~Point2D(){
    cerr << "Delete successfully!\n";
}