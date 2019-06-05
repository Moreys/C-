/*************************************************************************
  @FileName:  ./2_stringTest.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 11:54:11 AM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//string 的初始化
void test1()
{
    string str1 = "aaaaa";
    string str2("bbbbb");
    string str3 = str2;//通过拷贝构造函数  来初始化对象str3
    string str4(10, 'a');

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

}

//string的遍历
void test2()
{
    string str1 = "abcdefghijl";
    
    //1 数组的方式
    for(int idx = 0; idx < str1.length(); ++idx)
    {
        cout << str1[idx] << " ";
    }
    cout << endl;

    //2 迭代器
    for(string::iterator it = str1.begin(); it != str1.end(); ++it)
    {
        cout << *it << " " ;
    }

    // () 和 [] 的区别
    try
    {
        for(int idx = 0; idx < str1.length() + 3; ++idx)
        {
            cout << str1.at(idx) << " ";   // 抛出异常
        }
    }
    catch(...)
    {
        cout << "发生异常" << endl;
    }
    cout << "at 之后" << endl;
    //try
    //{
    //    for(int idx = 0; idx < str1.length() + 3; ++idx)
    //    {
    //        cout << str1[idx] << " ";   // 出现错误不会向外面抛出异常
    //    }
    //}
    //catch(...)
    //{
    //    cout << "发生异常" << endl;
    //}

}

//字符指针和string的转换
void test3()
{
    string str1 = "aaaabbb";
}

//字符串的连接
void test4()
{
    string s1 = "aaa";
    string s2 = "bbb";
    s1 = s1 + s2;
    cout << "s1: " << s1 << endl;

    string s3 = "3333";
    string s4 = "4444";
    s3.append(s4);
    cout << "s3: " << s3 << endl;
}

int main()
{
    //test1();
    //test2();
    test4();
    std::cout << "Hello world" << std::endl;
    return 0;
}

