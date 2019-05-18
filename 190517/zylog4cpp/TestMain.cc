#include "Log4CppHead.h"

using namespace wdCadd;

int main()
{
    cout << "hello,world" << endl;
    // printf("Message");
    Mylogger * log  = Mylogger::getInstance();
    log->logWern("wern");
    log->logInfo("info");
    log->logDebug("debug");
    log->logError("error");
    return 0;
}

