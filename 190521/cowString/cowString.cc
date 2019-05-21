#include "cowString.h"

CowString::CowString() : _pstr(new char[1 + 4]() + 4)
{
    cout << "CowString()" << endl;
    initRefcount(); //进行初始化
}

CowString::CowString(const char * pstr) : _pstr(new char[strlen(pstr) + 5]() + 4)
{
    initRefcount();
    strcpy(_pstr, pstr);
    cout << "CowString(const char * pstr)" <<endl; 
}

CowString::CowString(const CowString & rhs) : _pstr(rhs._pstr)
{
    cout << "CowString(const CowString & rhs)" << endl;
    increaseRefcount();//让前面统计的引用计数加1
}

//深拷贝三部曲 
//框架  释放空间   从新赋值
CowString & CowString::operator=(const CowString & rhs)
{
    cout << "CowString::operator=()" << endl;
    if(nullptr == _pstr)
    {
        release();//释放空间的
        _pstr = rhs._pstr;
        increaseRefcount();//引用计数加1
    }
    return *this;
}

CowString::~CowString()
{
    release();
}

//下标访问运算符无法区分出接下来的操作是读操作  还是  写操作
//实现的只有写操作，没有考虑读操作的问题
char & CowString::operator[](int idx)
{
    cout << "char & operator[](int idx)" << endl;
    //读时共享 判断条件，为
    //
    if(idx >= 0 && idx < size())
    {
        if(refcount() > 1)
        {
            decreaseRefcount();
            char * ptmp = new char[size() + 5]() + 4;
            strcpy(ptmp, _pstr);
            initRefcount();
        }
        return _pstr[idx];
    }
    else if(idx <= 0 && idx > size())
    {
        if()
    }
    else
    {
        cout << "下标越界！" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
    
}

std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
    os << rhs._pstr;
    return os;
}

