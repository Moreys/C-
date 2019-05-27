#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
using namespace std;
using std::ifstream;
using std::map;
using std::ofstream;

class Dictionary
{
public:

public:
    void read(const string & filename)
    {
        ifstream ifs(filename);
        if(!ifs)
        {
            cout << ">>>ifstream open file" << filename << "error" << endl;
            return ;
        }
        string line;
        while(ifs >> line)
        {
            map<string,size_t>::iterator it = _count.find(line);
            if(it == _count.end())
            {
                _count.insert(map<string, size_t>::value_type(line,1));    
            }
            else 
            {
                ++_count[line];
            }
        }
    }
    void store(const string & filename)
    {
        
        ofstream ofs(filename);
        if(!ofs)
        {
            cout << ">>>ifstream open file" << filename << "error" << endl;
            return ;
        }
        //写入有问题
       for(const auto &w : _count)
       {
        ofs << w.first << " " <<   w.second   << endl;
       }
    }
private:
   map<string, size_t> _count;
};
int main()
{
    Dictionary d1;
    d1.read("test.txt");
    d1.store("tt.txt");
    std::cout << "Hello world" << std::endl;
    return 0;
}

