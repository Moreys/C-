#include "MyString.h"

using namespace morey;

int main()
{
    MyString s1;
    MyString s2("s2");
    MyString s2_2 = NULL;
    MyString s3 = s2;
    MyString s4 = "s44444";

    s2.print();
    s3.print();
    s4.print();

    return 0;
}
