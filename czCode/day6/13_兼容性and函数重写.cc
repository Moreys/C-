#include <iostream>
using std::cout;
using std::endl;

class Parent
{
public:
    Parent(int a) : _a(a)
    {
        cout << "Parent()" << a << endl;
    }
//     void print()//子类和父类的函数名是一样的，没有写virtual时每次都调用父类的
     virtual void print()//
    {
        cout << "Parent 打印 a" << _a << endl;
    }
private:
    int _a;
};

class Child : public Parent
{
public:
    Child(int b)
        : Parent(10)
        , _b(b)
    {
        cout << "Child()" << b << endl;
    }
     void print() //virtual 父类写了virtual ，子类可以不用写
                        //不过一般还写出来表明这个也是virtual的
    {
        cout << "Child 打印 b " << _b << endl;
    }
private:
    int _b;
};

//指针实现舞台
void howToPrint(Parent *base)
{
    base->print();
}
//引用实现舞台
void howToPrint2(Parent &base)
{
    base.print();
}

//如果父类没有写虚函数 不管何种方式的调用都是调用父类的print()函数
//如果父类写了构造函数为虚函数  则不同的调用对象调用相同的函数则各自调用各自的函数
//
int main()
{
    Parent *base = nullptr;
    Parent p1(20);
    Child c1(30);
    base = &p1;
    base->print();

    base = &c1;
    base->print();//
    std::cout << "Hello world" << std::endl;
    howToPrint(&p1);
    howToPrint(&c1);
    howToPrint2(p1);
    howToPrint2(c1);
    return 0;
}

