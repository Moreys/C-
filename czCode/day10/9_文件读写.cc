/*************************************************************************
  @FileName:  ./9_文件读写.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 04 Jun 2019 11:21:50 PM CST
 ************************************************************************/
                                                                         
#include "fstream"
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main1()
{
    string  fname = "text.txt";
    ofstream fout(fname, ios::app); //创建一个输出流对象 和关联文件
    if(!fout)
    {
        cout << "打开失败" << endl;
        return -1;
    }
    fout << "hello.....111" << endl;
    fout << "hello.....111" << endl;
    fout << "hello.....111" << endl;
    fout << "hello.....111" << endl;
    fout << "hello.....111" << endl;

    fout.close();
    ifstream fin(fname);//建立一个输入流对象和文件关联
    char ch;
    while (fin.get(ch))
    {
        cout << ch;
    }
    fin.close();
    std::cout << "Hello world" << std::endl;
    return 0;
}

class Teacher
{
public:
    Teacher(int age = 32, string name)
    : _age(age)
    , _name(new [name.size() + 1]())
    {
    }
    Teacher(int age, char * name)
    {
        _age = age;
    }
    void printT()
    {
        cout << "age = " << _age << "name: " << _name << endl;
    }
    
private:
    int _age;
    string _name;
};

int main()
{
    string  fname = "text1.txt";
    ofstream fout(fname, ios::binary); //创建一个输出流对象 和关联文件
    if(!fout)
    {
        cout << "打开失败" << endl;
        return -1;
    }
    Teacher t1(31, "t31");
    Teacher t2(32, "t31");
    fout.write((char*)&t1, sizeof(Teacher));
    fout.write((char*)&t2, sizeof(Teacher));
    fout.close();


    ifstream fin(fname);//建立一个输入流对象和文件关联
    Teacher tmp;

    fin.read((char*) &tmp, sizeof(Teacher));
    tmp.printT();


    fin.read((char*) &tmp, sizeof(Teacher));
    tmp.printT();

    fin.close();
    std::cout << "Hello world" << std::endl;
    return 0;
}
