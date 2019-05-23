#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
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
    test0();
    //输出流，如果文件不存在，直接创建新文件；
    //如果文件存在会清空流的内容，再写的数据
    ofstream ofs("test.txt", std:: ios::app);
    if(!ofs)
    {
        cout << ">> ifstream open file error" << endl;
        return;
    }
    cout << "pos = " << ofs.tellp() << endl;
    ofs << "that's new line!" << endl;
#if 0
    for(auto & line : file)
    {
        ofs << line << "\n";
    }
#endif

    ofs.close();
}
void test2()
{
    //ate模式针对于输入流起作用
    ifstream ifs("test.txt", std::ios::ate);
    if(!ifs)
    {
        cout << "ifstream err" << endl;
        return;
    }
    cout << "pos = " << ifs.tellg() << endl;
    ifs.close();
}
void printCinStatus(fstream & fs)
{
    cout << "cin's badbit = " << fs.bad() << endl
        << "cin's failbit = " << fs.fail() << endl
        << "cin's sofbit = " << fs.eof() << endl
        << "cin's goodbit  = " << fs.good() << endl;
}
void test3()
{
    //必须要求文件存在
    fstream fs("test2.txt");//文件有内容会进行清空以后在继续写入。
    if(!fs) 
    {
        cout << "fstream file error" << endl;
        return;
    }
    int number;
    cout << "请输入十个数字" << endl;
    for(int idx =0; idx != 10; ++idx)
    {
        std::cin >> number;
        cout << number << endl;
        fs << number <<" "; //将读取到是数字写入到fs中
    }
    cout << "fs's pos = " << fs.tellg() << endl;
    cout << endl;
    fs.seekg(0);

    for(int idx = 0; idx != 10; ++idx)//遍历文件进行打印
    {
        fs >> number;
        cout << number << " ";
    }
    cout << endl;
    fs.close();
}

void test4()
{
   //从某个文件中取出全部的内容，保存到一个字符串中
   string filename = "vector.cc";
   ifstream ifs(filename, std::ios::ate);
   if(!ifs)
   {
       cout << ">> ifstream open fiel " << filename << "error!" << endl;
       return;
   }
   int length = ifs.tellg();
   cout << ">> length = " << length << endl;
   char * buff = new char[length + 1]();
   ifs.seekg(std::ios::beg);
   ifs.read(buff, length);//常用的到方法
   string content(buff);
   cout << "content:-------"
       << content << endl
       << "-------" << endl;
   delete  [] buff;
   ifs.close();
}
int main(void)
{
    //test0();
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}

