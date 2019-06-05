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


int main1()
{
    try
    {
        throw  'z';
    }
    catch(int e)
    {
        cout << "捕获int类型异常" << endl;
    }
    catch(...)
    {
        cout << "未知 类型异常" << endl;
    }
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

void divide(int x, int y)
{
    if(y == 0)
    {
        throw x;//抛出int类型异常
    }
    cout << "divide结果" << x / y << endl;
}

//异常处理函数 可以处理也可以不处理
void myDivide(int x, int y)
{
    try
    {
        divide(x, y);
    }
    catch(...)
    {
        cout << "我接受了divide的异常" << endl
            << "但是没有处理异常 我向上抛出" << endl;
        throw;
    }
}

int main()
{
    //myDivide(100, 0); //没有处理的话就报错
    //
    try
    {
        myDivide(100, 0);
    }
    catch(int e)
    {
        cout << e << "被零除" << endl;
    }
    catch(...)
    {
        cout << "其他未知类型异常" << endl;
    }
    return 0;
}
