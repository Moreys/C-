/*************************************************************************
  @FileName:  Consumer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:41:11 PM CST
 ************************************************************************/
                                                                         
#include "Consumer.h"
#include "TaskQueue.h"

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

namespace morey
{
void Consumer::get(TaskQueue & taskque)
{
    int cnt = 10;
    while(cnt--)
    {
        int number = taskque.pop();
        cout << "消费者pid = " << pthread_self()
            << " number = " << number << endl;
        ::sleep(2);
    }
}

}//end of namespace morey

