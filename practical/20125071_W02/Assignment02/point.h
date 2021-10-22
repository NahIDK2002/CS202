#ifndef POINT_H_
#define POINT_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Point2D{
    private:
        double x;
        double y;

    public:
        Point2D();
        Point2D(double x, double y);
        Point2D(Point2D &other);
        Point2D(Point2D &p1, Point2D &p2);
        Point2D(string s);
        ~Point2D();
        void display();
};

#endif