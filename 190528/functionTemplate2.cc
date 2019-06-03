#include <iostream>
using std::cout;
using std::endl;

template <typename T1, typename T2>
T2 multiply(T1 t1, T2 t2)
{
    return t1 * t2;
}
//模板的参数列表而言
//1/类型参数
//2、非类型参数，常量表达式，整型数据
template <typename T1, int NUMBER = 10>
T1 multiply(T1 t1)
{
    return t1 * NUMBER;
}

int main()
{
    int x1 = 1;
    double x2 = 2.22;
    cout << "multiply(x1, x2)" << multiply(x1, x2) << endl;

    cout << "multiply(x2)" << multiply(x2) << endl;
    cout << "multiply(x2)" << multiply<double, 100>(x2) << endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

