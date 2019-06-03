/*************************************************************************
  @FileName:  ./myString.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 12:28:32 PM CST
 ************************************************************************/
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

class MyString
{
public:
    MyString(const char * pstr)
    : _pstr(new char[strlen(pstr) + 1]())
    {
        cout << "MyString(const char * pstr)" << endl;
        strcpy(_pstr, pstr);
    }

    //复制构造函数
    MyString(const MyString & rhs)
    : _pstr(new char[strlen(rhs._pstr) + 1]())
    {
        strcpy(_pstr, rhs._pstr);
        cout << "MyString(const MyString & rhs)" << endl;
    }

    //赋值运算符函数
    //释放旧空间，开辟新空间
    //将数据拷贝到新空间
    //返回地址
    MyString & operator=(const MyString & rhs)
    {
        cout << "MyString & operator=(const MyString & rhs)" << endl;
        if(NULL == rhs._pstr)
        {
            delete [] _pstr;
            _pstr = new char[strlen(rhs._pstr)]();
            strcpy(_pstr, rhs._pstr);
        }
        return *this;   
    }

    //移动构造函数  和移动赋值运算符函数    通常称为具有    移动语义的函数
    //复制构造函数  和赋值运算符函数    统称为具    有复制控制语义的函数
    //具有移动语义的函数    要优先于    具有复制控制语义的函数
#if 1
        //移动构造函数
        MyString(MyString && rhs)
        : _pstr(rhs._pstr)// 深拷贝 
        {
            cout << " MyString(MyString && rhs)" << endl;
            rhs._pstr = nullptr;
        }

        //移动赋值运算符函数
        MyString & operator=(MyString && rhs)
        {
            cout << "MyString & operator=(MyString && rhs)" << endl;
            if(this != & rhs) //两者不相等。
            {
                delete [] _pstr;
                _pstr = rhs._pstr;
                rhs._pstr = nullptr;
            }
            return *this;
        }
#endif
    ~MyString()
    {
        if(_pstr)
            delete [] _pstr;
        cout << "~MyString()" << endl;
    }
    friend std::ostream & operator<<(std::ostream & os, const MyString & rhs);
private:
    char * _pstr;
};

std::ostream & operator<<(std::ostream & os, const MyString & rhs)
{
    os << rhs._pstr;
    return  os;
}
int main1()
{
    vector<MyString> strs;
    strs.push_back("hello,world");
    cout << ".........." << endl;

    MyString str1 = "wangdao";
    cout << "str1 = " << str1 << endl;
    cout << endl;
    //strs.push_back(str1);只要放在容器中的元素都是一个全新的副本
    strs.push_back(std::move(str1));

    MyString str2 = "shengzhen";
    str2 = "hengang";
    cout << "str2 = " << str2 << endl;
    
    cout << endl << "test std::move" << endl;
    //std::move 显示将一个左值转换成一个右值，本质上就是一个强制转换
    //
    str2 = std::move(str1);//该语句之后，就不再使用str1对象了
    cout << "str2 = " << str2 << endl;
    str2 = std::move(str2);
    cout << "........." << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

MyString & getMyString0()
{

}
MyString s1("hello");//全局对象

MyString getMyString()
{
    //MyString str("hello");//局部对象
   // return str;//当返回的对象的局部对象时
            //如果定义了移动构造函数，return 时调用的是移动构造函数.
    return s1;  // 当返回的值是全局对象时,return 时调用的是复制构造函数
}
    
void test1()
{
    int a = 1;
    int b = 2;
    cout << "a = " << a << "b = " << b << endl;
    b = std::move(a);//对于内置类型数据,表现不明显

    cout << "a = " << a << "b = " << b << endl;
    getMyString();
}

int main()
{
    test1();
    return 0;
}
