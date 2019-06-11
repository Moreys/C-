/*************************************************************************
  @FileName:  TaskQueue.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 11:15:59 AM CST
 ************************************************************************/

#include "TaskQueue.h"
#include <iostream>

using namespace std;

namespace morey
{

//function:产品队列进元素
//ind:产品id
void TaskQueue::push(int idx)
{
    {
    MutexLockGuard autoLock(_mutex);  //通过生命周期进行安全加锁和解锁
    while(full())  //while是为了防止异常唤醒
    {
        _notFull.wait();  //存在异常唤醒
    }//使用语句块减小加锁的范围
    _que.push(idx);
    }
    _notEmpty.notify();
}

//function:产品对象出元素
//return: temp:出栈元素
int TaskQueue::pop()
{
    int tmp;
    {
    MutexLockGuard autoLock(_mutex);
    while(empty())
    {
        _notEmpty.wait();
    }
    tmp = _que.front();
    _que.pop();
    }
    _notFull.notify();
    return tmp;
}

//function:队列是否已满
bool TaskQueue::full() const 
{
    return _que.size() == _queSize;
}

//function:队列是否为空
bool TaskQueue::empty() const
{
    return _que.empty();
}

}//end of namespace morey
