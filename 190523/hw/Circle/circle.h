#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>

#define PI 3.14
class Circle
{
public:
    Circle();
    Circle(double r);
    ~Circle();

public:
    double getArea();
    double getPerimeter();
    void show();
private:
    int _r;

};

#endif
