#ifndef __TESTQUERY_H__
#define __TESTQUERY_H__
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

using std::ifstream;
using std::ofstream;
using std::endl;
using std::cout;
using std::unordered_map;
using std::map;
using std::set;
using std::vector;
using std::string;

template <typename Container>
void display(const Container & c)
{
    for(auto & elem : c)
    {
        cout << elem << " ";
    }
    cout << endl;
}


class TestQuery
{
public:

public:
    void readFile(const string filename);
    void query(const string & word);
    
private:
    unordered_map<int, string> _lines;
    map<string, set<int>> _word2Line;
    map<string, int> dict;
};

//读取文件内容到内存中
//filename 文件名字
void TestQuery::readFile(const string filename)
{
    ifstream ifs(filename);
    if(!ifs)
    {
        cout << ">>> ifstream open file" << filename << "error" << endl;
        return;
    }
    string line;
    int idx = 1;
    while( getline(ifs,line))
    {
            
        _lines.insert(unordered_map<int, string>::value_type(1,line));
        _lines[idx++] = line;
    }
    string value;
    int idx2 = 1;
    while( getline(ifs, value))
    {
        istringstream sst(value);
        string key;
         set<int>number;
        while(sst >> key)
        {
            number.insert(idx2++);
            _word2Line[key] = number;
           auto ret =  _word2Line.insert({key,number});
           if(!ret.second)
          {
            number.insert(idx2++);
            _word2Line[key] = number;
          }
        }
    }
    for(map<string, set<int>>::iterator it = _word2Line.begin(); it != _word2Line.end(); ++ it)
    {
        set<int>st = it->second;
        for(auto &it1:it->second)
            cout << it1 << endl;
        
    }

}

//给定单词输出所有行
//word 给定的单词
void TestQuery::query(const string & word)
{

}


#endif
