#include <iostream>

using namespace std;

class Test2
{
public:
    Test2()
    {
        _a = 0;
        _b = 0;
        cout << "无参构造函数" << endl;
    }
    Test2(int a)
    {
        _a = a;
        _b = 0;
        cout << "有一个参数的构造函数" << endl;
    }
    Test2(int a, int b)
    {
        _a = a;
        _b = b;
        cout << "有两个参数的构造函数" << endl;
    }

    //赋值构造函数   也叫拷贝构造函数
    Test2(const Test2 & obj)
    {
        cout << "我也是构造函数" << endl;
    }
public:
    void printT()
    {
        cout << "我是普通成员函数" << endl;
    }
private:
    int _a;
    int _b;
};

int main()
{
    //无参构造函数
    Test2 t1;

    //有参构造函数一：括号法
    Test2 t2(1, 2);
    t2.printT();

    //有参构造函数二： = 号法
    Test2 t3 = (1, 2, 3, 4, 5); //  = C++对等号功能进行了增强  自动调用构造函数
    Test2 t4 = 5;

    //有参构造函三： 直接调用构造函数   手动的调用构造函数
    Test2 t5 = Test2(1,2);  // 匿名对象  

    t2 = t5;  //把 t5 copy 给t1  赋值操作
    //对象的初始化和对象的赋值是连个完全不同的概念
    std::cout << "Hello world" << std::endl;
    return 0;
}

