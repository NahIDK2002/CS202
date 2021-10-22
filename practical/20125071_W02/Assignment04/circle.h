#ifndef CIRCLE_H_
#define CIRCLE_H_

#include <iostream>
#include <math.h>

class Point2D{
    private:
        double x;
        double y;

    public:
        Point2D();
        Point2D(double X, double Y);
        double distanceToOther(Point2D other);
        void display();
};

class Circle{
    private:
        Point2D center;
        double radius;

    public:
        Circle();
        Circle(Point2D c, double r);
        Circle(double r, Point2D c);
        Circle(Point2D c, Point2D pOnLine);        
        Circle(const Circle &other);
        ~Circle();
        void display();
};

#endif