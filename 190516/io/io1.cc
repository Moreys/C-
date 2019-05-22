
#include <iostream>
#include <string>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void printCinSataus()
{
    cout << "cin's badbit = " << cin.bad() << endl
        << "cin's failbit = " << cin.fail() << endl
        << "cin's sofbit = " << cin.eof() << endl
        << "cin's goodbit  = " << cin.good() << endl;
}

void test0()
{
    int number = -1;
    printCinSataus();

    while(cin >> number, !cin.eof())
    {
        cout << "number = " << number << endl;
        printCinSataus();
        if(!cin.good())
        {
            cin.clear();//重置流的状态
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//清空缓冲区操作
            printCinSataus();
        }
    }
    cin.clear();
    cin.ignore(1024, '\n');

    cout << "imput string" << endl;
    string str;
    cin >> str;

    cout << "str = " << str << endl;


}

int main()
{
    test0();
    return 0;
}

