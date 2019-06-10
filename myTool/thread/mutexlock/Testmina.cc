#include "MutexLock.h"
#include "Condition.h"

#include <iostream>
using std::cout;
using std::endl;

int gTicket = 100;
bool flag = true;

morey::MutexLock mutex;//系统资源 不进行复制
morey::Condition condition(mutex);

void * threadFunc1(void * arg)
{
    //flag为true时，执行减1的操作
    int cnt = 20;
    while(cnt--)
    {
        morey::MutexLockGuard autolock(mutex);//防止四所
        if(false == flag)
        {
            condition.wait();
        }
        --gTicket;
        cout << "sub thread " << pthread_self() << ":"
            << " gTicket = " << gTicket << endl;
        if(flag)
        {
            flag = false;
        }
    }
    return NULL;
}
void * threadFunc2(void * arg)
{
    int cnt = 20;
    while(cnt--)
    {
        {
            morey::MutexLockGuard autolock(mutex);//防止死锁
            if(true == flag)
            {
                condition.wait();
            }
            --gTicket;
            cout << "sub thread " << pthread_self() << ":"
                << "gTicket = " << gTicket << endl;
            if(flag == false)
            {
                flag = true;
            }
        }//可以通过语句块来减小加锁的范围，
        //从而控制资源的区域

        condition.notify();

    }
    return NULL;
}
int main()
{
    pthread_t pthid1, pthid2;
    pthread_create(&pthid1, NULL, threadFunc1, NULL);
    pthread_create(&pthid2, NULL, threadFunc2, NULL);

    pthread_join(pthid1, NULL);
    pthread_join(pthid2, NULL);


    std::cout << "Hello world" << std::endl;
    return 0;
}

