/*************************************************************************
  @FileName:  TestEventfd.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 20时34分56秒
 ************************************************************************/
                                                                         
#include "EventfdThread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
#include <functional>
using namespace std;

struct Mytask
{
    void process()
    {
        ::srand(::time(NULL));
        int number = ::rand() % 100;
        cout << "pid = " << pthread_self()
            << " number = " << number << endl;
    }
};

int main()
{
    morey::EventfdThread eventfd(bind(&Mytask::process, Mytask()));
    eventfd.start();
    
    int cnt = 20;
    while(cnt--)
    {
        cout << "cnt = " << cnt << endl
            << "min thread notify sub thread to do something..." << endl;
        eventfd.wakeup();
        ::sleep(1);
    }
    
    std::cout << "main thread eventfd stop" << std::endl;
    eventfd.stop();
    return 0;
}

