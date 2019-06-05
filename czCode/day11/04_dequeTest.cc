/*************************************************************************
  @FileName:  ./04_dequeTest.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 05:34:31 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

template<typename T>
void printT(const T &t)
{
    typename T::const_iterator it = t.begin();
    while(it != t.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << "打印完毕" << endl;
}


void test1()
{
   deque<int> d1;
   d1.push_back(1);
   d1.push_back(3);
   d1.push_back(5);
   
   d1.push_front(-1);
   d1.push_front(-3);
   d1.push_front(-5);

   cout << endl;
   cout << "头部元素为：" << d1.front() << endl;
   cout << "尾部元素为：" << d1.back() << endl;

   d1.pop_back();
   d1.pop_front();
   printT(d1);

   deque<int>::iterator it = find(d1.begin(), d1.end(), -1);
   if(it != d1.end())
   {
       //distance 
       cout << "-3数组下标为:" << distance(d1.begin(), it) << endl;
   }
   else
   {
        cout << "没有找到" << endl;
   }

}

void test2()
{
    
}
int main()
{
    test1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

