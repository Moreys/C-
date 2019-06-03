/*************************************************************************
  @FileName:  ./unordered_set.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 31 May 2019 05:58:03 PM CST
 ************************************************************************/
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;


//在使用STL的时候，其实也就是函数，三要素都不会改变，只是自己一下子
//不能适应而已，模板类也是类的一种，只不过是在编译时没有确定，而且在调用的时候才确定具体的类型
//所有用法都是一样的

void test()
{
    int array[10] = {5, 7, 1, 2, 3, 4, 6, 9, 8, 0};
    
    //用大于号比较， 得到的是一个顺序列（小顶堆）
    //
    //底层实现  堆排序--》二叉堆 ---》 大顶堆  小顶堆
    //定义一个priority_queuel  里面的元素为三种,<三个类型>
    priority_queue<int, vector<int>, std::greater<int>> que;

    for(int idx = 0; idx != 10; ++idx)
    {
        que.push(array[idx]);
        cout << "此时优先级最高的元素是:" << que.top() << endl;
    }
    while(!que.empty())
    {
        cout << que.top() << " ";
        que.pop();
    }
    cout << endl;
}

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

void test2()
{
    priority_queue<Point, vector<Point>,
        PontComparator> que;
    que.push(Point(1, 2));
    que.push(Point(-1, 2));
    que.push(Point(3, 2));
    que.push(Point(4, 2));
    que.push(Point(6, 2));
    que.push(Point(9, 2));

    while(!que.empty())
    {
        cout << que.top() << " " ;
        que.pop();
    }        
    cout << endl;
}
int main()
{
//    test();
    test2();
    std::cout << "Hello world" << std::endl;
    return 0;
}

