/*************************************************************************
  @FileName:  TaskQueue.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 10:15:47 AM CST
 ************************************************************************/

#ifndef __TASKQUEUE_HPP__
#define __TASKQUEUE_HPP__
#include "Condition.h"
#include "MutexLock.h"

#include <iostream>
#include <queue>
using namespace std;
using namespace morey;

namespace  morey
{

class TaskQueue
{
public:
    TaskQueue(size_t);
    ~TaskQueue();

public:
    void push(int);
    int pop();
    bool full() const; //不修改数据成员的加上const
    bool empty() const;

private:
    size_t _queSize;
    queue<int> _que;
    MutexLock  _mutex;
    Condition _notFull;
    Condition _notEmpty;
};

}//end of namespace morey
#endif


