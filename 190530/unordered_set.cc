/*************************************************************************
  @FileName:  ./unordered_set.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 31 May 2019 05:58:03 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

class Point
{
public:
    Point(int ix = 0, int iy = 0)
    : _ix(ix)
    , _iy(iy)
    {
        cout << "Poin(int, int)" << endl;
    }
    float getDistance() const
    {
        return sqrt(_ix * _ix + _iy * _iy);
    }

    int getX()const {return _ix;}
    int getY()const {return _iy; }

    friend std::ostream & operator<<(std::ostream &os, const Point & rhs);
private:
    int _ix;
    int _iy;
};

std::ostream & operator<<(std::ostream &os, const Point & rhs)
{
    os <<"(" << rhs._ix
        << "," << rhs._iy
        << ")";
    return os;
}

//自定义类型必须重定义排序方式
struct PontComparator
{
    bool operator()(const Point & lhs, const Point & rhs)
    {
        return lhs.getDistance() > rhs.getDistance();
    }
};


//自己在namespace std 中重新定义排序的方式
namespace  std
{
template<>
struct hash<Point>
{
    size_t operator()(const Point & rhs)const
    {
        return ((rhs.getX() * rhs.getX()) >> 1) ^
            (rhs.getY() * rhs.getY() >> 1);
    }
};

}//end of namespace std

//在定义hash排序的类
struct PointHasher
{
    size_t operator()(const Point & rhs)const
    {
        return ((rhs.getX() * rhs.getX()) >> 1) ^
            (rhs.getY() * rhs.getY() >> 1);
    }
};

struct PointEqual
{
    bool operator()(const Point & lhs, const Point & rhs) const
    {
        return (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY());
    }
};

void test0()
{

    //个人总结：
    //1、不管存放的是什么类型，后面插入和取出进行承接的都必须和定义的类型一致才能进行操作
    //2、而且左值类型必须和右值类型一致才能进行相应的操作
    //
    unordered_set<Point, PointHasher,PointEqual> points
    {
        Point(1, 2),
        Point(1, 2),
        Point(3, 2),
        Point(4, 2),
        Point(5, 2),
        Point(-1, 2),
        Point(7, 2),
    };

    auto it = points.begin();
    for(; it != points.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //添加元素   时间复杂度为O(1)
    auto ret =  points.insert(Point(-1, 4));
    if(ret.second)
    {
        cout << "添加成功" << endl;
        cout << *ret.first << endl;
    }
    else
    {
        cout << "添加失败" << endl;
        cout << *ret.first << endl;
    }
}

int main()
{
    test0();
    std::cout << "Hello world" << std::endl;
    return 0;
}

