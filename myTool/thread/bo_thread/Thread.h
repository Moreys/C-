/*************************************************************************
  @FileName:  Noncopyable.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 10:55:56 AM CST
 ************************************************************************/
                                                                         
#pragma once
#include "Noncopyable.h"
#include <pthread.h>
#include <functional>
#include <string>
using  std::string;


namespace morey
{

extern __thread const char * threadName;

class Thread : Noncopyable
{ 
public:
    using TrreadCallback = std::function<void()>;
    Thread(TrreadCallback && cb, const string & name = string())
    : _pthid(0)
    , _isRunning(false)
    , _cb(std::move(cb))
    , _name(name)
    {}
    void start();
    void join();
    ~Thread();
private:
    static void * threadFunc(void *);
private:
    pthread_t _pthid;
    bool _isRunning;
    TrreadCallback _cb; //回调函数进行处理
    string _name;
};

}//end of namespace morey
