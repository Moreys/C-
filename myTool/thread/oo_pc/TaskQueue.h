/*************************************************************************
  @FileName:  TaskQueue.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 10:15:47 AM CST
 ************************************************************************/

#ifndef __TASKQUEUE_H__
#define __TASKQUEUE_H__

#include "Condition.h"
#include "MutexLock.h"

#include <queue>
using namespace std;

namespace  morey
{

class TaskQueue
{
public:
    TaskQueue(size_t queSize = 10)
    : _queSize(queSize)
    , _que()
    , _mutex()
    , _notFull(_mutex)
    , _notEmpty(_mutex)
    {}

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
