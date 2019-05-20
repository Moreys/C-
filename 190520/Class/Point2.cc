#include <math.h>

#include <iostream>

using std::cout;
using std::endl;

class Point;//类的向前声明

class Line
{
public:
    double distance(const Point & lhs, const Point & rhs);
};
class Point
{
public:
    Point(int ix = 0, int iy = 0) : _ix(ix), _iy(iy)
    {
        cout << "Point(int, int)" << endl;
    }
    void print()const
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
    //友元之成员函数  另一个类中的声明
    //知识对Line类汇总的distance函数是友元
    friend double Line::distance(const Point & lhs, const Point &rhs);
private:
    int _ix;
    int _iy;
};
//第一种写法  在另一个类中进行定义
//返回一个匿名对象
double Line::distance(const Point & lhs, const Point & rhs)
{
    return sqrt((lhs._ix - rhs._ix) * (lhs._ix - rhs._ix) +
                (lhs._iy - rhs._iy) * (lhs._iy - rhs._iy));
}
int main()
{
    Point pt(1, 2);
    pt.print();
    cout << "----->";
    Point pt2(11, 12);
    pt2.print();
    cout << Line().distance(pt, pt2) << endl;//临时对象 匿名对象 
    //如果用一个类型去承接则变为有名对象
    return 0;
}

