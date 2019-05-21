#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
    class AutoRelease
    {
    public:
        //在多线程的情况下是不安全的，可以加锁解决
        //但是在锁以后回影响效率，所有可以采用POSIX 下atexit + 静态方法
        AutoRelease()
        {   cout << "AutoRelease()" << endl;    }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;   
            if(_pInstance)
                delete _pInstance;
        }
    };
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
            _pInstance = new Singleton();
        return _pInstance;
    }

    void print() const {    cout << "print()" << endl;  }   

    static void destroy()
    {
        if(_pInstance)
            delete _pInstance;

    }

private:
    Singleton() {   cout << "Singleton()" << endl;  }
    ~Singleton() {  cout << "~Singleton()" << endl; }

    friend class AutoRelease;
private:
    static Singleton * _pInstance;

};

//Singleton::AutoRelease Singleton::_autoRelease;
//Singleton * Singleton::_pInstance = nullptr;  懒汉模式
Singleton * Singleton::_pInstance = getInstance();//饱汉模式

int main(void)
{
    Singleton * p = Singleton::getInstance();
    p->print();
    //传递的是析构函数或者是销毁函数
    atexit(p->destroy);
    return 0;
}

