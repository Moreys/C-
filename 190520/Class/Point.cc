#include <math.h>

#include <iostream>

using std::cout;
using std::endl;

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
    //友元之 普通函数  全局函数  自由函数
    friend double distance(const Point & lhs, const Point &rhs);
private:
    int _ix;
    int _iy;
};
double distance(const Point & lhs, const Point & rhs)
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
    cout << distance(pt, pt2) << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

