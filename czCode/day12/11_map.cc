/*************************************************************************
  @FileName:  11_map.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 11 Jun 2019 10:53:30 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <map>
#include <string>
using namespace std;

//map元素的添加//遍历 删除基本操作
void test1()
{
    map<int, string> map1;

    //方法1
    map1.insert(pair<int, string>(1, "t1"));
    map1.insert(pair<int, string>(2, "t2"));

    //方法2
    map1.insert(make_pair(3, "t3"));
    map1.insert(make_pair(4, "t4"));

    //方法3
    map1.insert(map<int, string>::value_type(5, "t5"));
    map1.insert(map<int, string>::value_type(6, "t6"));

    //方法4
    map1[7] = "t7";
    map1[8] = "t8";

    //遍历容器
    for(map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << "编辑结束" << endl;

    //容器元素的删除
    while(!map1.empty())
    {
        map<int, string>::iterator it = map1.begin();
        cout << it->first << "\t" << it->second << endl;
        map1.erase(it);
    }
    
    //插入的四种方法异同
    //前三种，返回值为pair<iterator,bool> 若key已经存在 则报错
    //方法四-----》若key已经存在则修改，原因的被覆盖
}

void test2()
{
    map<int, string> map1;
    //返回值原型：typedef pair<iterator, bool> _Pairib;
    //
    //方法1
    pair<map<int, string>::iterator, bool> mypair1 = map1.insert(pair<int, string>(1, "t1"));
    map1.insert(pair<int, string>(2, "t2"));

    //方法2
    pair<map<int, string>::iterator, bool> mypair3 = map1.insert(make_pair(3, "t4"));
    map1.insert(make_pair(4, "t4"));

    //方法3
    pair<map<int, string>::iterator, bool> mypair5 = map1.insert(map<int, string>:: value_type(5, "t5"));
    if(mypair5.second != true)
    {
        cout << "key 5 插入失败" << endl;
    }
    else
    {
        cout << mypair5.first->first << "\t" << 
            mypair5.first->second << endl;
    }
    pair<map<int, string>::iterator, bool>
        mypair6 = map1.insert(map<int, string>::value_type(5, "t5"));
    if(mypair6.second != true)
    {
        cout << "key 6 插入失败" << endl;
    }
    else
    {
        cout << mypair6.first->first << "\t"
            << mypair6.first->second << endl;
    }

    map1[7] = "t7";
    map1[7] = "t8";

    for(map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << "编辑结束" << endl;


}

void test3()
{
    map<int, string> map1;

    //方法1
    map1.insert(pair<int, string>(1, "t1"));
    map1.insert(pair<int, string>(2, "t2"));

    //方法2
    map1.insert(make_pair(3, "t3"));
    map1.insert(make_pair(4, "t4"));

    //方法3
    map1.insert(map<int, string>::value_type(5, "t5"));
    map1.insert(map<int, string>::value_type(6, "t6"));

    //方法4
    map1[7] = "t7";
    map1[8] = "t8";

    //遍历容器
    for(map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
    {
        cout << it->first << "\t" << it->second << endl;
    }
    cout << "编辑结束" << endl;

    //map的查找，异常处理
    map<int, string>::iterator it2 = map1.find(100);
    if(it2 == map1.end())
    {
        cout << "100 not is number" << endl;
    }
    else 
    {
        cout << it2->first << "\t" << it2->second << endl;
    }

    //queal_range 异常处理
    //pair里面进行承接的要和map1相同
    pair<map<int, string>::iterator, map<int, string> ::iterator> mypair
         = map1.equal_range(5);//返回两个迭代器，形成一个pari

    if(mypair.first == map1.end())
    {
        cout << "第一个迭代器 5 的位置不存在" << endl;
    }
    else
    {
        cout << mypair.first->first << "\t" << mypair.first->second << endl;
    }

    if(mypair.second == map1.end())
    {
        cout << "第一个迭代器 5 的位置不存在" << endl;
    }
    else
    {
        cout << mypair.second->first << "\t" << mypair.second->second << endl;
    }
}

int main()
{
    test3();
    std::cout << "Hello world" << std::endl;
    return 0;
}

