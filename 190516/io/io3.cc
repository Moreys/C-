#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

void printCinStatus(stringstream & fs)
{
    cout << "cin's badbit = " << fs.bad() << endl
        << "cin's failbit = " << fs.fail() << endl
        << "cin's sofbit = " << fs.eof() << endl
        << "cin's goodbit  = " << fs.good() << endl;
}
void test0()
{
    int val1 = 1;
    int val2 = 2;
    stringstream ss;
    //把其他类型的数据转化成字符串
    ss << "val1 = " << val1 << ", val2 = " << val2;
    cout << ss.str() << endl;
    string str0;
    int value;
    printCinStatus(ss);
    //一旦流的状态发送改变时，会产生问题
    while(!ss.eof())
    {
        ss >> str0 >> value;
        printCinStatus(ss);
        cout << str0 <<"---->" << value << endl << endl;
    }
}
string int2str(int number)
{
    ostringstream oss;
    oss << number;
    return oss.str();
}
void readConfigguration(const string & filename)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << ">>> ifstream open file" << filename << "error" << endl;
        return;
    }
    string line;
    while(std::getline(ifs, line))
    {
        istringstream iss(line);
        string key, value;
        while(!iss.eof())
        {
            iss >> key >> value;
            cout << key << "------>" << value << endl;
        }
    }
}

void test1()
{
    int number = 1024;
    cout << int2str(number) << endl << endl;
    readConfigguration("my.conf");
}
int main()
{
//    test0();
    test1();
    std::cout << "Hello world" << std::endl;
    return 0;
}

