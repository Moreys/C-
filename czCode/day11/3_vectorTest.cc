/*************************************************************************
  @FileName:  ./vectorTest.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 03:23:46 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <vector>

using namespace std;

//打印vector
void printT(vector<int> &v)
{
    vector<int>::iterator it = v.begin();
    for(; it != v.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "打印完毕" << endl;
}

void test1()
{
    vector<int> v1;
    cout << "v1.size = " << v1.size() << endl;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    cout << "v1.size = " << v1.size() << endl;
    cout << "v1.front = " << v1.front() << endl;

    //修改头部和尾部元素
    //函数返回值当左值 应该返回一个引用 
    v1.front() = 11;
    v1.back() = 55;

    while(v1.size() > 0)
    {
        cout << "尾部元素: " << v1.back() << endl; //获取尾部元素
        v1.pop_back(); //删除尾部元素
    }
}

//常用的初始化方式
void test2()
{
    vector<int> v1;
    cout << "v1.size = " << v1.size() << endl;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(5);

    vector<int> v2 = v1;  //赋值构造函数
    
    //使用迭代器进行初始化
    vector<int> v3(v1.begin(), v1.begin() + 2);
    printT(v3);
    printT(v2);
    printT(v1);
}

//vector遍历 通过数组的形式
void test3()
{
    vector<int> v1(10);// 要提前不内存准备好，
    for(int idx = 0; idx < 10; ++idx)
    {
        v1[idx] = idx + 1;
    }
    printT(v1);
}

//push_back()强化记忆
void test4()
{
    vector<int> v1(10); //分配10个元素的位置，默认都设置为0，
    v1.push_back(1000); //是在容器的后面进程插入
    v1.push_back(2000);

    cout << "v1.size = " << v1.size() << endl;
    printT(v1);
}

// 1 迭代器 end()的理解
// 1  2  5
// 
//
void test5()
{
    vector<int> v1(10);
    for(int i = 0; i != 10; ++i)
    {
        v1[i] = i + 1;
    }

    //正向遍历
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;
    //逆向遍历
    for(vector<int>::reverse_iterator it = v1.rbegin(); it != v1.rend(); ++it)
    {
        cout << *it << " " ;
    }
}

//vector元素删除
void test6()
{
    vector<int> v1(10);
    for(int i = 0; i != 10; ++i)
    {
        v1[i] = i + 1;
    }

    //区间删除
    v1.erase(v1.begin(), v1.begin() + 3);
    printT(v1);


    //根据元素的位置 进制指定删除
    v1.erase(v1.begin());//删除头部位置
    printT(v1);

    //根据元素的值
    v1[3] = 2;
    v1[1] = 2;
    printT(v1);
    
    vector<int>::iterator it = v1.begin();
    for(;it != v1.end();)
    {
        if(*it == 2)
        {
            it = v1.erase(it); // 当删除迭代器指向的元素的时候，erase删除函数会让it自动下移动
        }
        else
        {
           it++;
        }
    }
    printT(v1);
    cout << endl;
    v1.insert(v1.begin(), 100);
    v1.insert(v1.end(), 200);
    printT(v1);
    
}


int main()
{
    //test1();
    //test2();
    //test3();
    //test4();
    //test5();
    test6();
    std::cout << "Hello world" << std::endl;
    return 0;
}

