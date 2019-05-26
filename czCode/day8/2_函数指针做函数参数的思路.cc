#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include <iostream>
using namespace std;
int myadd(int a, int b)
{
    cout <<"func add()" << endl;
    return a + b;
}

int myadd1(int a, int b)
{
    cout <<"func add()" << endl;
    return a + b;
}

int myadd2(int a, int b)
{
    cout <<"func add()" << endl;
    return a + b;
}
int myadd3(int a, int b)
{
    cout <<"func add()" << endl;
    return a + b;
}
typedef int (*MyTypeFuncAdd)(int a, int b);

int MainOp(MyTypeFuncAdd myFuncAdd)
{
    int c = myFuncAdd(5 ,6);
    return c;
}

//int (*MyPointerFuncAdd)(int a, int b)
int MainOp2(int (*MyPointerFuncAdd)(int a, int b))
{
    int c = MyPointerFuncAdd(5, 6);//间接调用
    return c;
}

//间接调用
//任务的调用  和任务的编写可以分开
//

int main()
{
    /*
    MyTypeFuncAdd myFuncAdd = NULL;
    myadd(1, 2);
    myFuncAdd = myadd;
    myFuncAdd(3 ,4);//间接调用 
    MainOp2(myadd);
    MainOp(myadd);
*/
    //在mainop框架  没有发生任何改变的情况下
    MainOp(myadd1);
    MainOp(myadd2);
    MainOp(myadd3);
    

    std::cout << "Hello world" << std::endl;
    return 0;
}

