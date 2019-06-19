/*************************************************************************
  @FileName:  Noncopyable.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Wed 12 Jun 2019 11:03:40 PM CST
 ************************************************************************/
                                                                         
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

namespace morey
{

class Noncopyabele
{
protected:
    Noncopyabele(){}
    ~Noncopyabele(){}
    Noncopyabele(const Noncopyabele &) = delete;
    Noncopyabele & operator=(const Noncopyabele &) = delete;
};

}//end of namespace morey

#endif

