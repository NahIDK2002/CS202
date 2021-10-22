#include "triangle.h"

using namespace std;

Point2D::Point2D(){
    x=0;
    y=0;
}

Point2D::Point2D(double X, double Y){
    this->x = X;
    this->y = Y;
}

double Point2D::distanceToOther(Point2D other){
    return sqrt((other.x-x)*(other.x-x) + (other.y-y)*(other.y-y));
}

void Point2D::display(){
    cout << "(" << x << ", " << y << ")\n";
}

Point2D::~Point2D(){}

bool Triangle::isValid(){
    double da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);
    return (da<db+dc && db<da+dc && dc<da+db);
}

Triangle::Triangle(){
    A = Point2D(0,0);
    B = Point2D(1,0);
    C = Point2D(0,1);
}

Triangle::Triangle(Point2D A, Point2D B, Point2D C){
    this->A = A;
    this->B = B;
    this->C = C;
    if (!isValid()){
        throw "Error! The triangle is not valid!\n";
    }
}

Triangle::Triangle(double xA, double yA, double xB, double yB, double xC, double yC){
    A = Point2D(xA,yA);
    B = Point2D(xB,yB);
    C = Point2D(xC,yC);
    if (!isValid()){
        throw "Error! The triangle is not valid!\n";
    }
}

Triangle::Triangle(Triangle &other){
    A = other.A;
    B = other.B;
    C = other.C;
}

Triangle::Triangle(double da, double db, double dc){
    if (da<db+dc && db<da+dc && dc<da+db){
        B = Point2D(0,0);
        C=Point2D(0,da);

        double p=(da+db+dc)/2.0;
        double s=sqrt(p*(p-da)*(p-db)*(p-dc));
        A = Point2D(abs(db*db-dc*dc-da*da)/(2*da),s*2.0/da);
    }
    else{
        throw "Error! The triangle is not valid!\n";
    }
}

void Triangle::display(){
    cout << "Triangle: A";
    A.display();
    cout << "          B";
    B.display();
    cout << "          C";
    C.display();
}

Triangle::~Triangle(){
    cout << "Delete successfully!\n";
}