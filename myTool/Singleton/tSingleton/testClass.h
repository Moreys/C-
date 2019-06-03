#ifndef __TESTCLASS_H__
#define __TESTCLASS_H__
#include <iostream>
#include <string>
using std::endl;
using std::cout;
using std::string;
class Point
{
public:
    Point(int x, int y)
    : _x(x)
    , _y(y)
    {
        cout << "Point()" << endl;
    }
    void prinT()const
    {
        cout << "x = " << _x << endl <<  "y = " << _y << endl;
    }
    ~Point()
    {
        cout << "~Point()" << endl;
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
        cout << "Point()" << endl;
    }
    void prinT()const
    {
        cout << "name =  " << _name << endl
             <<"number = " << _number << endl;
    }
    ~Computer()
    {
        cout << "~Point()" << endl;
    }
private:
    string _name;
    int _number;
};
#endif
