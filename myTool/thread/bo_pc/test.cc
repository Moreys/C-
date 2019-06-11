/*************************************************************************
  @FileName:  test.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:44:37 PM CST
 ************************************************************************/
                                                                         
#include "Thread.h"
#include "TaskQueue.h"
#include "Producer.h"
#include "Consumer.h"


#include <iostream>
#include <memory>
using namespace morey;
using namespace std;


int main()
{
    TaskQueue taskque;
    
    unique_ptr<Thread> producer1(new Thread(bind(&Producer::create, Producer(), ref(taskque))));
    unique_ptr<Thread> producer2(new Thread(bind(&Producer::create, Producer(), ref(taskque))));
    unique_ptr<Thread> consumer1(new Thread(bind(&Consumer::get, Consumer(), ref(taskque))));
    unique_ptr<Thread> consumer2(new Thread(bind(&Consumer::get, Consumer(), ref(taskque))));

    producer1->start();
    producer2->start();
    consumer1->start();
    consumer2->start();

    producer1->join();
    producer2->join();
    consumer1->join();
    consumer2->join();

    std::cout << "Hello world" << std::endl;
    return 0;
}

