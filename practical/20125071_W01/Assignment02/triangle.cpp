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
    cout << "Point: (" << x << ", " << y << ")\n";
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

Triangle::Triangle(){}

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

    int ans=0;
    ans += (da*da==db*db+dc*dc || db*db==da*da+dc*dc || dc*dc==da*da + db*db)*2;    //if triangle has right angle
    ans += (da==db || db==dc || da==dc);    //if triangle is isosceles
    
    return ans;
}

double Triangle::perimeter(){
    return A.distanceToOther(B)+B.distanceToOther(C)+C.distanceToOther(A);
}

double Triangle::area(){
    double p=perimeter()/2;

    return sqrt(p*(p-A.distanceToOther(B))*(p-B.distanceToOther(C))*(p-C.distanceToOther(A)));
}

Point Triangle::centerG(){
    double xa,ya;
    A.output(xa,ya);

    double xb,yb;
    B.output(xb,yb);

    double xc,yc;
    C.output(xc,yc);

    return Point((xa+xb+xc)/3,(ya+yb+yc)/3);
}