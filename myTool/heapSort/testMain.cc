/*************************************************************************
  @FileName:  testMain.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 07 Jun 2019 04:25:03 PM CST
 ************************************************************************/
#include "heapSort.h"                                                                         
#include <iostream>

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};
    int length = sizeof(arr) / sizeof(arr[0]);
    HeapSort<int,less<int>> heapSort(arr,length);
    heapSort.sort();
    heapSort.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

