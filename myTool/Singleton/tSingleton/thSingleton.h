#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class Singleton
{
public:

    static Singleton * getInstance()
    {
        pthread_once(&_once,init);
        return _pInstance;
    }
    
    template <class...args>
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
    static T * _pInstance;
    static pthread_once_t _once;
};

//Singleton::AutoRelease Singleton::_autoRelease;
template <class T>
class T * Singleton<T>::_pInstance = nullptr; // 懒汉模式
template <class T>
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
