/*************************************************************************
  @FileName:  customer.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 06:03:22 PM CST
 ************************************************************************/
#ifndef __CUSTOMER_H__
#define __CUSTOMER_H__
#include "Thread.h"

namespace  morey
{

class TaskQueue;

class Customer : public Thread
{
public:
    Customer(TaskQueue & tasque)
    : _tasque(tasque)
    {}
private:
    void run();
private:
    TaskQueue & _tasque;
};
}//end of namespace morey;
#endif
