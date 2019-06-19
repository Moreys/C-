/*************************************************************************
  @FileName:  Timer.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 12时29分39秒
 ************************************************************************/

#include "Timer.h"

#include <unistd.h>
#include <poll.h>
#include <sys/timerfd.h>

#include <iostream>

using namespace std;

namespace morey
{

//function: 开始计时
void Timer::start()
{
    _isStarted = true;
    setTimer(_initalTime, _intervalTime);
    struct pollfd pfd;
    pfd.fd = _fd;
    pfd.events = POLLIN;

    while(_isStarted)
    {
        int nready = ::poll(&pfd, 1, 5000);
        if(nready == -1 && errno == EINTR)
        {
            continue;
        }
        else if(-1 == nready)
        {
            perror(">> poll error");
            return;
        }
        else if(0 == nready)
        {
            cout << ">> poll timeout! " << endl;
        }        
        else
        {
            if(pfd.revents & POLLIN)
            {
                handleRead();//事件读事件
                //如果没有处理该事件，会一直触发
                if(_cb)
                    _cb();//执行事件
            }
        }
    }
}

//function: 停止计时
void Timer::stop()
{
    if(_isStarted)
    {
        setTimer(0, 0);
        _isStarted = false;
    }
}

//function: 设置时间
//args: initTime:初始时间  intervalTime:结束时间
void Timer::setTimer(int initTime, int intervalTime)
{
    struct itimerspec value;
    value.it_value.tv_sec = initTime;
    value.it_value.tv_nsec = 0;
    value.it_interval.tv_sec = intervalTime;
    value.it_interval.tv_nsec = 0;

    int ret = ::timerfd_settime(_fd, 0, &value, nullptr);
    if(-1 == ret)
    {
        perror(">>timerfd_settime");
    }
}

//function: 创建一个时间fd
int Timer::createTimerfd()
{
    int fd = ::timerfd_create(CLOCK_REALTIME, 0);
    if(-1 == fd)
    {
        perror("timerfd_create");
    }
    return fd;
}

//function: 处理读取事件
void Timer::handleRead()
{
    uint64_t howmany;
    int ret = ::read(_fd, &howmany, sizeof(howmany));
    if(ret != sizeof(howmany))
    {
        perror(">> read err");
    }
}

}//end of morey


