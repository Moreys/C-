#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <string.h>
#include <iostream>
using namespace std;

namespace morey
{

class MyString 
{
public:
    MyString();
    MyString(int len = 0);
    MyString(const char*);
    MyString(const MyString & );
    ~MyString();

    MyString & operator=(const MyString & rhs);
public:
    void print() const;
public:
    char * c_str()
    {
        return _pstr;
    }
    const char * c_str2()
    {
        return _pstr;
    }
    int length()
    {
        return _len;
    }
private:
    char * _pstr;
    int _len;
};

}//end of namespace morey

#endif
