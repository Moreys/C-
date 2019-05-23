#include "circle.h"
using std::cout;
using std::endl;


Circle::Circle() : _r(0)
{
    cout << "Circle()" << endl;
}
Circle::Circle(double r) : _r(r)
{
    cout << "Circle(double r)" << endl;
}

Circle::~Circle()
{
    cout << "~Circle()" << endl;
}

double Circle::getArea()
{
  return _r * _r * PI;
}

double Circle::getPerimeter()
{
    return 2 * _r;
}

void Circle::show()
{
    cout << "R =" << _r << endl;
    cout << "D =" << getPerimeter() << endl;
    cout << "S =" << getArea() <<endl;
}


