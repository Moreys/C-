#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton * getInstance()
    {
        pthread_once(&_once,init);
        return _pInstance;
    }
    static void init()
    {
        _pInstance = new Singleton();
        ::atexit(destroy);
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
private:
    static Singleton * _pInstance;
    static pthread_once_t _once;
};

//Singleton::AutoRelease Singleton::_autoRelease;
Singleton * Singleton::_pInstance = nullptr; // 懒汉模式
//Singleton * Singleton::_pInstance = getInstance();//饱汉模式
//
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

int main(void)
{
    Singleton * p = Singleton::getInstance();
    p->print();
    return 0;
}

