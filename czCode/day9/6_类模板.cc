/*************************************************************************
  @FileName:  6_类模板.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 02 Jun 2019 05:26:22 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;


//类模板 , 平时在使用的时候是类的就用class  是函数的就用template
template<class T>
class A
{
public:
    A(T a) : _a(a){}
    
    void printA()
    {
        cout << "a : " << _a << endl;
    }
protected:
    T _a;
};

//从模板类 派生了 普通类
//模板类派生时,需要具体化模板类, C++ 编译器需要知道,父类的数据具体的类型是什么样子的
//需要知道父类所占的内存空间的大小是多少.只有数据固定下来以后才能确定,如何分配内存
class B : public A<int> //在这里需要类型具体化，不然不知道如何分配内存
{
public:
    B(int a = 10, int b = 20) 
    : A<int>(a)
    , _b(b)
    {
        cout << "B()" << endl;
    }
    void printB()
    {
        cout << "a: " << _a << "b: " << _b << endl;
    }
private:
        int _b;
};

//从模板类派生模板类
template<typename T>
class C : public A<T>
{
    C(T c, T a)
    : A<T>(a) //必须使用构造函数  而且构造函数必须是跟随模板类型的
    , _c(c)
    {
        cout << "C()" << endl;
    }
    void printC()
    {
        cout << "c: " << _c <<endl;
    }
protected:
    T _c;

};


void UseA(A <int> & a)
{
    a.printA();
}

int main()
{
    //模板类(本身就是类型化的) =====>具体的类   =====》定义具体的变量
    
    A<int> a1(11), a2(20), a3(30), a4(40); // 模板类是抽象的  ====> 需要进行  类型的具体化

    UseA(a1);
    UseA(a2);
    UseA(a3);
    UseA(a4);

    B b1(1, 2);
    b1.printB();


    std::cout << "Hello world" << std::endl;
    return 0;

}

