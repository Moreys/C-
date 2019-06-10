/*************************************************************************
  @FileName:  customer.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 06:03:22 PM CST
 ************************************************************************/
#ifndef __CUSTOMER_HPP__
#define __CONDITION_H__
#include "Thread.hpp"
#include "TaskQueue.hpp"
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>

namespace  morey
{

class Customer : public Thread
{
public:
    Customer(TaskQueue &tasque)
    : Thread() 
    , _tasque(tasque)
    {}
    ~Customer() { cout << "~Customer()" << endl; }
private:
    void run() override
    {
        ::srand(::clock());
        while(!_tasque.empty())
        {
            cout << "消费者消费产品" << endl;
            cout << "sub thread " << pthread_self()
                 << ": get a number = " << _tasque.pop() << endl;
            _tasque.pop();
            //::sleep(1);
        }
    }
private:
    TaskQueue & _tasque;
};
}//end of namespace morey;
#endif
