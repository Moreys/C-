#include <string.h>
#include <iostream>
using namespace std;

//需求 多次申请空间   最后一次释放
class A
{
public:
    A()
    {
        _p = new char[20];
        strcpy(_p, "obja");
        cout << "A()" << endl;
    }
    //如果没有使用虚析构函数，
    //多个子类调用父类的构造函数以后
    //只会调用一次析构函数，释放一次对象
    //使用了虚析构函数以后，则会调用多次
    virtual ~A()
    {
        delete [] _p;
    }
private:
    char * _p;
};
class B : public A
{
public:
    B() : _p(new char[20])
    {
        strcpy(_p, "objb");
        cout << "B()" << endl;
    }
    ~B()
    {
        delete []_p;
        cout << "~B()" << endl;
    }
private:
    char * _p;
};
class C : public B
{
public:
    C() : _p(new char[20])
    {
        strcpy(_p, "objb");
        cout << "C()" << endl;
    }
    ~C()
    {
        delete []_p;
        cout << "~C()" << endl;
    }
private:
    char * _p;
};
//只执行了 父类的析构函数
//想通过父类指针，把 所有的子类对象的析构函数都执行一遍
//向通过父类指针  释放所有的子类资源
void howToDelete(A *base)
{
    delete base;
}
//void howToDelete(B *base)
//{
 //   delete  base;//不会表示为多态
//}
int main()
{
    C *myC = new C;

    delete myC;//直接通过子类对象释放资源  ，不需要写virtual

//:    howToDelete(myC);

    std::cout << "Hello world" << std::endl;
    return 0;
}

