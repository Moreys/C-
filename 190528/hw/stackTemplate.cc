#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template <typename Type, int kSize = 10>
class Stack
{
public:
    Stack()
        : _top(-1)
      , _count(0)
          , _data(new Type[kSize])
    {

    }

    ~Stack()
    {
        if(_data)
        {
            delete [] _data;
            cout << "~Stack()" << endl;
        }
    }

public:
    bool empty() const;
    bool full() const;
    void push(const Type & t);
    void pop();
    Type top();
    int getCount()
    {
        return _count;
    }
private:
    int _top;
    int _count;
    Type * _data;

};

template <typename Type, int kSize>
bool Stack<Type, kSize>::empty() const
{
    return _top == -1;
}

template <typename Type, int kSize>
bool Stack<Type, kSize>::full() const
{
    return _top == kSize - 1;
}

template <typename Type, int kSize>
void Stack<Type, kSize>::push(const Type & t)
{
    if(full())
    {
        cout << "Stack is full " << endl;
        return;
    }
    else 
    {
        _data[++_top] = t;
        _count++;
    }
    
}

template <typename Type, int kSize>
void Stack<Type, kSize>::pop()
{
    if(empty())
    {
        cout << "Stack is empty " << endl;
        return;
    }
    else
    {
        --_top;
        _count--;
    }
}

template <typename Type, int kSize>
Type Stack<Type, kSize>::top()
{
    return _data[_top];
}

int test()
{
    Stack<int> stack;
    cout << "此时栈是否为空？" << stack.empty() << endl;
    stack.push(1);
    cout << "此时栈是否为空？" << stack.empty() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;
    for(int idx = 2; idx != 12; ++idx)
    {
        stack.push(idx);
    }
    cout << "此时栈是否已满？" << stack.full() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;

    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    cout << "此时栈是否为空？" << stack.empty() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;
    return 0;
}
int test1()
{
    Stack<string> stack;
    cout << "此时栈是否为空？" << stack.empty() << endl;
    stack.push("aaa");
    cout << "此时栈是否为空？" << stack.empty() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;
    for(int idx = 2; idx != 12; ++idx)
    {
        stack.push(string(3, 'a' + idx));
    }
    cout << "此时栈是否已满？" << stack.full() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;

    while(!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    cout << "此时栈是否为空？" << stack.empty() << endl;
    cout << "栈的元素个数为：" << stack.getCount() << endl;
    return 0;
}
int main()
{
    test();
    cout << "------------------------------------" << endl;
    test1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

