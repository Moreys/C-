#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::fstream;
using std::string;
using std::vector;

vector<string> file;
void test0()
{
    ifstream ifs;
    ifs.open("io2.cc");//文件输入流要求文件必须存在
    if(!ifs.good())//成功返回非零，失败返回0
    {
        cout << ">> ifstream open file error" << endl;
        return;
    }
    string line;
    while(std::getline(ifs, line))//一行一行的读取ifs然后放到line中
    {
        cout << line << endl;//读到一行打印一行
        file.push_back(line);   
    }
    ifs.close();
}

void test1()
{

}
int main(void)
{
    test0();
    return 0;
}

