/*************************************************************************
  @FileName:  TimerThread.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 16时37分30秒
 ************************************************************************/
                                                                         
#include "Thread.h"
#include "Timer.h"

namespace morey
{

class TimerThread
{

using TimerCallback = function<void()>;
public:
    TimerThread(int initTime, int intervalTime, TimerCallback && cb)
    : _timer(initTime, intervalTime, move(cb))
    , _thread(bind(&Timer::start, &_timer))
    {}

    void start()
    {
        _thread.start();
    }

    void stop()
    {
        _timer.stop();
        _thread.join();
    }
private:
    Timer _timer;
    Thread _thread;
};

}//end of namespace morey
