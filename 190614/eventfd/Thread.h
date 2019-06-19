/*************************************************************************
  @FileName:  Thread.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 16时21分24秒
 ************************************************************************/
                                                                         
#ifndef __THREAD_H__
#define __THREAD_H__
#include "Noncopyable.h"

#include <pthread.h>
#include <functional>

namespace morey
{

class Thread
: Noncopyable
{
public:
    using ThreadCallback = std::function<void()>;
    Thread(ThreadCallback && cb)
    : _pthid(0)
    , _isRunning(false)
    , _cb(std::move(cb))
    {}

    ~Thread();

public:
    void start();
    void join();

private:
    static void * threadFunc(void*);

private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
};

}//end of namespace moery

#endif

