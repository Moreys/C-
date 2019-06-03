/*************************************************************************
  @FileName:  ./4_两者在一起的调用规则.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 02 Jun 2019 05:08:21 PM CST
 ************************************************************************/
/*
 * 函数模板不允许自动类型转化
 * 普通函数能够进行自动类型转换
 *
 *
 * 1、函数模板可以像普通函数类型一样进行自动转换
 * 2、C++编译器优先考虑的是普通函数
 * 3、如果函数模板能够产生一个更好的匹配,那么选择模板
 * 4、可以通过空模板参数化实参列表的语法限定编译器只通过模板匹配
 *
 * * */
#include <iostream>
using namespace std;

int Max(int a, int b)
{
    cout << "int Max(int a, int b)" << endl;
    return a > b ? a : b;
}

template<typename T>
T Max(T a, T b)
{
    cout << "T Max(T a, T b)" << endl;
    return a > b ? a : b;
}

template<typename  T>
T Max(T a, T b, T c)
{
    cout << "T Max(T a, T b, T c)" << endl;
    return Max(Max(a, b), c);
}
int main()
{
    int a = 10; 
    int b = 20;
    cout << Max(a, b) << endl; //当函数模板和普通函数都符合要求的时候，优先调用普通函数

    cout << Max<>(a, b) << endl; //若显示使用函数模板，则使用<> 类型列表

    cout << Max(3.1, 4.5) << endl; //如果函数模板参数更好的匹配，使用函数模板

    cout << Max(5.0, 6.0, 7.0) << endl;//模板重载

    cout << Max('a', 100) <<endl; //调用普通函数，可以隐式类型转换。
    std::cout << "Hello world" << std::endl;
    return 0;
}

