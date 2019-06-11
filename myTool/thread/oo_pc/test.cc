/*************************************************************************
  @FileName:  test.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 02:20:55 PM CST
 ************************************************************************/

#include "TaskQueue.h"
#include "Producer.h"
#include "Customer.h"

#include <memory>
#include <iostream>
using namespace morey;

int main()
{
    TaskQueue tasque;
    cout << ">> main thread" << pthread_self() << endl;
    unique_ptr<Thread> producer1(new Producer(tasque));
    unique_ptr<Thread> producer2(new Producer(tasque));
    unique_ptr<Thread> customer1(new Customer(tasque));
    unique_ptr<Thread> customer2(new Customer(tasque));
    
    producer1->start();
    producer2->start();
    customer1->start();
    customer2->start();
    
    producer1->join();
    producer2->join();
    customer1->join();
    customer2->join();

    std::cout << "Hello world" << std::endl;
    return 0;
}

