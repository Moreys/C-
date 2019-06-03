#include <iostream>
#include <vector>
#include <list>
#include <deque>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::deque;

template <typename Container>
void display(const Container & c) //遍历任何容器
{
    typename Container::const_iterator it = c.begin();
    while(it != c.end())
    {
        cout << *it << " ";
        it++;
    }
    cout << endl;
}

void test0()
{
    cout << endl << ">> Test vector..." << endl;
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //构造函数，将array的第一个元素到后面10个元素都初始化给numbers
    vector<int> numbers(array, array + 10);//左闭右开的区间
    cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
    cout << "numbers size = " << numbers.size() << endl
        << "numbers capacity = " << numbers.capacity() << endl;

    for(size_t idx = 0; idx != numbers.size(); ++idx)
    {
        cout << numbers[idx] << " ";
    }
    cout << endl;

    vector<int>::iterator it = numbers.begin();
    for(; it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    //添加元素
    cout << ">> 添加元素的操作：" << endl;
    numbers.insert(numbers.begin(), 11);//时间复杂度为O(n)
    display(numbers);
    //vector<int>::iterator it2 = numbers.begin();
    //添加N个元素
    auto it2 = numbers.begin();//auto自动推导猜测后面的类型是什么
    it2 += 2;//开始 头部 + 2 的位置
    numbers.insert(it2, 3, 12); //添加3个12进去
    display(numbers);
    
    //添加迭代器范围内的元素
    int arr[3] = {22, 23, 24};
    it2 = numbers.begin();//一旦发生扩容操作，迭代器有可能失效，需要重新获取位置。
    it2 += 2;
    numbers.insert(it2, arr, arr + 3);
    display(numbers);
    
    //清空容器的元素
    numbers.clear();//只清空，空间还在
    cout << "number size" << numbers.size() << endl
        << "number capacity = " << numbers.capacity() << endl;
    numbers.shrink_to_fit();//回收空间
    cout << "number size" << numbers.size() << endl
        << "number capacity = " << numbers.capacity() << endl;

    
}

void test1()
{
    cout << endl << ">> Test list。。。" << endl;
    list<int> numbers {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
    cout << "numbers size = " << numbers.size() << endl;
    
    //numbers[0]; err list不能使用小标访问。只支持双向访问迭代器
    //
    list<int>::iterator it = numbers.begin();
    for(; it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }        
    cout << endl;
    cout << ">> 添加元素的操作" << endl;
    numbers.insert(numbers.begin(), 11);  //时间复杂度为O(1)
    display(numbers);
    auto it2 = numbers.begin();
    ++it2; ++it2;
    numbers.insert(it2, 3, 12);
    display(numbers);

    int arr[3] = {22, 23, 24};
    numbers.insert(it2, arr, arr + 3);
    display(numbers);
    cout << "*it2 = " << *it2 << endl;
    numbers.clear();
    cout << "numbers size = " << numbers.size() << endl;
}
void testDeque()
{
    cout << endl << ">> Test deque..." << endl;
    //int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //构造函数，将array的第一个元素到后面10个元素都初始化给numbers
   // <int> numbers(array, array + 10);//左闭右开的区间
    deque<int> numbers{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "sizeof(numbers) = " << sizeof(numbers) << endl;
    cout << "numbers size = " << numbers.size() << endl;
        //<< "numbers capacity = " << numbers.capacity() << endl;//没有capacity
        //

    for(size_t idx = 0; idx != numbers.size(); ++idx)
    {
        cout << numbers[idx] << " "; //支持下标访问运算符，随机访问
    }
    cout << endl;

    deque<int>::iterator it = numbers.begin();
    for(; it != numbers.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    cout << "push_front" << endl;
    numbers.push_front(11);
    display(numbers);
    //添加元素
    cout << ">> 添加元素的操作：" << endl;
    numbers.insert(numbers.begin(), 11);//时间复杂度为O(n)
    display(numbers);
    //vector<int>::iterator it2 = numbers.begin();
    //添加N个元素
    auto it2 = numbers.begin();//auto自动推导猜测后面的类型是什么
    it2 += 2;//开始 头部 + 2 的位置
    numbers.insert(it2, 3, 12); //添加3个12进去
    display(numbers);
    
    //添加迭代器范围内的元素
    int arr[3] = {22, 23, 24};
    it2 = numbers.begin();//一旦发生扩容操作，迭代器有可能失效，需要重新获取位置。
    it2 += 2;
    numbers.insert(it2, arr, arr + 3);
    display(numbers);
    
    //清空容器的元素
    numbers.clear();//只清空，空间还在
    cout << "number size" << numbers.size() << endl;
      //  << "number capacity = " << numbers.capacity() << endl;
    numbers.shrink_to_fit();//回收空间
    cout << "number size" << numbers.size() << endl;
        //<< "number capacity = " << numbers.capacity() << endl;

    
}
int main()
{
    test0();
    test1();
    testDeque();
    std::cout << "Hello world" << std::endl;
    return 0;
}

