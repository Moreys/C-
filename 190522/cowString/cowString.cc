#include "cowString.h"

CowString::CowString() : _pstr(new char[1 + 4]() + 4)
{
    cout << "CowString()" << endl;
    initRefcount(); //进行初始化
}

CowString::CowString(const char * pstr) : _pstr(new char[strlen(pstr) + 5]() + 4)
{
    initRefcount();
    strcpy(_pstr, pstr);
    cout << "CowString(const char * pstr)" <<endl; 
}

CowString::CowString(const CowString & rhs) : _pstr(rhs._pstr)
{
    cout << "CowString(const CowString & rhs)" << endl;
    increaseRefcount();//让前面统计的引用计数加1
}

//深拷贝三部曲 
//框架  释放空间   从新赋值
CowString & CowString::operator=(const CowString & rhs)
{
    cout << "CowString::operator=()" << endl;
    if(nullptr == _pstr)
    {
        release();//释放空间的
        _pstr = rhs._pstr;
        increaseRefcount();//引用计数加1
    }
    return *this;
}

CowString::~CowString()
{
    release();
}
CowString::CharProxy CowString::operator[](int idx)
{
    return CharProxy(idx, *this);
}

//下标访问运算符无法区分出接下来的操作是读操作  还是  写操作
//实现的只有写操作，没有考虑读操作的问题
char & CowString::CharProxy::operator=(const char & ch)
{
    cout << "CharProxy::operator=" << endl;
    //读时共享 判断条件，为
    int sz = _self.size();//通过第二个类来获取引用计数的大小
    if(_idx >= 0 && _idx < sz)//对比的Cow类中的本身的引用计数
    {
        if(_self.refcount() > 1)
        {
            _self.decreaseRefcount();
            char * ptmp = new char[sz+ 5]() + 4;
            strcpy(ptmp, _self._pstr);
            _self._pstr = ptmp;
            _self.initRefcount();
        }
        _self._pstr[_idx] = ch;//将字符串的位置信息返回到第二个类中然后进行赋值
        //最后找到字符串的位置所在进行显示
        return _self._pstr[_idx];
    }
    else
    {
        cout << "下标越界！" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
    
}

std::ostream & operator<<(std::ostream & os, const CowString & rhs)
{
    os << rhs._pstr;
    return os;
}

