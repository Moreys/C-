#include <iostream>

using namespace std;

// 1 第一点
//      单独定义的引用时，必须初始化，说明跟常量很像
int main1001()
{
    const int c1 = 10;
    int a = 10;
    int &b = a; //b很像一个常量
    cout << "&a:" << &a << endl;
    cout << "&b:" << &b << endl;// a 和 b 就是同一块内存空间的门牌号
    std::cout << "Hello world" << std::endl;
    return 0;
}

// 2. 普通引用有自己的空间吗   有
struct Teacher
{
    char name[64];
    int age;
    int &a;
    int &b;
};

//3 引用的本质
void modifyA(int &a1)
{
    a1 = 1000;
}
void modifyA2(int * const a1)
{
    *a1 = 2000;//实参的地址 去间接的修改实参的值

}

int main()
{
    int a = 10;
    modifyA(a);
    cout << "a:" << a << endl;

    a = 10;

    modifyA2(&a);//如果是指针需要我们程序员手工的取实参的市值
    cout << "a:" << a << endl;
    cout << "sizeof(Teacher):" << sizeof(Teacher) << endl;
}
