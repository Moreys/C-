#include <string.h>

#include <iostream>
using namespace std;

class String 
{
public:
    String() : _pstr(new char[1]())
    {
        cout << "String()" << endl;
    }
    String(const char *pstr)
    {
        _pstr = new char(strlen(pstr) + 1);
        strcpy(_pstr, pstr);
    }
    String(const String & rhs)
    {
        _pstr = new char(strlen(rhs._pstr) + 1);
        strcpy(_pstr, rhs._pstr);
    }
    String & operator=(const String & rhs)
    {
        cout << "String & operator = (cosnt String &rhs)" << endl;
        if(this != & rhs)
        {
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr)]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;
    }
    ~String()
    {
        delete [] _pstr;
    }
public:
    void print() const
    {
        if(_pstr != NULL)
        {
            cout << _pstr << endl;
        }
    }
private:
    char * _pstr;
};


int main()
{
    String s1;
    cout << "0000" << endl;
    s1.print();



    String str2 = "hello,world";
    String str3("wangdao");

    str2.print();
    str3.print();

    String str4 = str3;
    cout << "s4 = ";
    str4.print();
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

