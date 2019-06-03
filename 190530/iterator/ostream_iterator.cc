/*************************************************************************
  @FileName:  ostream_iterator.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 31 May 2019 08:28:33 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6};
    //ostream_iterator 内部要重载相应的运算符，模拟出
    //一个迭代器功能来 ------—》适配器模式
    ostream_iterator<int> osi(cout, ",");
    copy(numbers.begin(), numbers.end(), osi);
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

