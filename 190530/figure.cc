/*************************************************************************
  @FileName:  figure.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 31 May 2019 10:01:06 AM CST
 ************************************************************************/
#include <math.h>
#include <functional>
#include <iostream>

using namespace std;

class Figure
{
public:
    typedef function<void()> DisplayCallback;
    typedef function<double()> AreaCallback;
    void setDisplayCallback(DisplayCallback cb)
    {
        _cb1 = cb;
    }
    void setAreaCallback(AreaCallback cb)
    {
        _cb2 = cb;
    }
    void handleDisplayCallback()
    {
        if()
    }

private:
    DisplayCallback _cb1;
    AreaCallback _cb2;

};
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

