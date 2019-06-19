/*************************************************************************
  @FileName:  Eventfd.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 20时13分47秒
 ************************************************************************/
                                                                         
#ifndef __EVENTFD_H__
#define __EVENTFD_H__
#include <functional>
#include <iostream>
using namespace std;

namespace morey
{

class Eventfd
{
    using EventfdCallback = function<void()>;
public:
    Eventfd(EventfdCallback && cb)
    : _fd(createEventfd())
    , _cb(move(cb))
    , _isStarted(false)
    {   
        cout << "Eventfd = " << _fd << endl;
    }

public:
    void start();
    void stop();
    void wakeup();
private:
    int createEventfd();
    void handleRead();
private:
    int _fd;
    EventfdCallback _cb;
    bool _isStarted;
};

}//end of namespace std;

#endif

