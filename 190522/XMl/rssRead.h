#ifndef __RSSREAD_H__
#define __RSSREAD_H__
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct RssItem
{
    string title;
    string link;
    string description;
    string content;
};

class RssRead
{
public:
    RssRead();
    ~RssRead();
public:
    void parseRss();
    void dump(const string & filename);
    void readXML(const string & fileName);

private:
    vector<RssItem> _rss;
    

};
#endif

