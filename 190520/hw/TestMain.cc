#include "MyString.h"

using namespace morey;

//测试前面的默认初始化和两个等号重载 以及 [] 重载
void test1()
{
    MyString s1;
    MyString s2("s2");
    MyString s2_2 = NULL;
    MyString s3 = s2;
    MyString s4 = "s44444";
    cout << "s1.len = " << s1.length() << endl;
    s1.print();
    s2.print();
    s3.print();
    s4.print();
    cout << "测试重载的= 和重载的[]" << endl;
    s4 = s2;
    s4.print();
    s4 = "s222";
    s4.print();
    s4[1] = '4';
    cout << "s4[1] = " << s4[1] << endl;
    cout << "下面有问题吗？" << endl;
    s4.print();
    cout <<"s4 = " << s4 << endl; //err 不能直接打印
}

//测试+= 
void test2()
{
    MyString s2("s2");
    MyString s2_2 = NULL;
    MyString s3 = s2;
    MyString s4 = "s44444";
    s2.print();
    s2 += "hello";
    s2.print();
    s2 += s4;
    s2.print();
}

//测试== !=  < >
void test3()
{

    MyString s2("s2");
    MyString s2_2 = NULL;
    MyString s3 = s2;
    MyString s4 = "s44444";
    if(s3 == s4)
    {
        cout << "相等" << endl;
    }
    else
    {
        cout << "不相等" << endl;
    }
}

//测试== 
void test4()
{
    MyString s1;
    MyString s2("s2");
    MyString s3 = s2;

    if (s2 == "aa")
    {
        printf("相等");

    }
    else
    {
        printf("不相等");

    }

    if (s3 == s2)
    {
        printf("相等");

    }
    else
    {
        printf("不相等");

    }
}
//测试大于小于
void test5()
{
    MyString s1;
    MyString s2("s2");

    MyString s3 = s2;
    s3 = "aaa";

    int tag = (s3 < "bbbb");
    if (tag < 0 )
    {
        printf("s3 小于 bbbb");

    }
    else
    {
        printf("s3 大于 bbbb");

    }
    MyString s4 = "aaaaffff";
    cout<<s4<<endl;
}

int main()
{   
    // test1();
    //    test3();
    //test4();
    //test5();
    return 0;
}
