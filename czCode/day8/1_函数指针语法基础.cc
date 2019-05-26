#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
//数组指针 语法 梳理
//定义一个数组类型
//int a[10];
//
//定义一个指针数组类型
//
//定义一个指针  数组类型的指针  数组类的指针
//

int main01()
{
    int a[10];//a 代表的是数组首元素的地址， &a代表整个数组的地址 a + 1 4  &a+1 步长40

    {
        //定义一个数组类型
        //
        typedef int (myTypeArray)[10];//取一个别名
        myTypeArray myArray;// 相当于a 
        myArray[0] = 10;
        printf("%d \n", myArray[0]);
    }

    {
        //定义一个指向  数组类型的指针  指针类的指针
        int (*MyPointer)[10];//变量  告诉编译器给我分配内存
        MyPointer = &a;
        (*MyPointer)[0] = 40;
        printf("a[0]:%d \n", a[0]);
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

//函数指针语法梳理
//1 如何定义一个函数类型
//2 如何定义一个函数指针类型
//3 如何定义一个  函数指针  (指向一个函数的入口地址)
//

int add(int a, int b)
{
    cout << "func add " << endl;
    return a + b;
}
int main()
{
    add(1, 2); //直接调用  函数名就是函数的入口地址

    //定义一个函数类型
    //
    {
        typedef int(MyFuncType)(int a, int b);//定义了一个类型
        MyFuncType *myPointerFunc = NULL;//定义了一个指针，指向某一种函数 就是typedef那种
        
        myPointerFunc = & add;  //细节  把add的地址给myPointerFunc  就是给指针赋值
        myPointerFunc(3, 4); //间接调用 指针的间接赋值

        myPointerFunc = add;//细节  C过程，兼容历史版本的原因
        myPointerFunc(3 ,4);//间接调用
        
    }

    //定义一个函数指针类型
    {
        typedef  int(*MyPointerFuncType)(int a, int b); //int * a = NULL;
        MyPointerFuncType myPointerFunc;//定义了一个指针
        myPointerFunc = add; //让指针指向一个函数如否地址
        myPointerFunc(5, 6);
    }
    //函数指针
    {
        int (*MyPointerFunc)(int a, int b);//定义了一个变量
        MyPointerFunc = add;
        MyPointerFunc(7 ,8);
    }

}


