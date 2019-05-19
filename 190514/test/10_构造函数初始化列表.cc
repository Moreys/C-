#include <iostream>
using namespace std;
class A
{
public:
    A(int a)
    {
        _a = a;
        cout << "构造函数" << "a" << _a << endl;
    }
    ~A()
    {
        cout << "析构函数" << "a" << _a << endl;
    }
private:
    int _a;
};

//1、构造函数的初始化列表   解决：在B类中 组合定义了 A类对象 A类也设计了构造函数
//根据构造函数的调用规则  设计构造A类的构造函数必须要使用 没有机会初始化A
//新语法：Constructor::Contructor() : m1(v1), m2(v1,v2), m3(v3)
class B
{
public:
    B(int b1, int b2, int a1, int a2) : _a1(a1), _a2(a2)
    {
        _b1 = b1;
        _b2 = b2;
        cout << "B的构造函数被调用" << endl;
    }
    ~B()
    {
        cout << "B的析构函数被调用" << endl;
    }
private:
    int _b1;
    int _b2;
    A _a2;
    A _a1;
};

//2、先执行 被组合对象的构造函数 
//如果组合对象有多个  按照定义顺序调用  而不是按照初始化列表顺序进行
//
//析构函数：和构造函数调用顺序相反
//
//3、被组合的构造函数顺序 与定义顺序有关系  与初始化列表的顺序没有关系
//
//4、初始化列表 用来 给const  属性赋值
void objplay()
{
     B objB2(1, 2, 3, 4);
}
int main()
{
    objplay();
    std::cout << "Hello world" << std::endl;
    return 0;
}

