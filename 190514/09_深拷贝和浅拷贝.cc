#include <string.h>

#include <iostream>

using namespace std;
class Name
{
public:
    Name(const char * myp)
    {
        _len = strlen(myp);
        _p = new char(_len +1);
        strcpy(_p, myp);
    }
    //Name obj2 = obj1;
    //手工写一个拷贝构造函数  进行深拷贝
    Name(const Name & obj)
    {
        _len = obj._len;
        _p = new char(obj._len + 1);
        strcpy(_p, obj._p);
    }
    ~Name()
    {
        if(_p != NULL)
        {
            delete _p;
            _p = NULL;
            _len = 0;
        }
    }
private:
    char *_p;
    int _len;
};

void objplay()
{
    Name obj1("objplay");
    Name obj2 = obj1;
    Name obj3("obj3");
    //obj3 = obj1;//err C++默认提供的 = 号也是浅拷贝   解决，进行 =  号操作符重载
}
int main()
{
    objplay();
    std::cout << "Hello world" << std::endl;
    return 0;
}

