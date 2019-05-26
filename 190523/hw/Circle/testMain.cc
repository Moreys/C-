#include "circle.h"
#include <iostream>

int main()
{
    Cylinder c1(10, 10);
    c1.getArea();
    c1.getPerimeter();
    c1.show();
    c1.getVolume();
    c1.showVolume();
    std::cout << "Hello world" << std::endl;
    return 0;
}

