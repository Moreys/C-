#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;//动态数组

int arr[10];

void printCapacity(vector<int> & vec)
{
    //size()当前元素的个数
    cout << "vec's size() = " << vec.size() << endl;
    //capacity()当前数组能够容纳元素的个数
    cout << "vec's capacity() = " << vec.capacity() << endl;
}
int main()
{
    //动态数组的实现原理
    //当size() == capacity() 并且还需要继续往其中添加新元素的时候必须要扩容
    //1、申请2 * capacity() 的空间
    //2、再把原来的所有元素复制到新空间中
    //3、销毁原来的空间的所有元素，并回收原来的空间
    //4、再新的空间的结尾添加元素
    //
    //尽管可以动态扩容，但是扩容的开销是很大的
    vector<int> numbers;
    numbers.reserve(30); //预先开辟空间
    std::cout << "Hello world" << std::endl;
    return 0;
}

