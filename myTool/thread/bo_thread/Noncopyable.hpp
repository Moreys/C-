/*************************************************************************
  @FileName:  Noncopyable.hpp
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Sat 08 Jun 2019 04:18:52 PM CST
 ************************************************************************/
                                                                         
#pragma once

namespace morey
{

class Noncopyable
{
protected:
    Noncopyable() {}
    ~Noncopyable() {}
    Noncopyable(const Noncopyable &) = delete;
    Noncopyable & operator=(const Noncopyable &) = delete;
};

}//end of namespace morey

