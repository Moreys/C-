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
int main()
{   
    test1();
    return 0;
}
