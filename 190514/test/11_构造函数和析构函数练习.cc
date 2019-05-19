#include <iostream>
using namespace std;

class ABDC
{
public:
    ABDC(int a, int b, int c)
    {
        this->_a = a;
        this->_b = b;
        this->_c = c;
        cout << "ABD() construct a:" << this->_a << "b:" << this->_b
            << "c" << this->_c << endl;
    }
    ~ABDC()
    {
        cout << " ~ABCD() construct , a:" << this->_a << "b:" << this->_b << "c:" << this->_c << endl;
    }

    int getA()
    {
        return this->_a;
    }
private:
    int _a;
    int _b;
    int _c;
};

class MyE
{
public:
    MyE() : abcd1(1, 2, 3), abcd2(4, 5, 6), m(100)
    {
        cout << "MyD()" << endl;
    }
    ~MyE()
    {
        cout << "~MyE()" << endl;
    }
    MyE(const MyE & obj) : abcd1(7, 8, 9), abcd2(10, 11, 12), m(100)
    {
        cout << "MyD(const & obj)" <<endl;
    }
public:
    ABDC abcd1; //C++ 编译器不知道如何构造abcd1
    ABDC abcd2;
    const int m;
};

int doTing(MyE mye1)
{
    cout << "doTing() mye1.abcd1.a" << mye1.abcd1.getA() << endl;
    return 0;
}

int run2()
{
    MyE  myE;
    doTing(myE);
    return 0;
}
int run3()
{
    cout << "run3 is start" << endl;
    //ABDC(400, 500, 600);//err 有错误，临时对象声明周期
    ABDC abcd = ABDC(400, 500, 600);
    //若想直接调用构造函数呢
    //必须使用一个对象的类型去承接  才能将临时对象扶正  成为类的对象
    //
    cout << "run3 end" << endl;
    return 0;
}
int main()
{
    //run2();
    run3();
    std::cout << "Hello world" << std::endl;
    return 0;
}

