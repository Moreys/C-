/*************************************************************************
  @FileName:  TaskQueue.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:10:18 PM CST
 ************************************************************************/
                                                                         
#pragma once
#include "MutexLock.hpp"
#include "Condition.hpp"

#include <queue>
using std::queue;

namespace morey
{

class TaskQueue
{
public:
    TaskQueue(size_t queSize = 10)
    : _queSize(queSize)
    , _notFull(_mutex)
    , _notEmpty(_mutex)
    {}
public:
    bool full() const;
    bool empty() const;
    void push(int number);
    int pop();

private:
    size_t _queSize;
    queue<int> _que;
    MutexLock _mutex;
    Condition _notFull;
    Condition _notEmpty;
};

}//end of namespace morey
