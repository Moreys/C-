/*************************************************************************
  @FileName:  Thread.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 05:04:38 PM CST
 ************************************************************************/
                                                                         
#pragma once

#include "Noncopyable.h"
#include <pthread.h>

namespace morey
{

class Thread : Noncopyable
{
public:
    Thread()
    : _pthid(0)
    , _isRunning(false)
    {}

    ~Thread();
    void start();
    void join();

private:
    virtual void run() = 0;
    static void * threadFunc(void *);
private:
    pthread_t _pthid;
    bool _isRunning;
};

}//end if namespace morey
