#include <iostream>
#include <list>
using std::cout;
using std::endl;
using std::list;

template <typename Container>
void display(const Container & c)
{
    for(auto & elem : c) //& 不可少，如果没有加 就会复制的
    {
        cout << elem << " ";
    }
    cout << endl;
}
void testList()
{
    list<int> number1{3, 6, 2, 4, 7, 6, 9, 7, 2, 1, 4, 5};
    list<int> number2{11, 22, 33};
    display(number1);
    display(number2);
    cout << "移动元素以后" << endl;
    auto it1 = number1.begin();
    ++it1;
    *it1 = 100;
    //number2.splice(number2.begin(), number1);
    //number2.splice(number2.begin(), number1, it1);
    //number2.splice(number2.begin(), number1, it1, number1.end());
    //display(number1);
    //display(number2);
    number1.reverse();
    display(number1);
    std::greater<int> gt;
    number1.sort(gt);
    display(number1);
    number1.unique();
    display(number1);
    


}
int main()
{
    testList();
    std::cout << "Hello world" << std::endl;
    return 0;
}

