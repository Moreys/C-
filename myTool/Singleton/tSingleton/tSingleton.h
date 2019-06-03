#include <iostream>
using std::cout;
using std::endl;

template<typename Type>
class Singleton
{
    class AutoRelease
    {
    public:
        AutoRelease()
        {   cout << "AutoRelease()" << endl;     }

        ~AutoRelease()
        {
            cout << "~AutoRelease()" << endl;   
            if(_pInstance)
                delete _pInstance;
        }
    };

public:
    template<typename Type1,typename...Args>
static Type* getInstance(Type1 t2, Args ...args)
{
    if(nullptr == _pInstance)
    {
        _pInstance = new Type(t2, args...);
        (void)_autoRelease;
    }
    return _pInstance;
}


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
static Type * _pInstance;
static AutoRelease _autoRelease;
};

template<typename Type>
typename Singleton<Type>::AutoRelease Singleton<Type>::_autoRelease;

template<typename Type>
Type * Singleton<Type>::_pInstance = nullptr;

