/*************************************************************************
  @FileName:  ./SafeFile.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 09:25:29 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
class SafeFile
{
public:
    SafeFile(FILE * fp) : _fp(fp)
    {

    }
    void write(const string & msg)
    {
        fwrite(msg.c_str(), 1, msg.size(), _fp);
    }
    ~SafeFile()
    {
        if(_fp)
        {
            fclose(_fp);
        }
        cout << ">> fclose(_fp)" << endl;
    }
private:
    FILE * _fp;
};
int main()
{
    //申请的文件描述符会根据的对象的生命周期，最后调用析构函数进行自动释放
    SafeFile sf(fopen("test.txt", "a+"));
    sf.write("hello, world\n");
    std::cout << "Hello world" << std::endl;
    return 0;
}

