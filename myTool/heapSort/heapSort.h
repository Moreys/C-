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
    , _backIdx(size - 1)
    {}
    //下沉调整
    void heapAdjust();
    void print() const;
    //堆排序  默认升序
    void sort();
private:
    T *  _arr; //要排序的
    size_t _size;//要排序的大小
    size_t _backIdx; //堆的最后一个元素的下标位置
};

template<typename T, typename Compare>
void HeapSort<T, Compare>::heapAdjust()
{
   Compare cmp;
   size_t parent = 0;
   size_t child;
   while(child = 2 * parent + 1, child <= _backIdx)
   {
       if(child < _backIdx && cmp(_arr[child], _arr[child + 1]))
       {
           child++;
       }
       if(cmp(_arr[parent], _arr[child]))
       {
           swap(_arr[parent], _arr[child]);
       }
       parent = child;
   }
}

template<typename T, typename Compare>
void HeapSort<T, Compare>::sort()
{
    while(_backIdx)
    {
        heapAdjust();
        swap(_arr[0], _arr[_backIdx--]);
    }
}
template<typename T, typename Compare>
void HeapSort<T, Compare>::print() const
{
    for(size_t idx = 0; idx != _size; ++idx)
    {
        cout << _arr[idx] << " " ;
    }
    cout << endl;
}

#endif

