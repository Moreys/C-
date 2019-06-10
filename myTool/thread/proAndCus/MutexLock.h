#ifndef __MY_NUTEXLOCK_H__
#define __MY_NUTEXLOCK_H__

#include "Noncopyable.hpp"
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

namespace morey
{

class MutexLock
: Noncopyable
{
public:
    MutexLock() 
    : _isLocking(false)
    {
        //初始化互斥锁
        if(pthread_mutex_init(&_mutex, NULL))
        {
            perror("pthread_mutex_init");
        }
    }
    //封装lock
    void lock()
    {
        if(pthread_mutex_lock(&_mutex))
        {
            perror("pthread_mutex_lock");
        }
        _isLocking = true;
    }

    //封装unlock
    void unlock()
    {
        if(pthread_mutex_unlock(&_mutex))
        {
            perror("pthread_mutex_unlock");
        }
        _isLocking = false;
    }

    ~MutexLock()
    {
      if(pthread_mutex_destroy(&_mutex))
      {
          perror("pthread_mutex_destroy");
      }
    }
    
    //返回是否解锁的函数
    bool isLocking() const 
    {
        return _isLocking;
    }
    pthread_mutex_t * getMutexLockPtr() 
    {
        return &_mutex;
    }

private:
    pthread_mutex_t _mutex;
    bool _isLocking;

};

class MutexLockGuard
{
public:
    MutexLockGuard(MutexLock & mutex)
    : _mutex(mutex)
    {
        _mutex.lock();
    }
    ~MutexLockGuard()
    {
        _mutex.unlock();
    }
private:
    MutexLock & _mutex;
};

}//end if namespace morey
#endif


