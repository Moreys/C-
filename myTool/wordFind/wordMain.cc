/*************************************************************************
  @FileName:  wordMain.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 06 Jun 2019 10:22:07 PM CST
 ************************************************************************/
                                                                         
#include "TextQuery.h"
#include "QueryResult.h"

int main(int argc, char **argv)
{
    if(argc != 2 )
    {
        cout << "缺少参数" << endl;
        return -1;
    }
    ifstream ifs(argv[1]);
    TextQuery textQuery(ifs);
    while(true)
    {
        cout << "请输入需要查询的单词,按q退出：" << endl;
        string s;
        if(!(cin >> s) || s == "q")break;
        print(cout, textQuery.query(s)) << endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

