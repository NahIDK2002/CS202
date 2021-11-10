#ifndef SHAPE_H_
#define SHAPE_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

#define _USE_MATH_DEFINES

using namespace std;

const int width = 1920;
const int height = 1080;

const string invalidInputMsg="Sorry, your input is invalid.\n";

class Point{
private:
    float x, y;

public:
    Point();
    Point(float X, float Y);
    Point(const Point &other);
    Point(const Point &other, float xt, float yt);
    void input();
    float distanceToOther(const Point &other);
    bool isInside();
};

class Shape{
private:
    virtual bool isValid();
public:
    virtual ~Shape();
    virtual void input();
    virtual string type();
    virtual float area();
};

class Triangle : public Shape{
private:
    Point A,B,C;
    bool isValid();

public:
    void input();
    string type();
    float area();
};

class Rectangle : public Shape{
private:
    Point topLeft;
    float width,height;
    bool isValid();

public:
    void input();
    string type();
    float area();
};

class Circle : public Shape{
private:
    Point center;
    float radius;
    bool isValid();

public:
    void input();
    string type();
    float area();
};

class Screen{
private:
    vector<Shape *> shape;

public:
    ~Screen();
    void input();
    void output();
    float totalArea();
};

#endif