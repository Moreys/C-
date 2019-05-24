#include "rssRead.h"

#include "tinyxml2.h"
using  namespace tinyxml2;
using std::cout;
using std::endl;

RssRead::RssRead()
{
    cout << "rssRead()" << endl;
}
RssRead::~RssRead()
{
    cout << "~RssRead()" << endl;
}

//解析XML
void RssRead::parseRss()
{
    XMLDocument doc;
    struct RssItem  rssItem;
    if(doc.LoadFile("cool.xml") != 0)
    {
        cout << "load xml file failed" << endl;
        return ;
    }

    XMLElement * root = doc.RootElement();
    XMLElement * channel = root->FirstChildElement("channel");
    if(channel != NULL)
    {
    XMLElement * title = channel->FirstChildElement("title");
    rssItem.title = atoi(title->GetText());
    XMLElement * link = channel->FirstChildElement("link");
    rssItem.link = atoi(link->GetText());
    XMLElement * description = channel->FirstChildElement("description");
    rssItem.description = atoi(description->GetText());

    XMLElement * content = channel->FirstChildElement("content");
    rssItem.content = atoi(content->GetText());
    }
   _rss.push_back(rssItem);
}


void RssRead::dump(const string & filename)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << "isftream open fiel" << filename
            << "error" << endl;
        return;
    }
    
    for(vector<RssItem>::iterator it = _rss.begin()
        ; it != _rss.end(); ++ it)
    {
        cout << (*it).title << " "
            << (*it).link << " "
            << (*it).content << " "
            << (*it).description << endl;
    }
        
}
