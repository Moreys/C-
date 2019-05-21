#include "cowString.h"
#include <iostream>

int main()
{
    CowString s0;
    cout << "s0 = " << s0 << endl;

    CowString s1("hello world");
    CowString s2(s1);

    CowString s3("shenzhen");
    s3[0] = 'S';

    s3 = s2;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl << ">>>> 执行s1[0] = 'x' 之后：" << endl;
    s1[0] = 'x';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());

    cout << endl << ">>>> 执行cout << s2[0] << endl 之后：" << endl;
    cout << "s2[0] = " << s2[0] << endl;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    
    cout << "s1's refcount() = " << s1.refcount() << endl;
    cout << "s2's refcount() = " << s2.refcount() << endl;
    cout << "s3's refcount() = " << s3.refcount() << endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

