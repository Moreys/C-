#include <iostream>
#include <string>
#include <map>

using namespace std;

template <typename Container>
void display(const Container & c)
{
    typename Container::const_iterator it = c.begin();
    for(; it != c.end(); ++it)
    {
        cout << it->first << "----->" << it->second << endl;
    }
}

void test0()
{
    //multimap默认情况下采用升序方式进行排列
    //能存放关键字相同的元素
    // 
    //
    // 底层实现是红黑树
    //
   multimap<string, string> cities
    {
        pair<string, string>("010", "北京"),
            make_pair("021", "上海"),
            make_pair("0755", "深圳"),
            make_pair("0571", "杭州"),
            make_pair("027", "武汉"),
            make_pair("027", "上海"),
    };
    display(cities);
    auto iret = cities.insert(make_pair("021", "天津"));
    cout << iret ->first << "---->" << iret->second << endl; 
    display(cities);
    cout << endl;

    
    cout << endl;
    display(cities);
    cout << endl;
    display(cities);
    cout << endl;


    //查找元素
    auto it = cities.find("021");//时间复杂度为O(logN)  树的二分查找
    if(it != cities.end())
    {
        cout << "查找成功" << endl;
        cout << it->first << "---->" << it->second << endl;
    }
    else
    {
        cout << "查找元素失败" << endl;
    }
}

int main()
{
    test0();
    std::cout << "Hello world" << std::endl;
    return 0;
}

