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
    typedef  size_t line_no;
    typedef set<line_no>::const_iterator line_it;
    QueryResult(string s, 
                shared_ptr<set<size_t>> p,
                shared_ptr<vector<string>> f)
    :_sought(s), _lines(p), _file(f){}
    set<line_no>::size_type size() const {return _lines->size();}
    line_it begin() const {return _lines->begin();}
    line_it end() const {return _lines->end();}
    shared_ptr<vector<string>> get_file() {return _file;}
private:
    string _sought;
    shared_ptr<set<size_t>> _lines; // 保存出现的行号
    shared_ptr<vector<string>> _file;//输入的文件
};
std::ostream & print(std::ostream&, const QueryResult&);

#endif


