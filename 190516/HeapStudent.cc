#include <string.h>
#include <stdlib.h>

#include <iostream>
using std::cout;
using std::endl;

//只能在堆上面开辟空间 
//将new和delete重载
//要将析构函数私有化
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
    void destroy()
    {
        delete  this;
    }
private:
    ~Student()
    {
        delete this;
    }
public:
    void * operator new(size_t sz)
    {
        cout << "void * operator new" << endl;
        void * ret = malloc(sz);
        return ret;
    }
    void  operator  delete(void * ret)
    {
        cout << "void operator delete" << endl;
        free(ret);
    }
private:
    char * _name;
    int _id;
};
int main()
{
    Student * pstu = new Student("make", 10);
    pstu->print();
    pstu->destroy();
    std::cout << "Hello world" << std::endl;
    return 0;
}

