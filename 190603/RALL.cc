/*************************************************************************
  @FileName:  ./RALL.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 09:10:44 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

template<typename T>
class RAII
{
public:
    RAII(T * data) : _data(data){}

    T *operator->() //访问里面的元素
    {
        return _data;
    }

    T * operator*() //解引用也是访问里面的元素  直接使用
    {
        return _data;
    }
    T * get()
    {
        return _data;
    }
    void reset(T * data)
    {
        if(_data)
            delete _data;
        _data = data;
    }
    ~RAII()
    {
        if(_data)
            delete [] _data;
        cout << "~RAII()" << endl;
    }
private:
    T * _data;
};

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
int main()
{
    Point * pt = new Point(1, 2);
    pt->print();
    (*pt).print();
    delete pt;
    cout << endl;

    RAII<Point> p(new Point(1, 2));
    p->print();
    (*p)->print();

   // p.reset(new Point(5, 6));

    //p->print(); //释放以后在进行打印好像是脏数据。
    //(*p)->print();

    std::cout << "Hello world" << std::endl;
    return 0;
}

