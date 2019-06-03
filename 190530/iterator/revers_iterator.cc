#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> numbers{1, 2, 3, 4, 5, 6};
    vector<int>::const_reverse_iterator rit;
    for(rit = numbers.rbegin(); rit != numbers.rend(); ++ rit)
    {
        cout << *rit << " ";
    }
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

