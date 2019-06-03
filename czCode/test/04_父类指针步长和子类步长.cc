#include <iostream>

using namespace std;

//多态成立的三个条件
//1、要有继承
//2、虚函数重写
//3、父类指针指向子类对象
//
//多态是用父类指针指向子类对象  和父类步长++  是两个不同的概念。
class Parent
{
public:
    Parent(int a = 0)
        : _a(a)
    {
        cout << "Parent()" << endl;
    }
    virtual void print() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是爹" << endl;
    }
    
private:

    int _a;
};

class Child : public Parent
{
public:
    /*
    Child(int a = 0, int b = 0)
        : Parent(a)   //父类显示定义了构造函数，子类必须显示初始化
        , _b(b)
    {
        cout << "Child()" << endl;
    }
    */
    Child(int b = 0)
         : Parent(0)
    {

    }
    virtual void print() //1、动手脚    写了virtua关键字会进行特殊处理  生成虚表
    {
        cout << "我是child" << endl;
    }
    
private:
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

    
    Parent *pP = NULL;
    Child *pC = NULL;
    Child array[] = {Child(1), Child(2), Child(3)};
    pP = array;
    pC = array;

    pP->print();
    pC->print(); //多态发生
    //指针也一种数据类型，C++类对象的指针p++ / p-- 是一样的；
    //指针运算是按照指针所指的类进行的
    //结论：父类p++与子类p++步长不一样，不要混搭，不要用父类指针++方式操作数组

    pP++;
    pC++;
    pP->print();
    pC->print(); //多态发生

    

    pP++;
    pC++;
    pP->print();
    pC->print(); //多态发生

    std::cout << "Hello world" << std::endl;
    return 0;
}

