/*************************************************************************
  @FileName:  WorkerThread.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 04:52:31 PM CST
 ************************************************************************/

#include "WorkerThread.h"
#include "Threadpool.h"

namespace morey
{

void WorkerThread::run()
{
    _threadpool.threadFun();
}

}//end of namespace morey
