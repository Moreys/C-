/*************************************************************************
  @FileName:  heapSort.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 31 May 2019 10:06:47 PM CST
 ************************************************************************/
#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__
#include <iostream>
#include <algorithm>


using namespace std;

template <typename T, typename Compare = std::less<T>>
class HeapSort
{
public:
    HeapSort(T * arr, int size)
    : _arr(arr)
    , _size(size)
    {}
    //下沉调整
    void heapAdjust(T & arr, T  parentIndex, int size);
    //堆排序  默认升序
    void sort(T & arr);

private:
    T *  _arr;
    int _size;

};

template<typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust(T & arr, T parentIndex, int size)
{

}

template<typename T, typename Compare>
void HeapSort<T, Compare>::sort(T & arr)
{

}

#endif

