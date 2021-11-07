#ifndef GEOMETRY_H_
#define GEOMETRY_H_

#include <iostream>

using namespace std;

class Geometry{
public:
    virtual void input();
};

class Triangle : public Geometry{
private:
    pair<float,float> A,B,C;

public:
    void input();
};

class Rectangle : public Geometry{
private:
    pair<float,float> topLeft;
    float width,height;

public:
    void input();
};

class Circle : public Geometry{
private:
    pair<float,float> center;
    float radius;

public:
    void input();
};

#endif