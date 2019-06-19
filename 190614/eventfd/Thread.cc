/*************************************************************************
  @FileName:  Thread.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 16时21分24秒
 ************************************************************************/

#include "Thread.h"
#include <stdio.h>
#include <errno.h>
#include <iostream>
using std::endl;
using std::cout;

namespace morey
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

void Thread::start()
{
    if(pthread_create(&_pthid, nullptr, threadFunc, this))
    {
        perror("pthread_create");
        return;
    }
}
void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

void * Thread::threadFunc(void * arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
        pthread->_cb();
    return nullptr;
}

}//end of namespace moery


