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

