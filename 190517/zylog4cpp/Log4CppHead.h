#ifndef __LOG4CPPHEAD_H__
#define __LOG4CPPHEAD_H__
#include <log4cpp/Appender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>

#include <iostream>

using namespace std;
using namespace log4cpp;

namespace wdCadd
{

class  Mylogger
{
public:
    static Mylogger * getInstance()
    {
        if(_pInstance == nullptr)
        {
            _pInstance = new Mylogger();
        }
        return _pInstance;
    }
    static void destroy()
    {
        if(_pInstance)
        {
            delete _pInstance;
            Category::shutdown();
        }
    }
    Category & categoryInit()
    {
        PatternLayout *pLayout1 = new PatternLayout();
        pLayout1->setConversionPattern("%d: %p %c %x : %m%n");

        PatternLayout *pLayout2 = new PatternLayout();
        pLayout2->setConversionPattern("%d: %p %c %x : %m%n");

        OstreamAppender *pOstreamAppender = new OstreamAppender("pOstreamAppender", &cout);
        pOstreamAppender->setLayout(pLayout1);

        FileAppender * pFileAppender = new FileAppender("pFileAppender","Mylogger.log");
        pFileAppender->setLayout(pLayout2);

        Category &myRecord = Category::getRoot().getInstance("mycategory");
        myRecord.setAppender(pOstreamAppender);
        myRecord.setAppender(pFileAppender);
        return myRecord;
    }
    void logWern(const char * msg);
    void logError(const char * msg);
    void logDebug(const char * msg);
    void logInfo(const char * msg);
private:
    Mylogger()
    {
        cout << "hello" << endl;
    }

    ~Mylogger()
    {
        Category::shutdown();
        cout << "~Mylogger()" << endl;
    }

private:
    static Mylogger * _pInstance;

};

void Mylogger::logWern(const char * msg)
{
    Category &wern = categoryInit();
    wern.warn(msg);
}
void Mylogger::logInfo(const char * msg)
{
    Category &myInfo = categoryInit();
    myInfo.info(msg);
}
void Mylogger::logDebug(const char * msg)
{
    Category &myDebug = categoryInit();
    myDebug.debug(msg);
}
void Mylogger::logError(const char *msg)
{
    Category &myError = categoryInit();
    myError.error(msg);
}
Mylogger *Mylogger::_pInstance = nullptr;
}

#endif
