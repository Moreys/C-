/*************************************************************************
  @FileName:  TestTimer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 16时43分59秒
 ************************************************************************/
                                                                         
#include "TimerThread.h"
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
        cout << ">> pid =  " << pthread_self()
            << " number = " << number << endl;
    }
};

int main()
{
    morey::TimerThread timer(3, 6, bind(&Mytask::process, Mytask()));
    
    timer.start();
    ::sleep(20);

    std::cout << "主线程时间停止" << std::endl;
    timer.stop();
    return 0;
}

