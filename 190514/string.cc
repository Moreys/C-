#include <iostream>

using namespace std;

void test()
{
    char str[] = "hello world!";//字符数组 栈上
    const char * str1 = "hello world!"; // 字符串常量 文字常量区
    cout << str << endl;
    cout << str1 << endl;
}
void test1()
{
    int number(1);
    cout << "number:" << number << endl;
    
    string s1 = "hello ";//c风格字符串转成为C++风格字符串
    string s2("word");
    cout << s1 << s2 << endl;
    //把C++风格字符串转为C风格字符串
    const char *pstr = s1.c_str();
    const char * pstr2 = s1.data();
    cout << pstr << pstr2 << endl;
    
    //求字符串长度
    cout << "s2.size = " << s2.size() << endl;
    cout << "s2.length = " << s2.length() << endl;
    //字符串遍历
    for(int idx = 0; idx != s2.size(); ++idx)
    {
        cout << s2[idx] << endl;
    }


    //字符串拼接
    string s3 = s1 + s2;
    cout << s3 << endl;
    s3.append(",hehe");
    cout << s3 << endl;
    s3.append(3,'z');
    cout << s3 << endl;
    s3.append(s1);
    cout << s3 << endl;
    
    //截取字串
    size_t pos = s3.find('s');
    string s4 = s3.substr(pos,8);
    cout << s4 << endl;

}
int main()
{
    test();
    test1();
    return 0;
}

