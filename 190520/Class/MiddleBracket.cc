#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

class Buffer
{
public:
    Buffer(size_t sz) : _sz(sz), _data(new char[_sz]())
    {
        cout << "Buffer(size_t)" << endl;
    }
    size_t size()const
    {
        return strlen(_data);
    }
    size_t capacity() const
    {
        return _sz;
    }

    //第二个参数可以是任意类型
    char & operator[](size_t idx)
    {
        if(idx < capacity())
        {
            return _data[idx];
        }
        else
        {
            static char nullchar = '\0';
            cout << ">> error 下标越界!" << endl;
            return nullchar;
        }
    }
    ~Buffer()
    {
        if(_data)
        {
            delete [] _data;
        }
    }
private:
    size_t _sz;
    char * _data;
};

int main()
{
    std::string s1 = "hello world";
    const char * pstr = "hello world";

    cout << "pstr = " << pstr << endl;
    Buffer buffer(20);
    size_t sz = strlen(pstr);
    for(size_t idx = 0; idx != sz; ++idx)
    {
        buffer[idx] = pstr[idx]; //判断是否相等  循环遍历判断每一个
    }
    cout << "buffer中的数据是：";
    for(size_t idx = 0; idx != buffer.size(); ++idx)
    {
        cout << buffer[idx] << " " ;
    }
    cout << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

