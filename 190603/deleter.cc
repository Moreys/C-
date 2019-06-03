/*************************************************************************
  @FileName:  ./deleter.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Mon 03 Jun 2019 05:18:01 PM CST
 ************************************************************************/
#include <iostream>
#include <memory>

using namespace std;

struct FileCloser
{
    void operator()(FILE * fp) const
    {
        if(fp)
        {
            fclose(fp);
            cout << " << fclose(fp)" << endl;
        }
    }
};
void test0()
{
    unique_ptr<FILE, FileCloser> up(fopen("text.txt","a+"));
    string msg("this is a new lene\n");

}
int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

