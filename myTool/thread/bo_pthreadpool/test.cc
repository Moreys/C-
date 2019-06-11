/*************************************************************************
  @FileName:  test.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:44:37 PM CST
 ************************************************************************/
                                                                         
#include "TaskQueue.h"
#include "Threadpool.h"

#include <unistd.h>
#include <time.h>

#include <iostream>
#include <memory>
using namespace morey;
using namespace std;

class Mytask
{
public:
    void process()
    {
        ::srand(::time(NULL));
        int number = ::rand() % 100;
        cout << "pid = " << pthread_self()
            << " number = " << number << endl;
        ::sleep(1);
    }
};

int main()
{
    Threadpool threadpool(4, 10);
    threadpool.start();
    for(int idx = 0; idx != 20; ++idx)
    {
        cout << "idx = " << idx <<endl;
        threadpool.addTask(std::bind(&Mytask::process, Mytask()));
    }
    threadpool.stop();
    return 0;
}

