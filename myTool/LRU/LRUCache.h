/*************************************************************************
  @FileName:  LRUCache.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 30 May 2019 08:09:36 PM CST
 ************************************************************************/
#ifndef __LRUCACHE_H__
#define __LRUCACHE_H__
#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

//最近最少使用淘汰机制
class LRUCache
{
public:
    //初始化的时候设置缓存的上限.
    LRUCache(int capacity) : _capacity(capacity)
    { cout << "LRUCache()" << endl;      }

    ~LRUCache()
    {    cout << "~LRUCache()" << endl;  }

    int get(int key);
    void put(int key, int value);
public:
    struct CacheNode
    {
        int key;
        int value;
        CacheNode(int k, int v) : key(k), value(v){}
    };
private:
    size_t _capacity; //上限
    list<CacheNode> _cacheList;
    unordered_map<int, list<CacheNode>::iterator> _hashMap;
};


//将缓存中数据取出  
//key:秘钥(使用的)
//存在返回key;没有返回-1
int LRUCache:: get(int key)
{
    auto it = _hashMap.find(key);
    if(it == _hashMap.end())//没有找到
    {   
        return -1; //没有找到，所有要直接返回
    }
    else 
    {
        //找到了，将数据重新插入到链表尾部
        int value = it->second->value;
        _cacheList.splice(_cacheList.begin(), _cacheList, it->second);
        _hashMap[key] = _cacheList.begin();
        return value;
    }
}

//将内容添加到缓存中
//key:秘钥;value:存储的值
//无返回
void LRUCache::put(int key, int value)
{
    auto it = _hashMap.find(key);
    if(it == _hashMap.end())
    {
        if(_cacheList.size() == _capacity)
        {
            int key = _cacheList.back().key;
            _hashMap.erase(key);
            _cacheList.pop_back();
        }
        _cacheList.push_front(CacheNode(key, value));
        _hashMap.insert(make_pair(key, _cacheList.begin()));
            
    }
    else 
    {
        it->second->value = value;
        _cacheList.splice(_cacheList.begin(), _cacheList, it->second);
        _hashMap[key] = _cacheList.begin();
    }
}

#endif

