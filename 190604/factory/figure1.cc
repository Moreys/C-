/*************************************************************************
  @FileName:  figure.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 04 Jun 2019 02:31:08 PM CST
 ************************************************************************/
                                                                         
#include <math.h>
#include <iostream>
#include <memory>
using namespace std;
//面向对象设计原则
//开闭原则：对修改关闭，对扩展开放

class Figure
{
public:
    virtual void display() const = 0;
    virtual double area() const = 0;
    virtual ~Figure(){}
};

class Rectangle : public Figure
{
public:
    Rectangle(size_t length, size_t width)
    : _length(length)
    , _width(width)
    {

    }
    void display()const 
    {
        cout << "rictanle";
    }
    double area() const
    {
        return _length * _width;
    }
    ~Rectangle(){cout << "~Rectangle()" << endl;}

private:
    size_t _length;
    size_t _width;
};

class Circle : public Figure
{
public:
    Circle(double radius) : _radius(radius)
    {

    }
    void display() const 
    {
        cout << "circle" ;
    }
    double area() const 
    {
        return 3.14 * _radius * _radius;
    }
    ~Circle()
    {
        cout << "~Circle()" << endl;
    }
private:
    double _radius;
};

class Triangle : public Figure
{
public:
    Triangle(size_t a, size_t b, size_t c)
    : _a(a)
    , _b(b)
    , _c(c)
    {}
    void display() const
    {
        cout << "Triangle" ;
    }
    double area() const
    {
        size_t p = (_a + _b + _c) / 2;
        return sqrt(p * (p - _a) * (p - _b) * (p - _c));
    }
    ~Triangle()
    {
        cout << "~Triangle()" << endl;
    }
private:
    size_t _a;
    size_t _b;
    size_t _c;
};

void display(Figure * fig)
{
    fig->display();
    cout << " 's area is '" << fig->area() << endl;
}

//静态工厂方法
//
//工厂模式
//  一个工厂对应于一种产品
//  适用场景
//      针对于复杂对象
//      创建大量类似对象
//
//
//简单对象不需要采用工厂模式
//
//抽象工厂 是对工厂模式的扩展
//1个工厂对应于多种产品
//
//
class Factory
{
public:
    virtual Figure * create() = 0;
    virtual ~Factory(){}
};

class RectangleFactory : public Factory
{
public:
    Figure * create() 
    {
        return new Rectangle(3, 4);
    }
};
class TriangleFactor : public Factory
{
public:
    Figure * create() 
    {
        return new Triangle(3, 4, 5);
    }
};

class CircleFactor : public Factory
{
public:
    Figure * create() 
    {
        return new Circle(10);
    }
};


int main()
{
    unique_ptr<Factory> rectangleFactory(new RectangleFactory());
    unique_ptr<Figure> rectangle(rectangleFactory->create());

    unique_ptr<Factory> tariangleFactory(new TriangleFactor());
    unique_ptr<Figure> tariangle(tariangleFactory->create());

    unique_ptr<Factory> circleFactor(new CircleFactor());
    unique_ptr<Figure> circle(circleFactor->create());
    display(rectangle.get());
    display(tariangle.get());
    display(circle.get());
    std::cout << "Hello world" << std::endl;
    return 0;
}

