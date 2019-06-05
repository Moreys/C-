/*************************************************************************
  @FileName:  1_stlprimer.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 11:29:56 AM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void test1()
{
    vector<int> v1; // 1 容器  把你的元素copy到容器中去
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    // 1  2  3  4
    // ｜  
    // 2 迭代器：相当于一个指针   分类
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++ it)
    {
        cout << *it << endl;
    }

    // 3/算法  算法和迭代器   进行无缝的连接
    int  num1 = count(v1.begin(), v1.end(), 3);
    cout << "num1 = " << num1 << endl;
    v1.push_back(3);
    cout << "再插入一个3以后" << endl;
    num1 = count(v1.begin(), v1.end(), 3);
    cout << "num1 = " << num1 << endl;
}

class Teacher
{
public:
    int _age;
    string _name;
public:
    void printT()
    {
        cout << "age = " << _age << endl;
    }
};

void test2()
{
    Teacher t1, t2, t3;
    t1._age = 31;
    t2._age = 32;
    t3._age = 33;
    vector<Teacher> v1; // 1 容器  把你的元素copy到容器中去
    v1.push_back(t1);  //  容器实现了数据类型和 算法的有效分离
    v1.push_back(t2);
    v1.push_back(t3);

    // 1  2  3  4
    // ｜  
    // 2 迭代器：相当于一个指针   分类
    for(vector<Teacher>::iterator it = v1.begin(); it != v1.end(); ++ it)
    {
        cout << it->_age << endl;
    }

    // 3/算法  算法和迭代器   进行无缝的连接
   // int  num1 = count(v1.begin(), v1.end(), 3);
   // 如何 求容器中老师 年龄为33 的节点的  个数
   // cout << "num1 = " << num1 << endl;
    //v1.push_back(3);
}

void test3()
{
    Teacher t1, t2, t3;
    t1._age = 31;
    t2._age = 32;
    t3._age = 33;
    Teacher * p1, *p2, *p3;
    p1 = &t1;
    p2 = &t2;
    p3 = &t3;   //指向的是t1对象的首地址

    vector<Teacher*> v1; // 1 把 t1 t2 t3 的内存首地址  放入到了容器当中
    v1.push_back(p1);  //  
    v1.push_back(p2);
    v1.push_back(p3);

    // 1  2  3  4
    // ｜  
    // 2 迭代器：相当于一个指针   分类
    for(vector<Teacher*>::iterator it = v1.begin(); it != v1.end(); ++ it)
    {
        cout << (*it)->_age << endl; //迭代器相当于指针，vector里面放的也是指针
                                    //所以现在的it想当与一个二级指针，先解引用，成为一级指针再进行数据的访问
    }

    // 3/算法  算法和迭代器   进行无缝的连接
   // int  num1 = count(v1.begin(), v1.end(), 3);
   // 如何 求容器中老师 年龄为33 的节点的  个数
   // cout << "num1 = " << num1 << endl;
    //v1.push_back(3);
}
int main()
{
    //test1();
    //test2();
    test3();
    std::cout << "Hello world" << std::endl;
    return 0;
}

