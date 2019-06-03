#include "rssRead.h"
#include <iostream>

int main()
{
    RssRead rss;
    rss.parseRss();
    rss.dump("my.xml");
    std::cout << "Hello world" << std::endl;
    return 0;
}

