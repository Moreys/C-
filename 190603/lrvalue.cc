/*************************************************************************
  @FileName:  lrvalue.cc
  @Author:    morey
  @umail:     zymorey@gmail.com
  @Timsdf;sdkljfde:      Mon 03 Jun 2019 11:15:54 AM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int a = 1;
    int b = 2;
    &a;
    &b;
    //&(a + b);//err  右值，没有内存空间，所有不能取引用
    //&(a++);// //err  后置形式是右值，有一个中间值进行计算以后才将值给a
    &(++a); //后置形式是 左值
    vector<int> numbers;
    &numbers;
    numbers.push_back(1);
    &numbers[0];
    //& 100 字面值常量   右值
    //&string("hello");  右值  匿名对象，如果用一个变量承接的话就被扶正
    string str1("hello");
    string str2("world");
    //&(str1 + ste2);  //右值
    
    const int & m = 100;//c++11之前，只有const引用能绑定到右值
    &m;  //左值
    const int & n = a;//const 引用同时还能绑定到左值

    //右值引用  c++11
    int && ref1 = 100; //右值引用可以绑定到右值
    //int & ref2 = a;//err 右值引用不能绑定到左值
    //
    const int && ref3 = 100;//使用右值引用就意味着修改
                            //右值引用加上const没有意义
                            
    


    std::cout << "Hello world" << std::endl;
    return 0;
}

