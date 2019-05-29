#include <cmath>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
using std::set;
using std::string;

template <typename Container>
void display(const Container & c)
{
    for(auto & elem : c)
    {
        cout << elem << " ";
    }
    cout << endl;
}

void testSet()
{
    //set默认情况下按照升序进行排列
    //set中不能存放关键字相同的元素
    set<int> numbers{1, 1, 5, 6, 3, 6, 8, 9, 2, 4};
    display(numbers);

    //不支持下标访问
    //numbers[1]; //err 使用双向迭代器进行访问
    for(auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    //插入元素
    //std::pair<set<int>::iterator, bool> ret = numbers.insert(1);
    auto ret = numbers.insert(7);
    if(ret.second)
    {
        cout << "添加元素成功" << endl;
        cout << *ret.first << endl;
    }
    else
    {
        cout << "插入失败" << endl;
        cout << *ret.first << endl;
    }
    display(numbers);

    //set底层实现是红黑树，  近似平衡二叉树   访问某一个节点的时间复杂度为O(logN)
    //特点：
    //1、节点不是红色就是黑色
    //2、根节点是黑色的
    //3、所有叶子节点都是黑色的
    //4、不能有两个连续的红色节点
    //5、从根节点到任意一个叶子节点的路径上的黑色节点的个数相同
    //*it = 10 err 不能修改已经添加到其中的元素，是只读的
    //
    //
    //
    //如果判断元素中是否包含某个值  使用count
    size_t count = numbers.count(7);  //O(logN)
    cout << "cout = " << count << endl;
    
    //如果要查找元素并访问，可以使用find
    auto it2 = numbers.find(1);
    if(it2 != numbers.end())
    {
        cout << "*it2 = " << *it2 << endl;
    }
    else
    {
        cout << "没有找到相关的元素" << endl;
    }
    

}


class Point
{
public:
    Point(int x = 0, int y = 0)
    : _x(x)
    , _y(y)
    {
    }
    float getDistance() const
    {
        return sqrt(_x * _x + _y * _y);
    }
    friend std::ostream & operator <<(std::ostream & os, const Point & rhs);
private:
    int _x;
    int _y;
};

std::ostream & operator <<(std::ostream & os, const Point & rhs)
{
    os << "(" << rhs._x
    << "," << rhs._y
    << ")";
    return  os;
}

struct PointComparator
{
    bool operator()(const Point & lhs, const Point & rhs)
    {
        return lhs.getDistance() > rhs.getDistance();
    }
};

void testSet1()
{
    //对于自定义类型，如果要放到关联容器里面，要指定排序方式
    set<Point, PointComparator> numbers
    {
        Point(1, 2),
        Point(3, 4),
        Point(5, 6),
        Point(1, 2),
        Point(7, 8),
        Point(9, 0)
    };
    display(numbers);
    
}

int main()
{
   // testSet();
    testSet1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

