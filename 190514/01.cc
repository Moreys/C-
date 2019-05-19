#define _CTR_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <iostream>

using namespace std;

class Test
{
public:
    Test()
    {
        a = 10;//作用完成对象的初始化工作
        p = new char(100);
        strcpy(p,"aaaaaffff");
        cout << "我的构造函数 为被执行了" << endl;
    }
    void print()
    {
        cout << a << endl;
        cout << p << endl;
    }
    ~Test()
    {
        if(p != NULL)
        {
            delete(p);
        }
        cout << "我的析构函数 我被调用了" << endl;
    }
private:
    int a;
    char *p;
};

//给对象搭建一个舞台,研究对象的行为
void objplay()
{
    //先创建对象后释放
    Test t1;
    t1.print();
    cout << "分割符" << endl; //
    Test t2;
    t2.print();
}

int main()
{
    objplay();
    std::cout << "Hello world" << std::endl;
    return 0;
}

