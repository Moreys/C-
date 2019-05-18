#include <iostream>
using namespace std;
int getAA1()
{
    int a;
    a = 10;
    return a;
}
//返回a的本身，返回a的一个副本 10
int & getAA2()
{
    int a;//如果返回栈上的 引用，有可能会有问题
    a = 10;
    return a;
}
int * getAA3()
{
    int a;
    a = 10;
    return  &a;
}
int main()
{
    int a1 = 0;
    int a2 = 0;
    a2 = getAA2();//10;
    int &a3 = getAA2();//若返回栈变量 不能成为其它引用的初始值
    cout << "a1:" << a1 << endl;
    cout << "a2:" << a2 << endl;
    cout << "a3:" << a3 << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

