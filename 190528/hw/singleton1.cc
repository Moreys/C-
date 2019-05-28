#include <string.h>
#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;

template <typename Type>
class Singleton
{
public:
    template < typename... Args>
    static Type * getInstance(Args... args)
    {
        if(_pInstance)
        {
            _pInstance = new Type(args...);
        }
        return _pInstance;
    }
    static void destroy()
    {
         if(_pInstance)
         {
             delete  _pInstance;
         }
    }
private:
    Singleton(){cout << "Singleton()" << endl;}
    ~Singleton(){cout << "~Singleton()" << endl;}
private:
    static Type * _pInstance;
};

template <typename Type>
Type * Singleton<Type>::_pInstance = nullptr;


class Point
{
public:
    Point(int x, int y)
        : _x(x)
        , _y(y)
    {
        cout << "Point()" << endl;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
    }
    void print()
    {
        cout << "print" << endl;
    }

private:
    int _x;
    int _y;
};


void test()
{

    Point p1(1, 2);
    cout << "1111111" << endl;
    Point * p4 = Singleton<Point>::getInstance(1, 2);
    p4->print();
}

int main()
{
   test();
    return 0;
}

