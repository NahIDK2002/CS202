#include "shape.h"

using namespace std;

Point::Point(){
    x=y=0;
}

Point::Point(float X, float Y){
    x = X;
    y = Y;
}

Point::Point(const Point &other){
    x=other.x;
    y=other.y;
}

Point::Point(const Point &other, float xt, float yt){
    x=other.x+xt;
    y=other.y+yt;
}

void Point::input(){
    bool flag=1;
    do{
        cout << "\nPlease input x: ";
        cin >> x;
        cout << "Please input y: ";
        cin >> y;

        flag = isInside();
        if (!flag){
            cout << invalidInputMsg;
        }
    } while(!flag);
}

float Point::distanceToOther(const Point &other){
    return sqrt((x-other.x)*(x-other.x) + (y-other.y)*(y-other.y));
}

bool Point::isInside(){
    return (0<=x && x<=width && 0<=y && y<=height);
}

Shape::~Shape(){}

bool Shape::isValid(){
    return 0;
}

void Shape::input(){}

string Shape::type(){
    return "";
}

float Shape::area(){
    return 0;
}

bool Triangle::isValid(){
    float da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);
    return (A.isInside() && B.isInside() && C.isInside() && (da<db+dc) && (db<da+dc) && (dc<da+db));
}

void Triangle::input(){
    bool flag=1;
    do{
        cout << "Enter point A: ";
        A.input();

        cout << "Enter point B: ";
        B.input();

        cout << "Enter point C: ";
        C.input();

        flag = (width>0 && height>0 && isValid());
        if (!flag){
            cout << invalidInputMsg;
        }
    } while(!flag);
}

string Triangle::type(){
    return "Triangle";
}

float Triangle::area(){
    float da=A.distanceToOther(B), db=B.distanceToOther(C), dc=C.distanceToOther(A);
    float p=(da+db+dc)/2;

    return sqrt(p*(p-da)*(p-db)*(p-dc));
}

bool Rectangle::isValid(){;
    return Point(topLeft,width,height).isInside();
}

void Rectangle::input(){
    bool flag=1;
    do{
        cout << "Enter top-left point: ";
        topLeft.input();

        cout << "Enter width: ";
        cin >> width;

        cout << "Enter height: ";
        cin >> height;

        flag = (width>0 && height>0 && isValid());
        if (!flag){
            cout << invalidInputMsg;
        }
    } while(!flag);
}

string Rectangle::type(){
    return "Rectangle";
}

float Rectangle::area(){
    return width*height;
}

bool Circle::isValid(){
    return (Point(center,radius,radius).isInside() && Point(center,-radius,-radius).isInside());
}

void Circle::input(){
    bool flag=1;
    do{
        cout << "Enter center point: ";
        center.input();

        cout << "Enter radius: ";
        cin >> radius;

        flag = (radius>0 && isValid());
        if (!flag){
            cout << invalidInputMsg;
        }
    } while(!flag);
}

string Circle::type(){
    return "Circle";
}

float Circle::area(){
    return M_PI*radius*radius;
}

Screen::~Screen(){
    int n=shape.size();
    for (int i=0;i<n;++i) delete shape[i];
}

void Screen::input(){
    while (1) {
        Shape *s=0;
        int choice;
        do{
            cout << "Input the shape (1: Triangle, 2: Rectangle, 3: Circle, 0: Stop): ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                s = new Triangle;
                break;
            
            case 2:
                s = new Rectangle;
                break;
            
            case 3:
                s = new Circle;
                break;

            case 0:
                break;
    
            default:
                cout << "Sorry, I don't understand.\n";
                break;
            }
        } while (!s && choice);

        if (!choice) break;
        s->input();
        shape.push_back(s);
    }
    cout << "\n\n";
}

void Screen::output(){
    cout << "You input " << shape.size() << " shape(s): ";
    for (auto s:shape){
        cout << s->type() << " ";
    }
    cout << "\n\n";
}

float Screen::totalArea(){
    float sum=0;
    for (auto s:shape){
        sum+=s->area();
    }

    return sum;
}