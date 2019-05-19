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
/*g 函数  返回一个元素
 * 结论1 ： 函数的返回值是一个元素 （赋值数据类型） 返回的是一个新的匿名对象（所有会调用匿名对象类的copy构造函数)
 *
 * 结论2 ： 有关匿名对象的去和留
 * 如果用匿名对象   初始化  另一个同类型的对象    匿名对象    匿名对象转为有名对象
 * 如果用匿名对象   赋值给  另一个同类型的对象    匿名对象  被析构
 *
 * */
// 如果是这样写  那么C++编译器默认返回的就是一个新对象（匿名对象）只是没有名字而已·
Loaction g() //没有参数
{
    Loaction A(1, 2);
    return A;
}
void objplay2()
{
    g();
}

void objplay3()//匿名对象  被扶正  留  初始化
{
    //用匿名对象初始化 m  此时C++编译器 直接把匿名对象转成m,  从匿名转成了有名的m
    Loaction m = g();
    cout << "匿名函数被扶正 不会被析构" << endl;
    cout << m.GetX() << endl;
}

void objplay4() //匿名对象为去  赋值给另一个对象   赋值操作
{
    //用匿名对象赋值给m2 后 匿名对象会被析构
    Loaction m2(1, 2);
    m2 = g();
    cout << "因为匿名 对象 = 给了m2，  匿名 对象被析构" << endl;
    cout << m2.GetX() << endl;
}
int main()
{
    //objplay2();
    //objplay3();
    objplay4();
    std::cout << "Hello world" << std::endl;
    return 0;
}

