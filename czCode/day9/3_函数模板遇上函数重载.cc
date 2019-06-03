/*************************************************************************
  @FileName:  ./3_函数模板遇上函数重载.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 02 Jun 2019 04:53:04 PM CST
 ************************************************************************/
#include <string.h>
#include <iostream>

using namespace std;

//泛型编程
//template 告诉编译器 我要开始泛型编程了,看到T 不要随便报错
template<typename T>
void myswap(T & a, T & b)
{
    T c = 0;
    c = a;
    a = b;
    b = c;
    cout << "我是模板函数" << endl;
}

void myswap(int & a,char & b)
{
    cout << "a: " << a << "b: " << b  << endl;
    cout << "我是普通函数" << endl;
}

int main()
{
    int a = 10;
    char b = 'a';
    myswap(a, b);
//    myswap(b, a); //err 没有匹配当相应的类型
    myswap(a, a);  // 函数模板的调用(本质：类型参数化 ) ; 将严格的按照类型匹配进行匹配,不会自动进行自动类型转换
    std::cout << "Hello world" << std::endl;
    return 0;
}

