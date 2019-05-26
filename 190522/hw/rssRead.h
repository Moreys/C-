#ifndef __RSSREAD_H__
#define __RSSREAD_H__
#include <iostream>
#include <vector>
using std::string;
using std::vector;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};

class rssRead
{
public:
    rssRead();
    ~rssRead();
public:
    void parseRss();
    void dump(const string & filename);

private:
    vector<RssItem> _rss;

};
#endif

