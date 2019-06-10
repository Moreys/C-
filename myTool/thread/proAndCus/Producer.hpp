/*************************************************************************
  @FileName:  producer.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 06:06:17 PM CST
 ************************************************************************/
#ifndef __PRODUCER_HPP__
#define __PRODUCER_HPP__
#include "Thread.hpp"
#include <iostream>
using namespace std;


namespace  morey
{
//类的前置声明，
class TaskQueue;
class Producer : public Thread
{
public:
    Producer(TaskQueue & tasque)
    : _tasque(tasque)
    {cout << "Producer()" << endl;}
    ~Producer(){cout << "~Producer()" << endl;}
private:
    void run() override;
private:
    TaskQueue & _tasque;
};

}//end of namespace morey

#endif

