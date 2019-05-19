#include <iostream>

using namespace std;

class Singleton
{
public:
    //在类的内部创建一个对象 返回指向该类型的指针
    //3、定义一个返回值为类指针的静态成员函数
    static Singleton * getInstance()
    {
        //判断是否为空 为空的情况下进行创建
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    //创建销毁函数 
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
        }
    }
    void print() const
    {
        cout << "Singleton::print()" << endl;
    }
private:
    //1、将构造函数和析构函数私有化
    Singleton()
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton" << endl;
    }
private:
    //2、在类中定义一个静态的 类指针变量
    static Singleton * _pInstance;
};
//4、使用初始化静态成员函数
Singleton * Singleton::_pInstance = nullptr;

int main()
{
    Singleton * p1 = Singleton::getInstance();
    Singleton * p2 = Singleton::getInstance();

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;
    Singleton::getInstance()->print();
    Singleton::destroy();
    std::cout << "Hello world" << std::endl;
    return 0;
}

