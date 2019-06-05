/*************************************************************************
  @FileName:  ./7_list.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 08:25:07 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <list>
using namespace std;

void test1()
{
    list<int> li;
    cout << "li的大小为" << li.size() << endl;
    for(int i = 0; i < 10; ++i)
    {
        li.push_back(i); //尾部插入  尾插法
    }
    cout << "li的大小为" << li.size() << endl;
    list<int>::iterator it = li.begin();
    while(it != li.end())
    {
        cout << *it << " " ;
        it++;
    }
    cout << endl;
    //1 2 3 4 5 6
    //list 不能提供下标随机访问  
    //只能++
    it = li.begin();
    it++;
    it++;
    it++;
    li.insert(it, 100); //插在什么地方 ？？？
    //链表的节点index 序号是从0号位置开始的
    // 在3号位置插入元素，让原来的三号位置变成4号位置 依次往后变化
    list<int>::iterator it1 = li.begin();
    while(it1 != li.end())
    {
        cout << *it1 << " " ;
        it1++;
    }
}

//删除
void test2()
{
    list<int> li;
    cout << "li的大小为" << li.size() << endl;
    for(int i = 0; i < 10; ++i)
    {
        li.push_back(i); //尾部插入  尾插法
    }
    cout << "li的大小为" << li.size() << endl;
    list<int>::iterator it1 = li.begin();
    list<int>::iterator it2 = li.begin();
    it2++;
    it2++;
    it2++;
    li.erase(it1, it2);
    for(list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << endl;
    

    li.insert(li.begin(), 100);
    li.insert(li.begin(), 100);
    li.insert(li.begin(), 100);
    for(list<int>::iterator it = li.begin(); it != li.end(); ++it)
    {
        cout << *it << endl;
    }
    cout << endl;

    //1 2 3 4 5 6
    //list 不能提供下标随机访问  
    //只能++
    //li.insert(it, 100); //插在什么地方 ？？？
    //链表的节点index 序号是从0号位置开始的
    // 在3号位置插入元素，让原来的三号位置变成4号位置 依次往后变化
    //list<int>::iterator it1 = li.begin();
    //while(it1 != li.end())
    //{
    //    cout << *it1 << " " ;
    //    it1++;
    //}
}
int main()
{
    //test1();
    test2();
    std::cout << "Hello world" << std::endl;
    return 0;
}

