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

class Task;
using ElemType = Task *;

class TaskQueue
{
public:
    TaskQueue(size_t queSize = 10)
    : _queSize(queSize)
    , _que()
    , _mutex()
    , _notFull(_mutex)
    , _notEmpty(_mutex)
    , _exitFlag(false)
    {}

public:
    bool full() const; //不修改数据成员的加上const
    bool empty() const;
    void push(const ElemType & elem);
    ElemType pop();
    void weakup();

private:
    size_t _queSize;
    queue<ElemType> _que;
    MutexLock  _mutex;
    Condition _notFull;
    Condition _notEmpty;
    bool _exitFlag;
};

}//end of namespace morey
#endif
