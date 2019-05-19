#include <iostream>
using namespace std;

class BB
{
public:
    void printC()
    {
        cout << "c:" << c << endl;
    }
    void Addc()
    {
        c = c + 1;
    }
    static void getC()
    {
        cout << "c:" << c << endl;
        //在静态成员函数中 不能调用普通成员属性 或者普通成员函数
        //cout << "a:" << a << endl; //err use 
    }
private:
    int _a;
    int _b;
    static int c; // 静态成员变量

};

//静态函数中 不能使用普通成员变量和普通成员函数
int BB::c = 10;
int main()
{
    BB b1, b2, b3;
    b1.printC();
    b2.Addc();
    b3.printC();

    //静态成员函数调用方法
    b3.getC();//用对象
    BB::getC();//类
    std::cout << "Hello world" << std::endl;
    return 0;
}

