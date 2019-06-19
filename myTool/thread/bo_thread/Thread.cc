/*************************************************************************
  @FileName:  Therad.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 10:51:39 AM CST
 ************************************************************************/

#include "Thread.h"

#include <stdio.h>
#include <errno.h>
#include <iostream>
using std::cout;
using std::endl;

namespace  morey
{
 __thread const char * threadName = "morey thread";

using ThreadCallback = std::function<void()>;
struct ThreadData
{
    string _name;
    ThreadCallback _cb;
    ThreadData(const string name, ThreadCallback cb)
    : _name(name)
    , _cb(cb)
    {}
    void runInThread()
    {
        //任务执行之前，do songthing
        threadName = (_name == string()) ? "morey thread" : _name.c_str();
        if(_cb)
               _cb();

        //执行任务只有：do something.....
    } 

};

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
    ThreadData * data = new ThreadData(_name, _cb);
    if(pthread_create(&_pthid, nullptr, threadFunc,data))
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
    ThreadData * pdata = static_cast<ThreadData*>(arg);
    if(pdata)
    {
        pdata->runInThread();
    }
    delete  pdata;
    return nullptr;
}

}//end of namespace morey



