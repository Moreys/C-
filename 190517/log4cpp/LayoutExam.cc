
#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/PatternLayout.hh>


#include <iostream>

using  namespace std;
int main(int argc,char **argv)
{
    using namespace log4cpp;//使用命名空间
    //先创建一个Appender,然后对齐进行new绑定
    OstreamAppender *pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);

    //定义一个PatternLayout指针，并创建对象
    PatternLayout *pLayout = new PatternLayout();
    //添加等下需要打印的内容的类型
    pLayout->setConversionPattern("%d: %p %c %x : %m%n");
    //设置setLayout
    pOstreamAppender->setLayout(pLayout);
   
    Category &root = Category::getRoot();
    Category &infoCategory = root.getInstance("infoCategory");
    infoCategory.addAppender(pOstreamAppender);
    infoCategory.setPriority(Priority::INFO);

    infoCategory.info("system is running");
    infoCategory.warn("system has a warning");
    infoCategory.error("system has a error, can't find a file");
    infoCategory.fatal("system has a fatal error ,must be shutdown");
    infoCategory.info("system shutdown, you can find some information in system log");
    
    Category::shutdown();
    std::cout << "Hello world" << std::endl;
    return 0;
}

