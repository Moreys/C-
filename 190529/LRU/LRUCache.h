/*************************************************************************
  @FileName:  LRUCache.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 30 May 2019 08:09:36 PM CST
 ************************************************************************/
#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__
#include <iostream>
#include <deque>
#include <map>

using namespace std;

    template <typename Container>
void display(const Container & c)
{
    typename Container::const_iterator it = c.begin();
    for(; it != c.end(); ++it)
    {
        cout << it->first << "---->" 
            << it->second << endl;
    }
    cout << "map 打印完毕！！！" << endl;
}

class LRUCache
{
public:
    //初始化的时候设置缓存的上限.
    LRUCache(int capacity) : _capacity(capacity)
    {
        cout << "LRUCache()" << endl;
    }
    ~LRUCache()
    {
        cout << "~LRUCache()" << endl;
    }

    int get(int key);
    void put(int key, int value);
    void print();
private:
    int _key;
    int _value;
    int _capacity; //上限
    map<int, int> _lru;
    deque<int> _deque;
};


//打印map
void LRUCache::print()
{
    display(_lru);
}

//将缓存中数据取出  
//key:秘钥(使用的)
//返回知否成功
int LRUCache:: get(int key)
{
    map<int, int>::iterator it = _lru.find(key);
    if(it == _lru.end())
    {
        cout << "没有该元素" << "对元素进程插入" << endl;
        int number = _lru.size();
        if(number < _capacity)
        { 
            cout << "大于cap" << endl;
            _lru.insert(make_pair(key,1));
            _deque.push_front(key); 
            return -1;
        }
        else 
        {
            cout << "大于cap" << endl;
            int number = _deque.back();
            _lru.erase(number);
            _deque.pop_back();
            _lru.insert(make_pair(key, _value)); 
            _deque.push_front(key);
            return -1;
        }
    }
    else 
    {
        cout << "找到该元素" << endl;
        int number = _lru.size();
        if(number <  _capacity)
        {
            cout << "小于cap" << endl;
            _deque.pop_back();
            _lru.insert(make_pair(_key,0)); 
            return -1;
        }
        else 
        {
            cout << "大于cap" << endl;
            int number = _deque.back();
            _lru.erase(number);
            _deque.pop_back();
            _lru.insert(make_pair(_key, _value)); 
            _deque.push_front(key);
            return -1;
        }
    }
}

//将内容吸入到缓存
//key:秘钥  value:存储的值
//无返回
void LRUCache::put(int key, int value)
{

    this->_key = key;
    this->_value = value;
    //数据入map
    int it =  _lru.size(); 
    if(it <  _capacity )
    {
        cout << "put小于cap" << endl;
        _lru.insert(make_pair(_key, _value)); 
        _deque.push_front(key);
        return;
    }
    else
    {
        cout << "put大于cap" << endl;
        int number = _deque.back();
        _lru.erase(number);
        _deque.pop_back();
        _lru.insert(make_pair(_key, _value)); 
        _deque.push_front(key);
        return;
    }
}

#endif

