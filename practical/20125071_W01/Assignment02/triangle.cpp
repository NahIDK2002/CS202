#include "triangle.h"

using namespace std;

void readFile(Triangle &ABC, string file){
    ifstream f;
    f.open(file);
    if (!f.is_open()){
        f.close();
        throw "Error! Can't open file!";
    }

    double xa,ya,xb,yb,xc,yc;
    f >> xa >> ya >> xb >> yb >> xc >> yc;
    ABC = Triangle(xa,ya,xb,yb,xc,yc);

    f.close();
}

Point::Point(){
    x=0; y=0;
}

Point::Point(double x, double y){
    this->x=x;
    this->y=y;
}

void Point::output(double &x, double &y){
    y=this->y;
    x=this->x;
}

void Point::display(){
    cout << "Point: (" << x << ", " << y << "\n";
}

double Point::distanceToOther(Point other){
    return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
}

double Point::distanceToOx(){
    return abs(y);
}

double Point::distanceToOy(){
    return abs(x);
}

bool Triangle::isValid(){
    double da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);

    return (da<db+dc && db<da+dc && dc<da+db);
}

Triangle::Triangle(Point a, Point b, Point c){
    A=a;
    B=b;
    C=c;

    if (!isValid()){
        throw "Error! The triangle is not valid!";
    }
}

Triangle::Triangle(double xa, double ya, double xb, double yb, double xc, double yc){
    A=Point(xa,ya);
    B=Point(xb,yb);
    C=Point(xc,yc);
    
    if (!isValid()){
        throw "Error! The triangle is not valid!";
    }
}

void Triangle::output(Point &a, Point &b, Point &c){
    a=A;
    b=b;
    c=C;
}

void Triangle::display(){
    double x,y;
    A.output(x,y);
    cout << "The triangle: A(" << x << ", " << y << ")\n";

    B.output(x,y);
    cout << "              B(" << x << ", " << y << ")\n";

    C.output(x,y);
    cout << "              C(" << x << ", " << y << ")\n";
}

int Triangle::typeOfTriangle(){
    double da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);

    //Equilateral triangle
    if (da==db && db==dc){
        return 4;       
    }
    else if (da*da==db*db+dc*dc || db*db==da*da+dc*dc || dc*dc==da*da + db*db){
        //Isosceles right triangle
        if (da==db || db==dc || da==dc) return 3;   
        //Right triangle
        else return 2;  
    }
    //Isosceles triangle
    else if (da==db || db==dc || da==dc){
        return 1;
    }
    //scalene triangle
    else return 0;
}

