#include <iostream>

using namespace std;
class Parent
{
public:
    Parent(int a = 0)
        : _a(a)
    {
    }
    virtual void print()
    {
        cout << "我是爹" << endl;
    }
private:
    int _a;
};
class Parent1
{
public:
    Parent1(int a = 0)
        : _a(a)
    {
    }
    virtual void print()
    {
        cout << "我是爹" << endl;
    }
private:
    int _a;
};

int main()
{
    cout << "sizeof(Parent) = " << sizeof(Parent)
        << "sizeof(Parent1) = " << sizeof(Parent1) << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

