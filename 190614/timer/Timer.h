/*************************************************************************
  @FileName:  Timer.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 12时29分39秒
 ************************************************************************/
                                                                         
#ifndef __TIMER_H__
#define __TIMER_H__

#include <functional>
using namespace std;

namespace morey
{

class Timer
{
    using TimerCallback = function<void()>;
public:
    Timer(int initTime, int intervalTime, TimerCallback && cb)
    : _fd(createTimerfd())
    , _initalTime(initTime)
    , _intervalTime(intervalTime)
    , _cb(move(cb))
    , _isStarted(false)
    {}

public:
    void start();
    void stop();
    void setTimer(int initTime, int intervalTime);

private:
    int createTimerfd();
    void handleRead();

private:
    int _fd;
    int _initalTime;
    int _intervalTime;
    TimerCallback _cb;
    bool _isStarted;
};

}//end of morey

#endif

