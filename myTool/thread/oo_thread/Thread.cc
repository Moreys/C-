/*************************************************************************
  @FileName:  Thread.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 05:07:46 PM CST
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

void Thread::start()
{
    if(pthread_create(&_pthid,nullptr,threadFunc, this))
    {
        perror("pthread_create");
        return;
    }
    _isRunning = true;
}
    
void Thread::join()
{
    if(_isRunning)
    {
        pthread_join(_pthid, nullptr);
        _isRunning = false;
    }
}

//回调函数，通过回调函数来进行调用私有的run函数
void * Thread::threadFunc(void * arg)
{
    Thread * pthread = static_cast<Thread*>(arg);
    if(pthread)
        pthread->run();
    return nullptr;
}

}//end of namespace morey

