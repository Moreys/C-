/*************************************************************************
  @FileName:  ./circleReference.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 10:24:35 PM CST
 ************************************************************************/
#include <iostream>
#include <memory>
using namespace std;

class Parent;
class Child
{
public:
    Child(){cout << "Child()" << endl;}
    ~Child(){cout << "~Child()" << endl;}
    shared_ptr<Parent> _pParent;
private:
};

class Parent
{
public:
    Parent(){cout << "Parent()" << endl;}
    ~Parent(){cout << "~Parent()" << endl;}
    shared_ptr<Child> _pChild;
};
int main()
{
    //shared_pter的循环引用会导致内存泄漏
    shared_ptr<Parent> pParent(new Parent());
    shared_ptr<Child> pChild(new Child());
    
    cout << "pParent's sue_count = " << pParent.use_count() << endl;
    cout << "pChild's sue_count = " << pChild.use_count() << endl;

    pParent->_pChild = pChild;
    pChild->_pParent = pParent;
    cout << "pParent's sue_count = " << pParent.use_count() << endl;
    cout << "pChild's sue_count = " << pChild.use_count() << endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

