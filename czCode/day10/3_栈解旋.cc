/*************************************************************************
  @FileName:  2_异常处理.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 04 Jun 2019 10:34:33 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
using namespace std;

//1 基本语法
//2 发送异常之后，是跨函数的
//3 接受异常以后 可以不处理  再抛出异常
//4 catch异常的时，按照类型进行catch
//5 异常捕获严格按照类型匹配
//
class Test
{
public:
    Test(int a = 0, int b = 0)
    : _a(a)
    , _b(b)
    {
        cout << "Test()" << endl;
    }
    ~Test()
    {
        cout << "~Test()" << endl;
    }
private:
    int _a;
    int _b;
};

void myDivide() throw (int, char, char *)
{
    Test t1(1, 2), t2(3, 4);
    cout << "myDivide。。。要发生异常" << endl;
    throw 1;
}

//只能列出；来，所列的类型
void myDivide1() throw (int, char, char *)
{
    Test t1(1, 2), t2(3, 4);
    cout << "myDivide。。。要发生异常" << endl;
    throw 1;
}

//不写，可以抛出任何类型
void myDivide2() 
{
    Test t1(1, 2), t2(3, 4);
    cout << "myDivide。。。要发生异常" << endl;
    throw 1;
}

//不抛出异常
void myDivide3() throw ()
{
    Test t1(1, 2), t2(3, 4);
    cout << "myDivide。。。要发生异常" << endl;
    throw 1;
}

