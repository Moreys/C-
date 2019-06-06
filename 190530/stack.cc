/*************************************************************************
  @FileName:  stack.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Thu 06 Jun 2019 09:24:02 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isValid(string s);
    void printT();
private:
    stack<char> _st;
};

void Solution::printT()
{
    while(!_st.empty())
    {
        cout << _st.top() << " ";
        _st.pop();
    }
    cout << endl;
}

bool Solution::isValid(string s)
{
    if(s.length() % 2 != 0) return false;
    //for(auto i = 0; i < s.length(); ++i)
    for(auto i : s)
    {
        switch(s[i])
        {
        case '[':
        case '(':
        case '{':
            _st.push(s[i]);
            break;
        case ')':
            if(_st.empty() || _st.top() != '(')
            {
                return false;
            }
            else
            {
                _st.pop();
            }
            break;
        case ']':
            if(_st.empty() ||_st.top() != '[')
            {
                return false;
            }
            else
            {
                _st.pop();
            }
            break;
        case '}':
            if(_st.empty() ||_st.top() != '{')
            {
                return false;
            }
            else
            {
                _st.pop();
            }
            break;
        default:
            break;
        }
    }
    if(!_st.empty())
    {
        return false;
    }
    else 
    {
    return true;
    }
}

int main()
{
    Solution s1;
    
   if(s1.isValid("(){}{}"))
   {
       cout << "是" << endl;
   }
   else
   {
        cout << "不是" << endl;
   }
    return 0;
}

