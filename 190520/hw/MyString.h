#ifndef __MYSTRING_H__
#define __MYSTRING_H__
#include <string.h>
#include <stdio.h>
#include <iostream>
using namespace std;

namespace morey
{

class MyString 
{
public:
    MyString();
    MyString(const char*);
    MyString(const MyString & );
    ~MyString();
public:
    MyString & operator= (const MyString & rhs);
    MyString & operator= (const char *);

    MyString & operator+=(const MyString &);
    MyString & operator+=(const char *);

    char &operator[](std::size_t index);
    const char &operator[](std::size_t index) const;

    std::size_t size() const;
    const char * c_str() const;

    friend bool operator==(const MyString &, const MyString &);
    friend bool operator!=(const MyString &, const MyString &);

    friend bool operator<(const MyString &, const MyString &);
    friend bool operator>(const MyString &, const MyString &);
    friend bool operator<=(const MyString &, const MyString &);
    friend bool operator>=(const MyString &, const MyString &);
    
    friend std::ostream &operator<<(std::ostream &os, const MyString &s);
    friend std::istream &operator>>(std::istream &is, MyString &s);
public:
    void print() const;
public:
    size_t length() const
    {
        return _len;
    }
private:
    char * _pstr;
    int _len;
};

}//end of namespace morey

#endif
