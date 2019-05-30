/*************************************************************************
  @FileName:  ./testMain.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 30 May 2019 08:50:24 PM CST
 ************************************************************************/
#include "LRUCache.h"

int main()
{
    LRUCache ache(5);
    ache.put(1, 2);
    ache.put(2, 4);
    ache.put(5, 6);
    ache.put(4, 4);
    ache.get(3);
    ache.put(9, 4);
    ache.put(8, 4);
    ache.put(3, 4);
    ache.get(2);
    ache.put(7, 4);
    ache.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}

