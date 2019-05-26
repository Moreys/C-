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
    double getR()
    {
        return _r;
    }
    void setR(double r)
    {
        _r = r;
    }

    int _r;

};

class Cylinder : public Circle
{

public:
    Cylinder(double r, double h);

public :
    double getVolume();
    void showVolume();

private:
    double _h;
    
};

#endif
