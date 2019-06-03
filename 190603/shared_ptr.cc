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

shared_ptr<Point> getPoint()
{
    shared_ptr<Point> point (new Point(1, 2));
    return point;
}

int main()
{
    Point * pt = new Point(1, 2);
    shared_ptr<Point> ap(pt);
    cout << "ap's set = " << ap.get() << endl;
    cout << "pt = " << pt << endl;

    ap->print();
    (*ap).print();

    shared_ptr<Point> ap2(ap);//进行复制或者复制,引用计数的值加1
    {
        shared_ptr<Point> ap3 = ap;//左值
        cout << "ap3's get = " << ap3.get() << endl;
        cout << "ap3's use_count = " << ap3.use_count() << endl;
        cout << "ap2's get = " << ap2.get() << endl;
        cout << "ap2's use_count = " << ap2.use_count() << endl;
    }//当一个共享对象被销毁时， 将引用计数减1,；直到引用计数为0时
     //才真正回收堆空间的数据
     //
     cout << "退出语句块" << endl;
     cout << "ap2's get = " << ap2.get() << endl;
     cout << "ap2's use_count = " << ap2.use_count() << endl;

    //shared_ptr具有移动语义的
    shared_ptr<Point> up = getPoint();//调用移动构造函数
    cout << "........." << endl;
    up = ap;
    cout << "up's get = " << up.get() << endl;
    cout << "up;s use_count = " << up.use_count() << endl;
     
#if 1
    //shared_ptr可以作为容器的元素存在
    vector<shared_ptr<Point>> points;
    points.push_back(shared_ptr<Point>(new Point(3, 4)));
    points.push_back(shared_ptr<Point>(new Point(3, 4)));
    points.push_back(shared_ptr<Point>(new Point(3, 4)));
    points.push_back(shared_ptr<Point>(new Point(3, 4)));

    points.push_back(ap);
    points.push_back(up);
#endif
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

