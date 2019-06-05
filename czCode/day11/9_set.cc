/*************************************************************************
  @FileName:  ./9_set.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 08:49:44 PM CST
 ************************************************************************/
                                                                         
#include <string.h>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

//集合  有序     唯一   默认从小到大 底层实现红黑树
void test1()
{
    set<int> set1;
    for(int i = 0; i < 5; ++i)
    {
        int tmp = rand();
        set1.insert(tmp);
    }

    set1.insert(100);
    set1.insert(100);
    set1.insert(100);

    //打印
    for(set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //删除集合
    while(!set1.empty())
    {
        set<int>::iterator it = set1.begin();
        cout << *it << endl;
        set1.erase(set1.begin());
    }
}


//更改集合的排序方式
void test2()
{
    set<int, greater<int>> set1;
    for(int i = 0; i < 5; ++i)
    {
        int tmp = rand();
        set1.insert(tmp);
    }

    set1.insert(100);
    set1.insert(100);
    set1.insert(100);

    //打印
    for(set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //删除集合
    while(!set1.empty())
    {
        set<int>::iterator it = set1.begin();
        cout << *it << endl;
        set1.erase(set1.begin());
    }
}

//对于存储自定义的类型要自己定义排序
//仿函数    函数对象    重载（）操作 进行比较大小
//学生包含学号，姓名属性，现在要求 任意插入一个学生对象到set容器中 
//使得容器
class Student
{
public:
    Student(char *name, int age)
    {
        strcpy(this->_name, name);
        this->_age = age;
    }
    char _name[64];
    int _age;
};


//函数对象
struct StuFunctor
{
    bool operator()(const Student & left, const Student & right)
    {
        if(left._age < right._age)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
};

void test3()
{
    set<Student, StuFunctor> set1;
    Student s1("张1", 31);
    Student s2("张2", 22);
    Student s3("张3", 44);
    Student s4("张4", 11);
    Student s5("张5", 31);
    set1.insert(s1);
    set1.insert(s2);
    set1.insert(s3);
    set1.insert(s4);
    set1.insert(s5);
    for(set<Student, StuFunctor>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        cout << it->_age << it->_name << endl;
    }

}

//typedef pair<iterator, bool> _Pairib;
void test4()
{
    Student s1("s1", 31);
    Student s2("s2", 31);
    Student s3("s3", 31);
    Student s4("s4", 31);
    Student s5("s5", 31);
    set<Student, StuFunctor> set1;
    pair<set<Student, StuFunctor>::iterator, bool> pair1 = set1.insert(s1);
    if(pair1.second == true)
    {
        cout << "插入s1成功" << endl;
    }
    else 
    {
        cout << "插入失败" << endl;
    }
    set1.insert(s2);

    //如何知道插入的结果
    pair<set<Student, StuFunctor>::iterator, bool > pair5 = set1.insert(s5);
    if(pair5.second == true)
    {
        cout << "插入成功" << endl;
    }
    else
    {
        cout << "插入失败" << endl;
    }

    //遍历
    for(set<Student, StuFunctor>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        cout << it->_age << endl << it->_name << endl;
    }
}


//find查找， equal_range
//返回结果是一个pair
void test5()
{
    set<int> set1;
    for(int i = 0; i < 10; ++i)
    {
        set1.insert(i + 1);
    }
    for(set<int>::iterator it = set1.begin(); it != set1.end(); ++it)
    {
        cout << *it << " " ;
    }
    cout << endl;
    auto it0 = set1.find(5);
    cout << "it0 = " << *it0 << endl;

    int num1 = set1.count(5);
    cout << "num1 = " << num1 << endl;

    auto it1 = set1.lower_bound(5); //大于等于5的元素的迭代器位置
    cout << "it1 = " << *it1 << endl;

    auto it2 = set1.lower_bound(5);
    cout << "it2 = " << *it2 << endl;


    //把5元素删除
    set1.erase(5); //删除以后返回下一个位置的元素
    auto mypair = set1.equal_range(5); //
    auto it3 = mypair.first;
    cout << "it3 = " << *it3 << endl;

    auto it4 = mypair.second;
    cout << "it4 = " << *it4 << endl;
}
int main()
{
    test5();
    std::cout << "Hello world" << std::endl;
    return 0;
}

