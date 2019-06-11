/*************************************************************************
  @FileName:  Producer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:31:21 PM CST
 ************************************************************************/

#include "Producer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

namespace morey
{

void Producer::create(TaskQueue & taskque)
{
    ::srand(::clock());
    int cnt = 10;
    while(cnt--)
    {
        int number = ::rand() % 100;
        taskque.push(number);
        cout << "生产者pid = " << pthread_self()
            << " number = " << number << endl;
        sleep(1);
    }
}

}//end of namespace morey
