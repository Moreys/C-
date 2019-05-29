#include <iostream>
#include <vector>
using std::endl;
using std::cout;
using std::vector;

class Point
{
public:
    Point(int x = 0, int y = 0)
    : _x(x)
    , _y(y)
    {
        cout << "Point(int x, int y)" << endl;
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

template<typename Container>
void display(const Container & c)
{
    for(auto & elem : c)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    vector<Point> points(10,Point(1, 2));  //里面存储十个Point:
    display(points);
    std::cout << "Hello world" << std::endl;
    return 0;
}

