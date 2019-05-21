#include "Line.h"

#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Line line(1, 2, 3, 4);
    line.printLine();
    //Line::Point pt1(11, 12);//err不能这样使用
    //pt1.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

