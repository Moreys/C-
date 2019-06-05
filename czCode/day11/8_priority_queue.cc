/*************************************************************************
  @FileName:  ./8_priority_queue.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 08:38:00 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <queue>
using namespace std;

void test1()
{
    priority_queue<int> p1;//默认是最大优先级队列
    //priority_queue<int, vector<int>, less<int>> p1;//跟上面相等；
    priority_queue<int, vector<int>, greater<int>> p2; //最小优先级队列

    p1.push(1);
    p1.push(5);
    p1.push(7);
    p1.push(4);
    p1.push(4);
    p1.push(5);
    p1.push(6);
    p1.push(8);
    cout << "size = " << p1.size() << endl;
    cout <<"top = " << p1.top() << endl;

    while(p1.size() > 0)
    {
        cout << p1.top() << endl;
        p1.pop();
    }
    cout << endl;
    cout << "测试最小优先队列" << endl;

    p2.push(1);
    p2.push(5);
    p2.push(7);
    p2.push(4);
    p2.push(4);
    p2.push(5);
    p2.push(6);
    p2.push(8);
    cout << "size = " << p2.size() << endl;
    cout <<"top = " << p2.top() << endl;
    while(p2.size() > 0)
    {
        cout << p2.top() << endl;
        p2.pop();
    }
    
    
}

int main()
{
    test1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

