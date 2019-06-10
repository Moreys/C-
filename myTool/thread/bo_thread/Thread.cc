/*************************************************************************
  @FileName:  Therad.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 10:51:39 AM CST
 ************************************************************************/

#include "Thread.hpp"
#include <stdio.h>
#include <errno.h>
#include <iostream>
using std::cout;
using std::endl;

namespace  morey
{

Thread::~Thread()
{
    if(_isRunning)
    {
        pthread_detach(_pthid);
        _isRunning = false;
    }
    cout << "~Thread()" << endl;
}

//线程开启
void Thread::start()
{
    if(pthread_create(&_pthid,nullptr, threadFunc,this))
    {
        perror("pthread_create");
        return;
    }
    _isRunning = true;
}

//join：监听——pthid
void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

//回调函数：执行
//arg:传入参数
void * Thread::threadFunc(void * arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
    {
        pthread->_cb();
    }
    return nullptr;
}

}//end of namespace morey



