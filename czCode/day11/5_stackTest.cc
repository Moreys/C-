/*************************************************************************
  @FileName:  ./5_stackTest.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 05 Jun 2019 08:13:58 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

    template<typename T>
void printT(const T &t)
{
    typename T::const_iterator it = t.begin();
    while(it != t.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << "打印完毕" << endl;
}

void test()
{
    stack<int> st; 
    for(int i = 0; i < 10; ++i)
    {
        st.push(i + 1);
    }
    cout << "st = " << st.size() << endl;
    //    printT(st);

    while(!st.empty())
    {
        int tmp = st.top();//获取栈顶元素
        cout << tmp << endl;
        st.pop();//弹栈
    }
    cout << "st = " << st.size() << endl;
}

class Teacher
{
public:
    int     age;
    char    name[32];
public:
    void printT()
    {
        cout << "age:" << age << endl;
    }
};

void test1()
{
    Teacher t1, t2, t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 34;
    stack<Teacher> st;
    st.push(t1);
    st.push(t2);
    st.push(t3);

    while(!st.empty())
    {
        Teacher tmp = st.top();//获取栈顶元素
        tmp.printT();
        st.pop();//弹栈
    }
}


void test2()
{
    Teacher t1, t2, t3;
    t1.age = 31;
    t2.age = 32;
    t3.age = 34;
    stack<Teacher*> st;
    
    st.push(&t1);
    st.push(&t2);
    st.push(&t3);

    while(!st.empty())
    {
        Teacher *ptmp = st.top();//获取栈顶元素
        ptmp->printT();
        st.pop();//弹栈
    }
}
int main()
{
    //test();
    //test1();
    test2();
    std::cout << "Hello world" << std::endl;
    return 0;
}

