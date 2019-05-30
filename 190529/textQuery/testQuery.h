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

template <typename Container>
void display(const Container & c)
{
    for(auto & elem : c)
    {
        cout << elem << " ";
    }
    cout << endl;
}

class QueryResult;
class TestQuery
{
public:

public:
    void readFile(const string filename);
    void query(const string & word);
    
private:
    vector<string> _file;
    map<string, set<

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
    set<int>temp;
    while( getline(ifs,line))
    {
        _lines.insert(unordered_map<int, string>::value_type(1,line));
        _lines[idx++];
        istringstream iss(line);
        string word;
        while(iss >> word)
        {
            _word2Line[word];
            temp.insert(idx);
        }
    }
    set<int>::iterator initert;
}

//给定单词输出所有行
//word 给定的单词
void TestQuery::query(const string & word)
{

}


#endif
