/*************************************************************************
  @FileName:  QueryResult.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 06 Jun 2019 11:46:29 AM CST
 ************************************************************************/
                                                                         
#ifndef __QUERYRESULT_H__
#define __QUERYRESULT_H__
#include "TextQuery.h"

#define make_plural(num, str1, str2)\
         (num == 1 ? str1 : ((string)str1 + (string)str2));


class QueryResult
{
friend std::ostream & print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, 
                shared_ptr<set<size_t>> p,
                shared_ptr<vector<string>> f)
    :_sought(s), _lines(p), _file(f){}
private:
    string _sought;
    shared_ptr<set<size_t>> _lines; // 保存出现的行号
    shared_ptr<vector<string>> _file;//输入的文件
};
std::ostream & print(std::ostream&, const QueryResult&);

#endif


