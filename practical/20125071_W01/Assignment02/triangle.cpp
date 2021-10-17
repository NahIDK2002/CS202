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

void Point::init(double x, double y){
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
    A.init(xa,ya);
    B.init(xb,yb);
    C.init(xc,yc);
    
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

bool Triangle::checkHasRightAngle(double a, double b, double c){
    double x=a*a+b*b, y=c*c;
    return fabs(x - y) / max(fabs(x), fabs(y)) <= __DBL_EPSILON__;
}

int Triangle::typeOfTriangle(){
    double da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);

    //Equilateral triangle
    if (da==db && db==dc){
        return 4;       
    }

    int ans=0;
    //if triangle has right angle
    if (checkHasRightAngle(da,db,dc) || checkHasRightAngle(db,da,dc) || checkHasRightAngle(dc,da,db)) ans+=2;
    //if triangle is isosceles
    ans += (da==db || db==dc || da==dc);    
    
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

    Point G;
    G.init((xa+xb+xc)/3,(ya+yb+yc)/3);

    return G;
}