#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

class Point{
    private:
        double x, y;

    public:
        Point();
        Point(double x, double y);
        void output(double &x, double &y);
        void display();
        double distanceToOther(Point other);
        double distanceToOx();
        double distanceToOy();
};

class Triangle{
    private:
        Point A,B,C;
        bool isValid();

    public:
        Triangle();
        Triangle(Point a, Point b, Point c);
        Triangle(double xa, double ya, double xb, double yb, double xc, double yc);
        void output(Point &a, Point &b, Point &c);
        void display();
        int typeOfTriangle();
        double perimeter();
        double area();
        Point centerG();
};

void readFile(Triangle &ABC, string file);

#endif