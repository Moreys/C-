/*************************************************************************
  @FileName:  TextQuery.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 06 Jun 2019 09:14:15 PM CST
 ************************************************************************/
                                                                         
#include "QueryResult.h"
#include "TextQuery.h"

#include <cstddef>
#include <sstream>
#include <cctype>
#include <cstring>
#include <utility>

using namespace std;

typedef map<string, shared_ptr<set<TextQuery::line_no>>> wmType;

typedef wmType::const_iterator wmIter;

typedef shared_ptr<set<TextQuery::line_no>>lineType;

typedef set<TextQuery::line_no>::const_iterator lineIter;


//读取文本并建立单词到行号的映射
//is:文件名字
TextQuery::TextQuery(ifstream &is) 
                    : _file(new vector<string>)
{
    string text;
    while(getline(is, text))
    {
        _file->push_back(text);
        int n = _file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word)
        {
            auto &lines = _wm[word];
            if(!lines)
            {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}


//查询函数
//sought：要查找的单词
QueryResult TextQuery::query(const string &sought) const
{
    static lineType nodata(new set<line_no>);
    wmIter loc = _wm.find(sought);
    if(loc == _wm.end())
    {
        return QueryResult(sought, nodata, _file);
    }
    else 
    {
        return QueryResult(sought, loc->second, _file);
    }
}


//打印输出查询的结果
//os:输出的位置;qr:输出文件来源
ostream &print(ostream & os, const QueryResult & qr)
{
    os << qr._sought << " occurs " << qr._lines->size() 
        << make_plural(qr._lines->size(), "time", "s");
    cout << endl;
    for(lineIter num = qr._lines->begin(); num != qr._lines->end(); ++num)
    {
        os << "\t(line " << *num + 1 << ")"
            << *(qr._file->begin() + *num) << endl;
    }
    return os;
}


//打印map里面是所有内容
void TextQuery::dispaly_map()
{
    wmIter iter = _wm.begin(), iter_end = _wm.end();
    for(; iter != iter_end; ++iter)
    {
        cout << "word:" << iter->first << "{";
        lineType text_locs = iter->second;
        lineIter loc_iter = text_locs->begin(),
                            loc_iter_end = text_locs->end();
        while(loc_iter != loc_iter_end)
        {
            cout << *loc_iter;
            if(++loc_iter != loc_iter_end)
                cout << ";";
        }
        cout << "}\n";
    }        
    cout << endl;
}




