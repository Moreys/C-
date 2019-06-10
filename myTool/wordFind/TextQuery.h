/*************************************************************************
  @FileName:  TextQuery.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 06 Jun 2019 11:44:08 AM CST
 ************************************************************************/

#ifndef __TEXTQUERY_H__
#define __TEXTQUERY_H__
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <memory>
using namespace std;

class QueryResult;

//TestQuery只负责查询，查询结果的展示交给QueryResult
class TextQuery
{
public:
    typedef vector<string>::size_type line_no;
    TextQuery(ifstream &); //传递要处理的文件
    QueryResult query(const string &) const;
    void dispaly_map();
private:
    shared_ptr<vector<string>> _file;
    map<string, shared_ptr<set<size_t>>> _wm;
};

#endif

