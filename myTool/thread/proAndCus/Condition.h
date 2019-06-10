#ifndef __CONDITION_H__
#define __CONDITION_H__

#include "Noncopyable.hpp"
#include "MutexLock.h"
#include "pthread.h"

namespace morey
{

class Condition
: Noncopyable
{
public:
    Condition(MutexLock & mutex)
    : _mutex(mutex)
    {
        if(pthread_cond_init(&_cond, nullptr))
        {
            perror("pthread_cond_init");
        }
    }

    //封装wait
    void wait()
    {
        if(pthread_cond_wait(&_cond, _mutex.getMutexLockPtr()))
        {
            perror("pthread_cond_wait");
        }
    }
    
    void notify()
    {
        if(pthread_cond_signal(&_cond))
        {
            perror("pthread_cond_signal");
        }
    }

    void notifyAll()
    {
        if(pthread_cond_broadcast(&_cond))
        {
            perror("pthread_cond_broadcast");
        }
    }
    
    ~Condition()
    {
        if(pthread_cond_destroy(&_cond))
        {
            perror("pthread_cond_destroy");
        }
    }

private:
    pthread_cond_t _cond;
    MutexLock & _mutex;//占据一个指针 类类型的指针，其实还是指针，只不过是指向一个类而已
};

}//end of namespace morey
#endif

