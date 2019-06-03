/*************************************************************************
  @FileName:  ./2_函数末班当类型强化.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sun 02 Jun 2019 04:41:14 PM CST
 ************************************************************************/
#include <string.h>
#include <iostream>


using namespace std;

//函数模板的本质:类型的参数化
//对字符数组排序

template<typename T, typename T2>
int mySort(T * array, T2 size)
{
    T2 i, j;
    T temp;
    if(NULL == array)
    {
        return -1;
    }
    for(i = 0; i < size; ++i)
    {
        for(j = i + 1; j < size; ++j)
        {
            if(array[i] < array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return 0;
}


template<typename T, typename T2>
int myPrint(T * array, T2 size)
{
    T2 i = 0;
    for(i = 0; i < size; ++i)
    {
        cout << array[i] << " " << endl;
    }
    return 0;
}
int main()
{
    int array[] = {1, 2, 5, 7, 10, 301, 49};
    int size = sizeof(array) / sizeof(*array);
    mySort(array, size);
    myPrint(array, size);

    char str[] = "dklfajrweruosdjfalfasd";
    int size1 = strlen(str);
    mySort(str, size1);
    myPrint(str, size1);



    std::cout << "Hello world" << std::endl;
    return 0;
}

