#include "testQuery.h"

void runQueries()
{
    while(true)
    {
        cout << "请输入需要查询的单词" << endl;
        string str;
        if(!(cin >> str) || str =="q") 
            break;
    }
}
int main()
{
    TestQuery tq;
    
    tq.readFile("test.dat");
    std::cout << "Hello world" << std::endl;
    return 0;
}

