#ifndef __PERSON_H__
#define __PERSON_H__
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Person
{
public:
    Person(string name, int age);
    ~Person();

public:
    void  display();
private:
    string _name;
    int _age;
};

class Employee : public Person
{

public:
    Employee(string, int , string, double);
    ~Employee();
    
public:

    void display();    

private:
    string _department;
    double _slary;

};
#endif

