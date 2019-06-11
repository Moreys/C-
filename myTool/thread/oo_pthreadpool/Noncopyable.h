/*************************************************************************
  @FileName:  Noncopyable.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 04:54:30 PM CST
 ************************************************************************/
                                                                         
#pragma once

namespace morey
{

//保证拷贝构造函数和赋值运算符函数是不起作用的
class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}
    Noncopyable(const Noncopyable &) = delete;
    Noncopyable & operator=(const Noncopyable &) = delete;
};

}//end of namespace std
