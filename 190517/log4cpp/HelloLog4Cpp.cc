#include <log4cpp/Category.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/Priority.hh>


#include <iostream>

using  namespace std;
/*
 * log4cpp 进行步骤
 *  1、创建一个Appende，并指定其包含的Layout；
 *  2、从系统中得到Category的根，将Appender添加到 Category中；
 *  3、设置Category的优先级
 *  4、记录日记
 *  5、关闭Category
 * */
int main()
{
    using namespace log4cpp;//使用命名空间
    Category & root = Category::getRoot(); //创建一个getroot对象
    

    log4cpp::OstreamAppender *pOstreamAppender = new OstreamAppender("OstreamAppender", &cout);
    //创建一个OstreamApp0ender 对象
    pOstreamAppender->setLayout(new BasicLayout()); //设置setLayout
    
    root.setAppender(pOstreamAppender);
    root.setPriority(Priority::DEBUG);

    root.debug("this is debug message");

    Category::shutdown();
    std::cout << "Hello world" << std::endl;
    return 0;
}

