#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void display(int number)
{
    ++number;
    cout << number << " ";
}

int main()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6};
    for_each(numbers.begin(),numbers.end(),display);
    cout << endl;
    cout << "&number[0] = " << &numbers[0] << endl;
    //lambada表达式，====>匿名函数
    for_each(numbers.begin(), numbers.end(), [](int number){
            cout << number << " ";
             });

    cout << endl;

    // [] 表示捕获山下文的对象  ，
    // = 以值传递方式进行捕获
    // & 以引用形式进行捕获
    // 在异步编程中使用的很广泛。
    auto f1 = [=](){
        cout << "lambda exci " << endl;
        cout << "number[0] = " << numbers[0] << endl;
        cout << "&number[0] = " << &numbers[0] << endl;
    };
    f1();

    std::cout << "Hello world" << std::endl;
    return 0;
}

