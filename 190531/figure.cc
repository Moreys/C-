/*************************************************************************
  @FileName:  figure.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 01 Jun 2019 09:14:43 AM CST
 ************************************************************************/
#include <math.h>
#include <iostream>
#include <functional>

using namespace std;

class Figure
{
public:
    typedef function<void()> DisplayCallback;
    typedef function<double()> AreaCallback;

    void setDisplayCallback(DisplayCallback cb)
    {
        _cb = cb;
    }
    void setAreaCallback(AreaCallback cb)
    {
        _cb2 = cb;
    }
    void handeDisplayCallback()
    {
        if(_cb)
        {
            _cb();
        }
    }
    void handeAreaCallback()
    {
        if(_cb2)
        {
            _cb2();
        }
    }
private:
    DisplayCallback _cb; //回调函数
    AreaCallback _cb2;

};

class Rectangle
{
public:
    Rectangle(size_t length, size_t width)
    : _length(length)
    , _width(width)
    {

    }
    void display() const
    {
        cout << "Rectangle";
    }
    double area() const
    {
        return _length * _width;
    }
private:
    size_t _length;
    size_t _width;
};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

