/*************************************************************************
  @FileName: bind.cc
  @Author:   morey
  @Email:    zymorey@gmail.com
  @Time:   Thu 30 May 2019 06:03:06 PM CST
 ************************************************************************/
#include <iostream>
#include <functional>
using namespace std;

void display()
{
    cout << "display()" << endl;
}
    void (*f)() = display; //定义万能函数，并将display赋值给万能函数
    typedef  void (*Function)();//定义一个函数指针
    
    int test0()
    {
        f(); //直接使用晚上
        Function f1 = display; //f1 指向display函数
        f1();
        return 0;
    }

void add(int x, int y)
{
    cout << "x + y = " << x + y << endl;
}
struct Example
{
    void add(int x, int y)
    {
        cout << "Example::add()" << endl;
        cout << "x + y = " << x + y << endl;
    }
    int _x = 10;
};
void test1()
{
    auto f = display;
    f();
    auto f1 = bind(&add, 1, 2);//可以绑定普通函数
    f1();
    Example example;

    //对于成员函数，绑定时必须要加上取地址符号
    //对于this指针而已，可以传递地址，也可以传递对象
    
    auto f2 = bind(&Example::add, &example, 1, 2);
    f2();

    //占位符
    using namespace std::placeholders;
    auto f4 = bind(&Example::add, &example, _1, _2);
    f4(11, 12);

    auto f5 = bind(&Example::_x, &example);
    cout << f5() << endl;

}
void print(int x1, int x2, int & x3, int x4)
{
    cout << "(" << x1
    << "," << x2
    << "," << x3
    << "," << x4
    << ")" << endl;
}
void test2()
{
    using namespace std::placeholders;
    int a = 100;
    //占位符 本身所占的位置是形参的位置
    //占位符本身的数字代表的是实参的位置
    auto f = bind(print, _1, _2, ref(a), a);
    a = 101;
    f(11, 22, 1111, 2222, 3333);
}
void test3()
{
    using namespace std::placeholders;
    int a = 100;

    //std::function称为函数的容器，只能保存一个函数
    function<void(int, int)> f = bind(print, _1, 100, ref(a), a);
    f(11, 12);

    function<void()> f2 = display;
    f2();

    f2 = bind(&Example::add, Example(), 1, 2);
    f2();

}
int main()
{
    cout << "test0" << endl;
    test0();
    cout << "test1" << endl;
    test1();
    cout << "test2" << endl;
    test2();
    cout << "test3:" << endl;
    test3();
    std::cout << "Hello world" << std::endl;
    return 0;
}

