/*************************************************************************
  @FileName:  ./mem_fn.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 08:48:05 AM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Number
{
public:
    Number(int data) : _data(data)
    {}
    void display()
    {
        cout << "data: " << _data << " " << endl;
    }
    bool isEven() const
    {
        return !(_data % 2);
    }
    bool isPrime() const 
    {
        if(1 == _data)
        {
            return false;
        }
        for(int idx = 2; idx <= _data / 2; ++idx)
        {
            if(! _data % idx)
            {
            return false;
            }
        }
        return true;
    }
private:
    int _data;
};


int main()
{
    vector<Number> numbers;
    for(int idx = 1; idx != 21; ++idx)
    {
        numbers.push_back(Number(idx));
    }
    for_each(numbers.begin(), numbers.end(), mem_fn(&Number::display)); //相当于注册函数，把函数名传递进去就能执行函数

    using namespace placeholders;
    for_each(numbers.begin(), numbers.end(), bind(&Number::display, _1)); //需要一个占位符
    cout << endl;

    numbers.erase(remove_if(numbers.begin(), numbers.end()
                        , mem_fn(&Number::isPrime)),numbers.end());
    for_each(numbers.begin(), numbers.end(), mem_fn(&Number::display));
    std::cout << "Hello world" << std::endl;
    return 0;
}

