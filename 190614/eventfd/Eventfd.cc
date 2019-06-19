/*************************************************************************
  @FileName:  Eventfd.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 20时13分47秒
 ************************************************************************/

#include "Eventfd.h"                                                                 
#include <unistd.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>
using namespace std;

namespace morey
{

void Eventfd::start()
{
    _isStarted = true;

    struct pollfd pfd;
    pfd.fd = _fd;
    pfd.events = POLLIN;

    while(_isStarted)
    {
        int nready = ::poll(&pfd, 1, 5000);
        if(-1 == nready && errno == EINTR)
        {
            continue;
        }
        else if(-1 == nready)
        {
            perror(">> poll");
            return;
        }
        else if(0 == nready)
        {
            printf(">> poll timeout");
        }
        else
        {
            if(pfd.revents & POLLIN)
            {
                handleRead();//处理读事件
                //如果没有处理该事件，会一直触发
                if(_cb)
                    _cb();
            }
        }
    }
}

void Eventfd::stop()
{
    if(_isStarted)
    {
        _isStarted = false;
    }
}
void Eventfd::wakeup()
{
    uint64_t one = 1;
    int ret = ::write(_fd, &one, sizeof(one));
    if(ret != sizeof(one))
    {
        perror(">> write");
    }
}

int Eventfd::createEventfd()
{
    int fd = ::eventfd(10, 0);
    if(-1 == fd)
    {
        perror(">> eventfd");
    }
    return fd;
}

void Eventfd::handleRead()
{
    uint64_t howmany;
    int ret = ::read(_fd, &howmany, sizeof(howmany));
    if(ret != sizeof(howmany))
    {
        perror(">> read");
    }
}

}//end of namespace std;


