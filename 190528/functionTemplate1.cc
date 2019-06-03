#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

//template <class T>
template <typename T>//模板形参列表
T add(T x, T y);//模板的函数参数类型

//函数模板与函数模板之间也可以进行重载
template <typename T>
T add(T x, T y, T z)
{
    return x + y + z;
}

//实例化
//函数模板----》模板函数
// 模板参数推导
//
// 模板====》代码生成器
//
// 函数模板与普通函数之间是可以重载的
// 而普通函数的执行要优先于函数模板

#if 0
//在编译期间有函数模板进行参数推导实例化的一个模板函数
int add(int x, int y)
{
    cout << "int add(int x, int y)" << endl;
    return x + y;
}
#endif

//当模板形参列表有多个参数时，还可以对某一个参数设置一个特殊的类型
//模板偏特化 --->目前阶段不需要理解太深j
//模板特化
//  特化版本不唯一
//
//

template<>
const char * add<const char*>(const char *p1, const char * p2)
{
    char * ptem = new char[strlen(p1) + strlen(p2) + 1]();
   strcpy(ptem, p1);
   strcpy(ptem, p2);
   return  ptem;
}

int main()
{
    int x1 = 3, x2 = 4, x9 = 5;
    double x3 = 1.11, x4 = 2.22;
    char x5 = 'a', x6 = 1;
    long x7 = 100, x8 = 101;
    const char * str1 = "hello";
    const char * str2 = "world";
    cout << "add(x1, x2) = " << add(x1, x2) << endl; //隐式实例化
    cout << "add(x3, x4) = " << add<double>(x3, x4) << endl;//显示实例化
    cout << "add(x5, x6) = " << add(x5, x6) << endl;
    cout << "add(x7, x8) = " << add(x7, x8) << endl;
    cout << "add(x1, x2, x3) = " << add(x2, x2, x9) << endl;
    cout << "add(str1, str2) = " << add(str1, str2) << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

template <typename T>
T add(T x, T y)
{
    cout << "T add(T, T)" << endl;
    return x + y;
}

