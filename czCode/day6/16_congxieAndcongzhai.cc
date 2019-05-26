#include <iostream>

using namespace std;

//重写  重载   重定义
//重写发送在两个类之间
//重载必须在一个类内
//
//
//重写分为两类
//1 虚函数重写   将发送多态
//2 非虚函数重写 （重写定义）
//
class Parent
{
    //这三个函数都是重载关系
public:
    void adc()
    {
        cout << "abd()" << endl;
    }
    virtual void func()
    {
        cout << "func() do...." << endl;
    }
    virtual void func(int i)
    {
        cout << "func()do=" << i << endl;
    }
    virtual void func(int i, int y)
    {
        cout << "func()do= " << i << " " << y << endl;
    }

    virtual void func(int i, int y,int n)
    {
        cout << "func()do= " 
            << i  << " " << y
            << " " << n << endl;
    }
    virtual void func(int i, int y, int n, int m)
    {
        cout << "func() do=" 
            << i << " " << y 
            << " " << n   
            << " " << m << endl;
    }
};

class Child : public Parent
{
public:
    void adb()
    {
        cout << "child adb" << endl;
    }
    virtual void func(int i, int y)
    {
        cout << "func(int i, int j) do=" << i << " " << y << endl;
    }
    virtual void func(int i, int y,int n)
    {
        cout << "func(int i, int y, int n)do= " 
            << i  << " " << y
            << " " << n << endl;
    }
};
//重载   重写   和  重定义
int main()
{
    Child c1;
    //c1.func();
    //子类无法重载父类的函数，父类同名函数将被名称覆盖
    c1.Parent::func();


    //1 C++编译器看到func名字，因为子类func名字已经存在了（名称覆盖）
    //  所有C++编译器不会去找父类的4个参数的func函数
    //2、C++编译器只会在子类中，查找func函数，找到两个func
    //  一个是两个参数，一个是三个参数的
    //3、C++编译器开始报错  没有重载函数接受4个参数
    //4、若想调用父类的func，只能加上父类的域名 这样才能正常使用
    //c1.func(1, 2, 3, 4); //err 说子类没有找相关重载的
    c1.Parent::func(1, 2, 3, 4); //err 说子类没有找相关重载的
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

