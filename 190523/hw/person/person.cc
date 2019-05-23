#include "person.h"
Person::Person(string name, int age)
      : _name(name)
      , _age(age)
{
    cout << "Person()" << endl;
}
Person::~Person()
{
    cout << "~Person()" << endl;
}
void  Person::display()
{
    cout << "name = " << _name << endl
        << "age = " << _age << endl;
}

Employee::Employee(string name, int age, string department, double salary)
    : Person(name, age)
    , _department(department)
    , _slary(salary)
{
    cout << "Employee()" << endl;
}

Employee::~Employee()
{
    cout << "~Employee()" << endl;
}

void Employee::display()
{
        Person::display();
       cout << "department = " << _department << endl
        << "salary = " << _slary << endl;
}
