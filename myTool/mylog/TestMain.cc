#include "Mylog.h"
using namespace morey;
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

void test1()
{
    int number = 1;
    const char * p = "hello world";

    LogError("error message, %d, %s",number, p);
    LogWarn("warn message");
    LogDebug("debug message");
    LogInfo("info message");
}
int main()
{
    test1();
    morey::Mylogger::destroy();
    return 0;
}

