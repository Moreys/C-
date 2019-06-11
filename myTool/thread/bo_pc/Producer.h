/*************************************************************************
  @FileName:  Producer.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:24:41 PM CST
 ************************************************************************/
                                                                         
#pragma once

namespace morey
{

//类前项声明(不完全类型),可以减少头文件的依赖
class TaskQueue;

class Producer
{
public:
    void create(TaskQueue & taskque);
};

}//endl of namespace morey
