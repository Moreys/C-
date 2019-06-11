/*************************************************************************
  @FileName:  Producer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 10:34:09 AM CST
 ************************************************************************/

#include "Producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;
namespace morey
{

void Producer::run() 
{
    ::srand(::clock());
    int cnt = 10;
    while(cnt--)
    {

        int number = ::rand() % 100;
        _tasque.push(number);
        cout << "生产者pid = " << pthread_self()
            << "number = " << number << endl;
        ::sleep(1);
    }
}
}//end of namespace morey;
