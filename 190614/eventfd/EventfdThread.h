/*************************************************************************
  @FileName:  EventfdThread.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 20时30分42秒
 ************************************************************************/
                                                                         
#ifndef __EVENTFDTHREAD_H__
#define __EVENTFDTHREAD_H__

#include "Eventfd.h"
#include "Thread.h"

namespace morey
{

class EventfdThread
{
    using EventfdCallback = function<void()>;
public:
    EventfdThread(EventfdCallback && cb)
    : _eventfd(move(cb))
    , _thread(bind(&Eventfd::start, &_eventfd))
    {}

    void start()
    {
        _thread.start();
    }
    void stop()
    {
        _eventfd.stop();
        _thread.join();
    }
    void wakeup()
    {
        _eventfd.wakeup();
    }

private:
    Eventfd _eventfd;
    Thread _thread;
};

}//end of namespace morey

#endif

