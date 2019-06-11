/*************************************************************************
  @FileName:  Consumer.h
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 10 Jun 2019 09:40:09 PM CST
 ************************************************************************/
                                                                         
#pragma once

namespace morey
{

class TaskQueue;
class Consumer
{
public:
    void get(TaskQueue & taskque);
};

}//end of namespace morey
