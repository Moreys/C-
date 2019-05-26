#include <iostream>
using std::cout;
using std::endl;

class Herofighter
{
public:
    //1、父类定义为虚函数
    virtual int power() //C++会对这个函数特殊处理
    {
        return 10;
    }
};
class EnemyFighter
{
public:
    int attack()
    {
        return 15;
    }
};

//2、需要继承父类
class Advherofighter : public Herofighter
{
public:
    virtual int power()
    {
        return 20;
    }
};
//2、需要继承
class AdvAdvHerofighter : public Herofighter
{
public:
    virtual int power()
    {
        return 30;
    }
};

//3、用父类指针(父类引用) 指向子类对象....
void PlayObj(Herofighter *hf, EnemyFighter *ef)
{
    //如果父类不写virtual关键字，是静态联编，
    //C++编译器根据Herofighter类型去执行 这个类的power函数
    //在编译阶段已经决定了函数的调用
    //
    //动态联编：迟绑定：在运行的时候，根据具体对象（具体的类型）
    //执行不同对象的函数，表示成多态
    if(hf->power() > ef->attack())
    {
        cout << "主角win" << endl;
    }
    else
    {
        cout << "主角die" << endl;
    }
}


/*
 * 多态的思想
 * 面向对象3大概念
 * 封装：突破C函数的概念，用来做函数参数的时候，可以使用对象的属性，和对象的方法
 * 继承： A B 代码复用
 * 多态：可以在未来使用
 *
 * 多态很重要
 * 1、C语言实现间接赋值的三个条件
 *    定义两个变量
 *    建立关联
 *    *p在被调用函数中去间接修改实参的值
 *
 *
 * 2、多态实现的三个条件
 *  要有继承
 *  要有虚函数重写
 *  用父类指针(引用)指向子类对象
 *
 * */
int main()
{

    Herofighter hf;
    Advherofighter advHf;
    EnemyFighter ef;
    cout << "Herofighter()" << endl;
    PlayObj(&hf, &ef);

    cout << "AdvHerofighter()" << endl;
    PlayObj(&advHf, &ef);

    cout << "advAdvHerofighter()" << endl;
    AdvAdvHerofighter advadvHf;
    PlayObj(&advadvHf, &ef);//这个框架 能把我们后来人写的代码调用起来

    std::cout << "Hello world" << std::endl;
    return 0;
}

