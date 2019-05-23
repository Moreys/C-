#include "person.h"

int main()
{
    Employee e1("momo1", 29, "kaifa", 8666);
    Employee e2("momo2", 19, "kaifa", 6666);
    Employee e3("momo3", 39, "kaifa",66666);
    e1.Employee::display();
    e2.Employee::display();
    e3.Employee::display();
    return 0;
}

