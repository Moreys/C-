#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;


int main()
{

    vector<int> numbers;
    istream_iterator<int> isi(cin); //开始读取数据
    //begin()/end() 是用来读取容器的元素的
    //不能用来做添加元素的操作
    //
   // copy(isi, istream_iterator<int>(), numbers.begin());
   //isi++  时，读取下一个元素的
   //
   //back_inserter 返回的是一个插入迭代器，std::back_insert_iterator
   //在赋值时调用相应的容器的push_back方法
   //
    
    copy(numbers.begin(),numbers.end(),back_inserter(numbers));
    
    copy(numbers.begin(), numbers.end(),ostream_iterator<int>(cout, " "));
         cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

