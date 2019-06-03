#include "tSingleton.h"
#include "testClass.h"


    Point p1(1, 3);
    Computer c1("hehe",8888);
void test()
{
    p1.prinT();
    c1.prinT();
    cout << "--------------------------------------" << endl;
    Computer * c2 = Singleton<Computer>::getInstance("momo", 6666);
    c2->prinT();
    Point *p2 = Singleton<Point>::getInstance(1, 2);
    p2->prinT();
}

int main(void)
{
    test();
    return 0;
}

