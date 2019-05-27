#include <string.h>
#include <stdlib.h>

#include <iostream>

using std::cout;
using std::endl;

class Student
{
public:
    Student(const char * name, int id)
        : _name(new char[strlen(name) + 1]())
        , _id(id)
    {
        cout << "Student()" << endl;
        strcpy(_name, name);
    }
    void print() const
    {
        cout << "name:" << _name
            << endl << "id:" << _id << endl;
    }
    ~Student()
    {
        delete [] _name;
        cout << "~Student" << endl;
    }
    //只能生成栈对象，意味着new和delete都要私有
    //这样才不能在其他位置生成堆对象
private:
    void * operator new(size_t sz);
    void  operator  delete(void * ret);
private:
    char * _name;
    int _id;
};
int main()
{
    //Student * pstu = new Student("make", 10); //err无法编译
    Student stu("morey", 100);
    stu.print();
    std::cout << "Hello world" << std::endl;
    return 0;
}


