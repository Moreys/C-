#include <iostream>

using std::cout;
using std::endl;

class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {
            cout << "AutoRelease()" << endl;
        }
        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;
            if(_pInstance)
            {
                delete _pInstance;
            }
        }
    };
public:
    static Singleton * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
    void print() const {    cout << "print()" << endl;}
    static void destroy()
    {
        if(_pInstance)
        {
            delete  _pInstance;
        }
    }
    friend class AutoRelease;
private:
    Singleton(){    cout << "Singleton()" << endl;}
    ~Singleton(){   cout << "~Singleton()" << endl;}
private:
    static Singleton * _pInstance;
    static AutoRelease _autoRelease;
};

Singleton::AutoRelease Singleton::_autoRelease;
Singleton * Singleton::_pInstance = nullptr;
int main()
{
    Singleton *p = Singleton::getInstance();
    p->print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

