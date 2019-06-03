/*************************************************************************
  @FileName:  shared_ptr.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 09:34:04 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Point
{
public:
    Point(int ix, int iy)
        : _ix(ix)
          , _iy(iy)
    {
        cout << "Point()" << endl;

    }
    void print()const
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;

    }

    ~Point()
    {
        cout << "~Point()" << endl;

    }
private:
    int _ix;
    int _iy;

};

unique_ptr<Point> getPoint()
{
    unique_ptr<Point> point (new Point(1, 2));
    return point;
}

int main()
{
#if 1

    Point * pt = new Point(1, 2);
    unique_ptr<Point> ap(pt);
    cout << "ap's set = " << ap.get() << endl;
    cout << "pt = " << pt << endl;

    ap->print();
    (*ap).print();

 //   unique_ptr<Point> ap2(ap);//不能进行复制或者赋值
       // unique_ptr<Point> ap3 = ap;//左值

    //unique_ptr具有移动语义的
    unique_ptr<Point> up = getPoint();//调用移动构造函数
    cout << "........." << endl;
     
#endif

#if 2
    //unique_ptr可以作为容器的元素存在
    vector<unique_ptr<Point>> points;
    points.push_back(unique_ptr<Point>(new Point(3, 4)));
    points.push_back(unique_ptr<Point>(new Point(3, 4)));
    points.push_back(unique_ptr<Point>(new Point(3, 4)));
    points.push_back(unique_ptr<Point>(new Point(3, 4)));
#endif
    std::cout << "Hello world" << std::endl;
    return 0;
}

