/*************************************************************************
  @FileName:  Query.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Fri 07 Jun 2019 08:55:12 PM CST
 ************************************************************************/

#ifndef __QUERY_H__
#define __QUERY_H__
#include "TextQuery.h"
#include "QueryResult.h"

class Query_base
{
    friend class Query;
protected:
    typedef TextQuery::line_no line_no;
    virtual ~Query_base(){}
private:
    virtual
    QueryResult eval(const TextQuery &) const = 0;
    virtual
    string rep() const = 0;
};

class Query
{
public:
    Query(const string &);
    QueryResult eval(const TextQuery &t)const
    {
        return _q->eval(t);
    }
    string rep() const{return _q->rep();}
    ~Query() {}

private:
    Query(shared_ptr<Query_base> query): _q(query) {}
    shared_ptr<Query_base> _q;
};


#endif

