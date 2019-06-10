/*************************************************************************
  @FileName:  testThread.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 05:17:09 PM CST
 ************************************************************************/
                                                                         

#include "Thread.hpp"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <memory>

using namespace std;


//用于问题展示，存在子类在继承的时候有拷贝构造函数
//和赋值函数的问题
class Mythread : public morey::Thread
{
public:
    ~Mythread(){cout << "~MyTask()" << endl;}
private:
    void run()override
    {
        ::srand(::clock());
        int cnt = 10;
        while(cnt--)
        {
            int number = ::rand() % 100;
            cout << "sub thread " << pthread_self()
                << ": get a number = " << number << endl;
            ::sleep(1);
        }
    }
};

int main()
{
   // Mythread thread1;
    //Mythread thread2(thread1); //不希望这样的事情发生
    //利用继承规则让Thread继承一个没有赋值构造函数和拷贝构造函数的爷爷类，
    //这样一路继承下来就没有赋值构造函数和拷贝构造函数了

    cout << ">> main thread" << pthread_self() << endl;
    unique_ptr<morey::Thread> mythread(new Mythread());
    mythread->start();
    mythread->join();
    std::cout << "Hello world" << std::endl;
    return 0;
}

