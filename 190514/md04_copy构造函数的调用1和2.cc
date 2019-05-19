#include <iostream>
using namespace std;
class Test4
{
public:
    Test4()//无参构造函数
    {
        _a = 0;
        _b = 0;
        cout << "我的无参构造函数" << endl;
    }
    Test4(int a)
    {
        _a = a;
        _b = 0;
        cout << "我的一个参数构造函数" << endl;
    }
    Test4(int a, int b) //有参数构造函数
    {
        _a = a;
        _b = b;
        cout << "我是两个参数构造函数" << endl;
    }
    //赋值构造函数  拷贝构造函数
    Test4(const Test4 & obj)
    {
        cout << "我的赋值构造函数" << endl;
        _b = obj._b + 100;
        _a = obj._a + 200;
    }
public:
    void printT()
    {
        cout << "我是普通成员函数" << endl;
        cout << "_a" << _a <<  "_b" << _b << endl; 
    }

private:
    int _a;
    int _b;
};
//1、赋值构造函数 用1个对象去初始化另一个对象
int main1()
{
    Test4 t1(1, 2);
    Test4 t0(1, 2);

    //赋值 =操作  会不会调用构造函数 
    t0 = t1; // 用 t1 给 t0 赋值  到 操作 和初始化是两个不同的概念

    //调用方法一：
    Test4 t2 = t1;  //使用t1 初始化t2 
    t2.printT();

    std::cout << "Hello world" << std::endl;
    return 0;
}

// 第二种调用时机
int main()
{
    Test4 t1(1, 2);
    Test4 t0(1, 2);

    Test4 t2(t1);//t1对象初始化t2
    t2.printT();

}
