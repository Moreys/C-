/*************************************************************************
  @FileName:  01_函数模板基本语法.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 02 Jun 2019 04:34:27 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

void  myswap1(int & a, int & b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}
template<typename T>
void myswap2(T & a, T & b)
{
    T c = 0;
    c = a;
    a = b;
    b = c;
}

//调用方式有两种，
//显示调用
//隐式调用
//
int main()
{
    int a = 10;
    int b = 20;
    cout << a << b << endl;
    myswap2(a, b);
    cout << a << b << endl;

    char c = 'a';
    char d = 'b';
    cout << c << d << endl;
    myswap2(c, d);
    cout << c << d << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

