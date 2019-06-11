/*************************************************************************
  @FileName:  test.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 02:20:55 PM CST
 ************************************************************************/

#include "TaskQueue.h"
#include "Threadpool.h"

#include <unistd.h>
#include <time.h>
#include <stdlib.h>


#include <memory>
#include <iostream>
using namespace std;
using namespace morey;

class MyTask
: public Task
{
public:
    void process()
    {
        ::srand(::time(NULL));
        int number = ::rand() % 100;
        cout << "pid = " << pthread_self()
            <<" number = " << number << endl;
        ::sleep(1);
    }
};

int main()
{
    Threadpool threadpool(4, 10);
    threadpool.start();
    unique_ptr<Task> task(new MyTask());
    int cnt = 20;
    while(cnt--)
    {
        threadpool.addTask(task.get());
        cout << "cnt = " << cnt << endl;
    }

    threadpool.stop();
    
    return 0;
}

