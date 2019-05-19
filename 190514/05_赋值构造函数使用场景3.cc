#include <iostream>
using namespace std;
class Loaction
{
public:
    Loaction(int xx = 0, int yy = 0)
    {
        _x = xx;
        _y = yy;
        cout << "Constructor Object..." << endl;
    }
    //拷贝构造函数 完成对象的初始化
    Loaction(const Loaction & obj)
    {
        _x = obj._x;
        _y = obj._y;
    }
    ~Loaction()
    {
        cout << _x << "," << _y << "obj" << endl;
    }
public:
    int GetX()
    {
        return _x;
    }
    int GetY()
    {
        return _y;
    }
private:
    int _x;
    int _y;
};

//业务函数 形参是一个元素
void f(Loaction p)
{
    cout << p.GetX() << endl;
}

void playObj()
{
    Loaction a(1, 2);
    Loaction b = a;
    cout << "b对象已经初始化完毕" << endl;
    f(b);// b实参取初始化形参p,会调用copy构造函数 ;调用 p.GetX 得到x的值
}
int main()
{
    playObj();
    std::cout << "Hello world" << std::endl;
    return 0;
}

