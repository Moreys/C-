#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;

template <typename Type >
class Singleton
{
public:
    static Singleton<Type> * getInstance()
    {
        if(_pInstance)
        {
            _pInstance = new Singleton<Type>();
        }
        return _pInstance;
    }
    void destroy();
private:
    Singleton();
    ~Singleton();
    friend class AutoRelease;
private:
    static Singleton<Type> * _pInstance;
};

template <typename Type>
Singleton<Type> * Singleton<Type>::_pInstance = nullptr;

    template <typename Type>
void Singleton<Type>:: destroy()
{
    if(_pInstance)
    {
        delete  _pInstance;
    }
}

class Point
{
public:
    Point(int x, int y)
        : _x(x)
          , _y(y)
    {
        cout << "Point()" << endl;
    }

private:
    int _x;
    int _y;
};

class Computer
{
public:
    Computer(string name, int number)
        : _name(name)
          , _number(number)
    {
        cout << "Computer()" << endl;
    }
private:
    string _name;
    int _number;

};

Point p1(1, 2);
Point p2(3, 4);

Computer c1("mac", 6666);
Computer c2("huasuo", 6666);



int main()
{

    Computer * p1 =  Singleton<Computer>::getInstance("Xiaomi", 6666);
    Computer * p2 =  Singleton<Computer>::getInstance("Xiaomi", 6666);

    Point * p3 = Singleton<Point>::getInstance(1, 2);
    Point * p4 = Singleton<Point>::getInstance(1, 2);
    return 0;
}

