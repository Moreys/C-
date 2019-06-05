/*************************************************************************
  @FileName:  ./testMain.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 04 Jun 2019 08:35:14 PM CST
 ************************************************************************/

#include "myVector.h"

int main()
{
    MyVector<int> numbers;
    display(numbers);
    for(int idx = 0; idx != 10; ++idx)
    {
        numbers.push_back(idx);
        display(numbers);
    }
    cout << "numbers[6] = " << numbers[6] << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

