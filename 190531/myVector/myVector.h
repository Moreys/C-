/*************************************************************************
  @FileName:  myVector.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 11:49:10 PM CST
 ************************************************************************/
#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__
#include <iostream>
#include <memory>
using namespace std;

template<typename T>
class MyVector
{
public:
    typedef T value_type;
    typedef T * pointer;
    typedef T * iterator;
    typedef const T * const_iterator;

    MyVector()
    : _start(nullptr)
    , _finish(nullptr)
    , _end_of_storage(nullptr)
    {}
public:
    size_t size()const
    {return _finish - _start;}

    size_t capacity() const
    {return _end_of_storage - _start;}

    void push_back(const T & t);
    void pop_back();

    const_iterator begin() const
    {return _start;}

    const_iterator end() const
    {return _finish;}

    T & operator[](size_t idx) const
    {return _start[idx];}

private:
    void reallocate();
private:
    static allocator<T> _alloc;
    T * _start;
    T * _finish;
    T * _end_of_storage;
};
template<typename T>
allocator<T> MyVector<T>::_alloc;

template<typename T>
void MyVector<T>::push_back(const T & t)
{
    if(size() == capacity())
    {
        reallocate();
    }
    _alloc.construct(_finish++, t);
}

template<typename T>
void MyVector<T>::pop_back()
{
    if(size() > 0)
    {
        _alloc.destroy(--_finish);
    }
}

template<typename T>
void MyVector<T>::reallocate()
{
    size_t oldSpace = capacity();
    size_t newSpace = 2 * oldSpace > 0 ? 2 * oldSpace : 1;
    T * ptmp = _alloc.allocate(newSpace);//开辟未知类型的新空间
    if(_start)
    {
        uninitialized_copy(_start, _finish, ptmp);
        while(_finish != _start)
        {
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, oldSpace);
    }
    _start = ptmp;
    _finish = _start + oldSpace;
    _end_of_storage = _start + newSpace;
}

template<typename Container>
void display(const Container & c)
{
    typename Container::const_iterator it = c.begin();
    while(it != c.end())
    {
        cout << *it << " " ;
        ++it;
    }
    cout << endl;
    cout << "c' size = " << c.size() << endl
        << "c' capacity = " << c.capacity() << endl;
}
#endif
