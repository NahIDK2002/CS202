#include "circle.h"

using namespace std;

Point2D::Point2D(){
    x=0;
    y=0;
}

Point2D::Point2D(double X, double Y){
    x=X;
    y=Y;
}

double Point2D::distanceToOther(Point2D other){
    return sqrt((other.x-x)*(other.x-x)+(other.y-y)*(other.y-y));
}

void Point2D::display(){
    cout << "(" << x << ", " << y << ")\n";
}

Circle::Circle(){
    center=Point2D(0,0);
    radius = 1;
}

Circle::Circle(Point2D c, double r){
    if (r<=0){
        throw "Error! The radius must be a positive real number!\n";
    }
    center = c;
    radius = r;
}

Circle::Circle(Point2D c, Point2D pOnLine){
    center = c;
    radius = c.distanceToOther(pOnLine);
}

Circle::Circle(const Circle &other){
    center=other.center;
    radius=other.radius;
}

Circle::Circle(double r, Point2D c){
    if (r<=0){
        throw "Error! The radius must be a positive real number!\n";
    }
    center = c;
    radius = r;
}

Circle::~Circle(){
    cout << "Delete successfully!\n";
}

void Circle::display(){
    cout << "Circle: center O";
    center.display();
    cout << "        radius r = " << radius << "\n";
}