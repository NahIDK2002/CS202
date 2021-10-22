#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include <iostream>
#include <math.h>

using namespace std;

class Point2D{
    private:
        double x;
        double y;

    public:
        Point2D();
        Point2D(double x, double y);
        double distanceToOther(Point2D other);
        ~Point2D();
        void display();
};

class Triangle{
    private:
        Point2D A,B,C;
        bool isValid();

    public:
        Triangle();
        Triangle(Point2D A, Point2D B, Point2D C);
        Triangle(double xA, double yA, double xB, double yB, double xC, double yC);
        Triangle(Triangle &other);
        Triangle(double da, double db, double dc);
        ~Triangle();
        void display();
};

#endif