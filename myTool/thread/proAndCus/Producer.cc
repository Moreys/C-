/*************************************************************************
  @FileName:  Producer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 10:34:09 AM CST
 ************************************************************************/

#include "Producer.hpp"
#include <time.h>
#include <stdlib.h>

namespace morey
{

void Producer::run() 
{
    ::srand(::clock());
    while(!_tasque.full())
    {
        cout << "生成者生成产品" << endl;
        int number = ::rand() % 100;
        cout << "sub thread " << pthread_self()
            << ": get a number = " << number << endl;
        _tasque.push(number);
        ::sleep(1);
    }
}
}//end of namespace morey;
