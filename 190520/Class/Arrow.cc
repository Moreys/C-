#include <iostream>
using std::cout;
using std::endl;
class Data
{
public:
    Data(int ix = 0) : _ix(ix)
    {
        cout << "Data(int = 0)" << endl;

    }
    int ix() const {    return _ix;     }
    ~Data() {   cout << "~Data()" << endl;  }
private:
    int _ix;
};

class MiddleLayer
{
public:
    MiddleLayer(Data * pdata) : _pdata(pdata)
    {
        cout << "MiddleLayer()" << endl;
    }
    //指针访问运算符
    Data * operator->()
    {
        return _pdata;
    }
    //解引用运算符
    Data & operator*()
    {
        return *_pdata;
    }
    ~MiddleLayer()
    {
        cout << "~MiddleLayer()" << endl;
        if(_pdata)
        {
            delete _pdata;
        }
    }

private:
    Data * _pdata;
};
void test1()
{
    //只能指针的雏形
    MiddleLayer pData(new Data(10));
    pData->ix();
    (*pData).ix();
}
int main()
{
    test1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

