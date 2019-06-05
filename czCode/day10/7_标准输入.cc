/*************************************************************************
  @FileName:  ./7_标准输入.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 04 Jun 2019 10:51:36 PM CST
 ************************************************************************/
                                                                         
#include <string.h>
#include <iostream>
using namespace std;

//cin.get()  一次只读去一个字符
//cin.get()  一个参数，读取一个字符
//cin.get() 三个参数，可读字符串
//cin.getline() 可读取空格
//cin.ignore() 
//cin.peek()
//cin.putback()
//


int main1()
{
    char mybuf[1024];
    int myInt;
    long myLong;
    cin >> myInt;
    cin >> myLong;
    cin >> mybuf;  //遇见空格停止接收数据
    cout << "myInt = " << myInt << "myLong = "
        << myLong << "mybuf = " << mybuf << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

int main2()
{
    char a, b, c;
    cout << "cin.get(a)如果缓冲区没有数据，则程序阻塞" << endl;  
    cin.get(a);
    cin.get(b);
    cin.get(c);
    cout << a << b << c << "cin.get(a)如果缓冲区没有数据，则程序阻塞" << endl;  
    cin.get(a).get(b).get(c);
    cout << a << b << c << endl;
    return 0;
}


//getline函数可以接收空格
int main3()
{
    char buf1[256];
    char buf2[256];

    cout << "请输入一个字符串，含有多个空格 aa  bb cc dd ee" << endl;
    
    cin >> buf1;
    cin.getline(buf2, 256);
    cout << "buf1 = " << buf1 << "buf2 = " << buf2 << endl;
    return 0;
}

int  main4()
{
    char buf1[256];
    char buf2[256];

    cout << "请输入一个字符串，含有多个空格 aa  bb cc dd ee" << endl;
    
    cin >> buf1;
    cin.ignore(20);
    int myint = cin.peek();
    cout << "myint:" << myint << endl;
    cin.getline(buf2, 256);

    cout << "buf1 = " << buf1 << "buf2 = " << buf2 << endl;
    
    return 0; 
}

//输入的字符串和数字分开处理
int main()
{
    cout << "Please, enter a number or a word:" << endl;
    char c = std::cin.get();
    if((c >= '0') && (c <= '9'))
        //输入的是整数和字符串  分开处理
    {
        int n;  //整数不可能中间有空格
        cin.putback(c); 
        cin >> n;
        cout << "You entered a number:" << n << endl;
    }
    else 
    {
        string str;
        cin.putback(c);
        getline(cin, str);//字符串
        cout << "You entered a word:" << str << endl;
    }
}
