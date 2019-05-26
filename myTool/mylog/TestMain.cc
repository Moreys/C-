#include "Mylog.h"
using namespace morey;
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;

void test1()
{
    LogError("error message");
    LogWarn("warn message");
    LogDebug("debug message");
    LogInfo("info message");
}
int main()
{
    test1();
    morey::Mylogger::destroy();
    // printf("Message");
    return 0;
}

