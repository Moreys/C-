/*************************************************************************
  @FileName:  ./testMain.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 30 May 2019 08:50:24 PM CST
 ************************************************************************/
#include "LRUCache.h"

int main()
{
    LRUCache ache(2);
    ache.put(1, 1);
    ache.put(2, 2);
    cout << ache.get(1) << endl;
    ache.put(3, 3);
    cout << ache.get(2) << endl;
    ache.put(4, 4);
    cout << ache.get(1) << endl;
    cout << ache.get(3) << endl;
    cout << ache.get(4) << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

