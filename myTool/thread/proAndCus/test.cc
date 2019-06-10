/*************************************************************************
  @FileName:  test.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 09 Jun 2019 02:20:55 PM CST
 ************************************************************************/

#include "TaskQueue.hpp"
#include "producer.hpp"
#include "customer.hpp"

using namespace morey;

int main()
{
    TaskQueue tasque(20);
    cout << ">> main thread" << pthread_self() << endl;
    unique_ptr<morey::Thread> mythreadp(new Producer(tasque));
    unique_ptr<morey::Thread> mythreadc(new Customer(tasque));
    
    mythreadp->start();
    mythreadc->start();



    mythreadp->join();
    mythreadc->join();
    std::cout << "Hello world" << std::endl;
    return 0;
}

