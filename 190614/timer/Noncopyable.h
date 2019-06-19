/*************************************************************************
  @FileName:  Noncopyable.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      2019年06月14日 星期五 16时19分19秒
 ************************************************************************/
                                                                         
#ifndef __NONCOPYABLE_H__
#define __NONCOPYABLE_H__

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

#endif

