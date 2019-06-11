/*************************************************************************
  @FileName:  WorkerThread.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 04:48:34 PM CST
 ************************************************************************/
                                                                         
#pragma once

#include "Thread.h"

#include <iostream>

using std::endl;
using std::cout;

namespace morey
{

class Threadpool;

class WorkerThread
: public Thread
{
public:
    WorkerThread(Threadpool & pthreadpool)
    : _threadpool(pthreadpool)
    {}
    ~WorkerThread() {   cout << "~WorkerThread()" << endl;  }

private:
    void run();

private:
    Threadpool & _threadpool;
};

}//end of namespace morey
