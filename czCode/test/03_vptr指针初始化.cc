#include <iostream>

using namespace std;

//多态成立的三个条件
//1、要有继承
//2、虚函数重写
//3、父类指针指向子类对象
//
class Parent
{
public:
    Parent(int a = 0)
        : _a(a)
    {
        cout << "Parent()" << endl;
        print(); //构造函数种调用虚函数能发送多态吗？
        //不能 虚函数调用不会被传递到派生类中。派生类表现出来的是本身的属性
        //静态联编和动态联编的问题
        //构造函数在编译的时候就已经确定了
        //而虚函数 则是在运行的时候通过对象的调用才确定。
    }
    virtual void print() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是爹" << endl;
    }
    virtual void print1() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是爹" << endl;
    }
    
private:

    int _a;
};

class Child : public Parent
{
public:
    Child(int a = 0, int b = 0)
        : Parent(a)   //父类显示定义了构造函数，子类必须显示初始化
        , _b(b)
    {
        cout << "Child()" << endl;
        print();
    }
    virtual void print() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是child" << endl;
    }
    virtual void print1() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是child" << endl;
    }
    
private:
    int _b;
};

//搭建舞台，同一个函数，传递参数对象不一样实现不一样的效果
void HowToPlay(Parent *base)
{
    base->print(); //有多态  2、动手脚
    //效果  传来子类对象的时候执行子类的print函数
    //      传来父类对象的时候执行父类的print函数
    //
    //      C++编译器根本不需要区别是子类对象还是父类对象
    //      父类对象和子类对象分别有vptr指针   指向各自的虚函数表   函数表放的是函数入口地址
    //      迟绑定 ：运行时的时候，C++ 编译器才去判断
//
}

int main()
{
    Child c1;
    HowToPlay(&c1); //没有效果

    std::cout << "Hello world" << std::endl;
    return 0;
}

