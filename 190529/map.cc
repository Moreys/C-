#include <iostream>
#include <map>
#include <string>
using std::endl;
using std::cout;
using std::map;
using std::string;
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
    //map默认情况下采用升序方式进行排列
    //不能存放关键字相同的元素
    // 
    //
    // 底层实现是红黑树
    //
    map<string, string> cities
    {
        pair<string, string>("010", "北京"),
            make_pair("021", "上海"),
            make_pair("0755", "深圳"),
            make_pair("0571", "杭州"),
            make_pair("027", "武汉"),
            make_pair("027", "上海"),
    };
    display(cities);
    auto ret = cities.insert(make_pair("021", "天津"));
    if(ret.second)
    {
        cout << "元素添加成功" << endl;
        cout << ret.first->first << "----->" 
            << ret.first->second << endl;
    }
    else 
    {
        cout << "元素添加失败" << endl;
        cout << ret.first->first << "--->" 
            << ret.first->second << endl;
    }
    display(cities);
    cout << endl;


    //下标访问
    //1、当元素存在时，通过key直接拿到相应的value
    //2、当元素不存在的时候，会通过key添加一个元素，但对象的value的是默认值
    //3、当元素存在时，还可以通过它直接修改value的值
    
    cout << cities["021"] << endl;
    cout << cities["023"] << endl;
    cout << endl;
    display(cities);
    cities["023"] = "重庆";  //时间复杂度为O(logN) 红黑树的查询操作，找到以后进行修改
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

