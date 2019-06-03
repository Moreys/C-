#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

void test0()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8, 9};
    numbers[0] = numbers[3] = numbers[4] = 66;
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove算法的实现
    //1、 
   auto it = remove(numbers.begin(), numbers.end(), 66);
    numbers.erase(remove(numbers.begin(), numbers.end(), 66),numbers.end());
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    std::cout << "Hello world" << std::endl;
}

//一般情况下，在遍历容器的过程中，不要做删除和添加元素的操作
//放置迭代器失效的问题。
void test1()
{
    
    vector<int> numbers;
    numbers.push_back(1);
    
    bool flag = true;
    for(auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        //数据位置前面的没有确定，中间有很多无效数据
        //
       // cout << "nuimbers capacity = " << numbers.capacity() << endl;
        cout << *it << " " ;
        if(flag)
        {
            numbers.push_back(2); //当扩容操作执行完毕之后，原来的迭代器已经失效。

            flag = false; //必须重新获取迭代器。才能正常运行 
        }
    }
    numbers[0] = numbers[3] = numbers[4] = 66;
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    //remove算法的实现
    //1、 
   auto it = remove(numbers.begin(), numbers.end(), 66);
    numbers.erase(remove(numbers.begin(), numbers.end(), 66),numbers.end());
    copy(numbers.begin(), numbers.end(), ostream_iterator<int>(cout, " "));
    std::cout << "Hello world" << std::endl;

}

int main()
{
    return 0;
}

