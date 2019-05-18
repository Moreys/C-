
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>


#include <iostream>

using  namespace std;
using namespace log4cpp;//使用命名空间

int main(int argc,char **argv)
{
    PatternLayout *pLayout1 = new PatternLayout();
    pLayout1->setConversionPattern("%d: %p %c %x : %m%n");

    PatternLayout *pLayout2 = new PatternLayout();
    pLayout2->setConversionPattern("%d: %p %c %x : %m%n");

    PatternLayout *pLayout3 = new PatternLayout();
    pLayout3->setConversionPattern("%d: %p %c %x : %m%n");

    OstreamAppender *pOstreamAppender = new OstreamAppender("pOstreamAppender", &cout);
    pOstreamAppender->setLayout(pLayout1);

    //一直写数据
    FileAppender * pFileAppender = new FileAppender("pFileAppender","wangdao.log");
    pFileAppender->setLayout(pLayout2);

    //回卷数据
    RollingFileAppender *pRollingFileAppender = new RollingFileAppender(
                                                                        "pRollingFileAppender",
                                                                        "rollingFile.log",
                                                                        1024,
                                                                        10);
    pRollingFileAppender->setLayout(pLayout3);

    Category &myRecord = Category::getRoot().getInstance("mycategory");
    myRecord.setAppender(pOstreamAppender);
    myRecord.setAppender(pFileAppender);
    myRecord.setAppender(pRollingFileAppender);
    myRecord.setPriority(Priority::ERROR);//通过配置文件

    //只有当日志的优先级别大于等于日志记录器的优先级时，该条日志才会被记录
    for(int idx = 0; idx != 50; ++idx)
    {
        myRecord.emerg("this is an emerg memsage");//方法本身就是代表是就是一条日志的级别
        myRecord.info("system is running");
        myRecord.alert("this is an alert memsage");
        myRecord.notice("this is a notice memsage");
        myRecord.debug("this is an debug");
        myRecord.warn("system has a warning");
        myRecord.error("system has a error, can't find a file");
        myRecord.fatal("system has a fatal error ,must be shutdown");
        myRecord.info("system shutdown, you can find some information in system log");

    }
    Category::shutdown();
    std::cout << "Hello world" << std::endl;
    return 0;
}

