#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"

#include <iostream>
namespace morey
{

MyString::MyString() : _pstr(new char[1]()), _len(0){   }

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
    if(nullptr !=_pstr)
    {
        delete [] _pstr;
        _pstr = nullptr;
        _len = 0;
    }
}


// s1 = s2 释放旧空间 分配新空间
MyString& MyString::operator=(const MyString & rhs)
{
    if(nullptr == _pstr)
    {
        delete [] _pstr;
        _len = 0;
    }
    _len = rhs._len;
    _pstr = new char[_len + 1];
    strcpy(_pstr,rhs._pstr);
    return  *this;

}

//s1 = "fasdkjfla" 释放旧空间 开辟新空间
MyString & MyString::operator= (const char *pstr)
{
    if(nullptr == _pstr)
    {
        delete [] _pstr;
        _len = 0;
    }
    else if(nullptr == pstr)
    {
        _len = 0;
        _pstr = new char[_len + 1];
        strcpy(_pstr, "");
    }
    else
    {
        _len = strlen(pstr);
        _pstr = new char[_len + 1];
        strcpy(_pstr, pstr);
    }
    return *this;
}

MyString & MyString::operator+=(const MyString &pstr)
{
    _pstr = new char[_len + 1];
    strcat(_pstr, pstr._pstr);
    return  *this;
}
//有问题,不能正常进行
MyString & MyString::operator+=(const char *pstr)
{
    if(nullptr == _pstr)
    {
        delete [] _pstr;
        _len = 0;
    }
    else if(nullptr == pstr)
    {
        _len = 0;
        _pstr = new char[_len + 1];
        strcat(_pstr, "");
    }
    else
    {
        _len = strlen(pstr);
        _pstr = new char[_len + 1];
        strcat(_pstr, pstr);
    }
    return *this;
}

//要判断是否访问越界 如果越界就返回\0
char & MyString::operator[](std::size_t index)
{
    if(index < length())
    {
        return _pstr[index];
    }    
    else
    {
        static char nullchar = '\0';
        cout << ">> error下标越界！" << endl;
        return nullchar;
    }
}

const char & MyString::operator[](std::size_t index) const
{
    if(index < length())
    {
        return _pstr[index];
    }    
    else
    {
        static char nullchar = '\0';
        cout << ">> error下标越界！" << endl;
        return nullchar;
    }
}

void MyString::print() const
{
    if(_pstr != NULL)
    {
        cout << _pstr << endl;
    }
}

std::size_t MyString::size() const
{
    return _len;
}
const char * MyString::c_str() const
{
    return _pstr;
}

std::istream &operator>>(std::istream &in, MyString &pstr)
{
    cin >> pstr._pstr;
    return in;
}

bool operator==(const MyString &pstr1, const MyString &pstr2)
{
    if(pstr1.length() != pstr2.length())
    {
        return false;
    }
    return !strcmp(pstr1._pstr, pstr2._pstr);
}

bool operator!=(const MyString &pstr1, const MyString &pstr2)
{
    return !(pstr1 == pstr2 );
}

bool operator<(const MyString &pstr1, const MyString &pstr2)
{
    return strcmp(pstr1._pstr, pstr2._pstr);
}
bool operator>(const MyString &pstr1, const MyString &pstr2)
{
    
    return strcmp(pstr1._pstr, pstr2._pstr);
}

bool operator<=(const MyString &pstr1, const MyString &pstr2)
{
    if(strcmp(pstr1._pstr, pstr2._pstr) == 0)
    {
        return true;
    }
    else if(strcmp(pstr1._pstr, pstr2._pstr) == -1)
    {
        return true;
    }
    return  false;
}

bool operator>=(const MyString &pstr1, const MyString &pstr2)
{
    if(strcmp(pstr1._pstr, pstr2._pstr) == 0)
    {
        return true;
    }
    else if(strcmp(pstr1._pstr, pstr2._pstr) == 1)
    {
        return true;
    }
    return false;
}

std::ostream &operator<<(std::ostream &out, const MyString &pstr)
{
    cout << pstr._pstr;
    return out;
}
}//end of namespace morey
