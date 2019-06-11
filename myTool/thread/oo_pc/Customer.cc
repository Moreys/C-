/*************************************************************************
  @FileName:  customer.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 06:03:22 PM CST
 ************************************************************************/
#include "Customer.h"
#include "TaskQueue.h"

#include <unistd.h>

#include <iostream>
using namespace std;

namespace  morey
{

void Customer::run() 
{
    int cnt = 10;
    while(cnt--)
    {
        int number = _tasque.pop();
        cout << "消费pid = " << pthread_self()
            << "number = " << number << endl;
        ::sleep(2);
    }
}
}//end of namespace morey;
