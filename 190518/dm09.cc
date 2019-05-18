#include <iostream>

using namespace std;
// 引用的基本概念
//
// 属于C++编译器对c的扩展，不能用c语言的语法去思考它
//
int main92()
{
    int a = 10;
    //引用的语法 type & name = var;
    int &b = a;
    b = 100;//相当于把a修改成了100
    cout << b << endl;
    cout << a << endl;
    
    a = 200;
    cout << b << endl;
    cout << a << endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

//基础类型的引用

void myswap(int a, int b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}
void myswap02(int *a, int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
}

//04 引用做函数参数声明时不进行初始化
void myswap03(int &a, int &b)
{
    int c = 0;
    c = a;
    a = b;
    b = c;
}
int  main93()
{
    int x, y;
    x = 10;
    y = 20;
    myswap(x, y);
    cout << x << y << endl;
    myswap02(&x, &y);
    cout << x << y << endl;

    //a就是x的别名  b就是y的别名
    myswap03(x, y);
    cout << x << y << endl;
}
struct Teacher
{
    char anme[64];
    int age;
};
void printfT(Teacher *pT)
{
    cout << pT -> age << endl;
}
    
//pT是t1的是两个不同的变量
void printfT2(Teacher &pT)
{
    pT.age = 33; //只会修改pT变量,不会修改t1变量j
}
void printfT3(Teacher &pT)
{
    cout << pT.age << endl;
    pT.age = 45; //只会修改pT变量,不会修改t1变量j
}

int  main()
{
    Teacher t1;
    t1.age = 35;
    printfT(&t1);

    printfT2(t1);//pT是t1的别名
    cout << "t1.age:" << t1.age << endl;

    printfT3(t1);//pT是形参 t1  copy 一份数据给 pT  pT = t1
    cout << "t1.age:" << t1.age << endl;
}
