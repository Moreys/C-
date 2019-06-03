/*************************************************************************
  @FileName:  ./weak_ptr.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 10:09:02 PM CST
 ************************************************************************/
#include <iostream>
#include <memory>
#include <vector>
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

void test0()
{
    weak_ptr<Point> wp;
    {
        shared_ptr<Point> sp(new Point(1, 2));
        wp = sp; //不会导致引用计数加1
        cout << "wp's use_count = " << wp.use_count() << endl;
        cout << "sp's use_count = " << sp.use_count() << endl;
        //weak_ptr 其所托管的对象是否还存活
        cout << "wp's expired = " << wp.expired() << endl; //没有到期；

        shared_ptr<Point> sp2 = wp.lock(); //对weak_ptr进行提升
        if(sp2)
        {
            cout << "wp提升成功" << endl;
            sp2->print();
        }
        else
        {
            cout << "wp提升失败" << endl;
        }
    }

    cout << endl << "退出语句块:" << endl;
    cout << "wp's expired = " << wp.expired() << endl; //此时对象呗销毁

    //weak_ptr 内部没有提供访问资源的方法，必须要提升成shared_ptr才能进行访问
    shared_ptr<Point> sp2 = wp.lock();//对weak_ptr进行提升
    if(sp2)
    {
        cout << "wp提升成功" << endl;
        sp2->print();
     }
    else
    {
        cout << "wp提升失败" << endl;
     }
    cout << ">> sp3: " << endl;
    shared_ptr<Point> sp3;
    sp3->print();
}

int main()
{
    test0();
    std::cout << "Hello world" << std::endl;
    return 0;
}

