#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1 = "this is a search test";
    string s2("search");

    //查找字串   返回迭代器
    auto it = search(s1.begin(),s1.end(), s2.begin(), s2.end());
    cout << *it << endl;

    for(; it != s1.end(); ++it)
    {
        cout << *it;
    }
    cout << endl;
    
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

