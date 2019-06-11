/*************************************************************************
  @FileName:  producer.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 06:06:17 PM CST
 ************************************************************************/
#ifndef __PRODUCER_H__
#define __PRODUCER_H__
#include "Thread.h"
#include <iostream>
using namespace std;


namespace  morey
{
//类的前置声明，可以减少头文件的依赖
class TaskQueue;

class Producer : public Thread
{
public:
    Producer(TaskQueue & tasque)
    : _tasque(tasque)
    {}
private:
    void run();
private:
    TaskQueue & _tasque;
};

}//end of namespace morey

#endif

