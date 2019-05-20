#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

#include <iostream>
namespace morey
{

MyString::MyString(int len)
{
    if(0 == len)
    {
        _len = 0;
        _pstr = new char[_len +1];
        strcpy(_pstr, "");
    }
    else
    {
        _len = len;
        _pstr = new char[_len + 1];
        memset(_pstr, 0, len);
    }
}

MyString::MyString(const char *pstr)
{
    if(NULL == pstr)
    {
        _len = 0;
        _pstr = new char[_len + 1];
        strcpy(_pstr,"");
    }
    else
    {
        _len = strlen(pstr);
        _pstr = new char[_len + 1];
        strcpy(_pstr, pstr);
    }
}

//拷贝构造函数 S2 = S3
MyString::MyString(const MyString & rhs)
{
    _len = rhs._len;
    _pstr = new char[_len + 1];
    strcpy(_pstr, rhs._pstr);
}

MyString::~MyString()
{
    delete [] _pstr;
}

void MyString::print() const
{
    if(_pstr != NULL)
    {
        cout << _pstr << endl;
    }
}
}//end of namespace morey
