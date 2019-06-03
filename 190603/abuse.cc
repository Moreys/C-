/*************************************************************************
  @FileName:  ./abuse.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 05:22:12 PM CST
 ************************************************************************/
#include <iostream>
#include <memory>

using namespace std;

class Point
: public enable_shared_from_this<Point> //辅助类
{
public:
    Point(int ix, int iy)
    : _ix(ix)
    , _iy(iy)
    {
        cout <<"Pint(int, int)" << endl;
    }
    void print()
    {
        cout << "(" << _ix << "," << _iy << ")" << endl;
    }
   // Point * add(const Point & point)
   shared_ptr<Point> add (const Point & point)
    {
        //在成员函数内部获取本对象的shared_ptr对象。
        _ix += point._ix;
        _iy += point._iy;
    //    return shared_ptr<Point>(this);
        return shared_from_this();
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
private:
     int _ix;
     int _iy;
};


void test0()
{
    Point * pt = new Point(1, 2);
    unique_ptr<Point> up1(pt);
//    unique_ptr<Point> up2(pt);
    up1->print();
 //   up2->print();
}

void test1()
{
    //一个对象交给一个智能指针进行托管的之后,都要用智能指针
    //操作原始的对象
    shared_ptr<Point> sp1(new Point(1, 2));
    shared_ptr<Point> sp2(new Point(2, 4));

    shared_ptr<Point> sp3(sp1->add(*sp2)); //主要是指针都符合：指针指向谁就把谁的值赋给指针。
    sp3->print();
}
void test3()
{
    shared_ptr<Point> sp1(new Point(1, 2));
    shared_ptr<Point> sp2(new Point(3, 4));
    

    sp2.reset(sp1.get()); //不要使用
    //两次构造，三次析构，没有达到想要的效果
    //
        
}
int main()
{
  //  test0();
    //test1();
    test3();
    std::cout << "Hello world" << std::endl;
    return 0;
}

