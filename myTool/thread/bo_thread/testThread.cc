/*************************************************************************
  @FileName:  testThread.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 04:33:09 PM CST
 ************************************************************************/
                                                                         
#include "Thread.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>

using namespace std;

class MyTask
{
public:
    ~MyTask(){cout << "~MyTask()" << endl;}
    void process()
    {
        ::srand(::clock());
        int cnt = 10;
        while(cnt--)
        {
            int number = ::rand() % 10;
            cout << "sub thread " << pthread_self()
                << ": get a number = " << number << endl;
            ::sleep(1);
        }
    }
};

int main()
{
    cout << ">> main thread " << pthread_self() << endl;
    MyTask task;

    //如果是以指针的方式存储对象，要保证在执行process方法时,
    //该对象生命周期没有结束,如果结束,执行会出错
    //
    //所有要使用一个单独的来来监控,不能让对象生命周期在
    //结束
    
    unique_ptr<morey::Thread> mythread(new morey::Thread(std::bind(&MyTask::process, task)));
    mythread->start();
    mythread->join();
    std::cout << "Hello world" << std::endl;
    return 0;
}

