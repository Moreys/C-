#include <iostream>
using std::cout;
using std::endl;

//面向抽象类编程（面向一套预先定义好的接口编程）
//
//借耦合   模块划分
//


class Figure //抽象类
{
public:
    //阅读统一的界面（接口）  让子类使用， 让子类必须去实现   C#接口
    virtual void getArea() = 0; //纯虚函数  

};


class Circle : public Figure
{
public:
    Circle(double a, double b)
    : _a(a)
    , _b(b)
    {
        cout << "Circle()" << endl;
    }
    virtual void getArea()
    {
        cout << "圆的面积为：" <<  3.14 * _a * _a << endl;
        
    }
private:
    double _a;
    double _b;
};


class Tri : public Figure
{
public:
    Tri(double a, double b)
    : _a(a)
    , _b(b)
    {
        cout << "Tri()" << endl;
    }
    virtual void getArea()
    {
        cout << "三角形面积为：" <<  _a * _b /2 << endl;
    }
private:
    double _a;
    double _b;
};
class Square : public Figure
{
public:
    Square(double a, double b)
    : _a(a)
    , _b(b)
    {
        cout << "Squar()" << endl;
    }
    virtual void getArea()
    {
        cout << "矩形的面积：" <<  _a * _b  << endl;
    }
private:
    double _a;
    double _b;
};

void objPlay(Figure * obj)
{
    obj->getArea();
}

int main()
{
    //Figure f1;//抽象类不能实例化
    
    Figure * f1 = NULL; 

    Circle c1(10, 20);
    Tri t1(30, 40);
    Square s1(50, 60);

    objPlay(&c1);
    objPlay(&t1);
    objPlay(&s1);

    return 0;
}
