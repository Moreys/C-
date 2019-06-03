#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*
 * 编写一个C++程序, 计算程序员( programmer  )工资
 *  1 要求能计算出初级程序员( junior_programmer  ) 
 *  中级程序员 ( mid_programmer  )高级程序员( adv_programmer )的工资
 *   2 要求利用抽象类统一界面,方便程序的扩展,
 *   比如:新增, 计算 架构师 (architect ) 的工资
 *      */
class Porgrammer
{
public:
    virtual void getSale() = 0;
};

class JuniorProg : public Porgrammer
{
public:
    JuniorProg(string name, string job, int sale)
                : _name(name)
                , _job(job)
                , _sale(sale)
    {
        cout << "Junior_prog()" << endl;
    }
    virtual void getSale()
    {
        cout << _name << " " << _job << " : " << _sale << endl;
    }
private:
    string _name;
    string _job;
    int _sale;
};

class MidProg : public Porgrammer
{
public:
    MidProg(string name, string job, int sale)
                : _name(name)
                , _job(job)
                , _sale(sale)
    {
        cout << "Junior_prog()" << endl;
    }
    virtual void getSale()
    {
        cout << _name << " " << _job << " : " << _sale << endl;
    }
private:
    string _name;
    string _job;
    int _sale;
};

class AdvProg : public Porgrammer
{
public:
    AdvProg(string name, string job, int sale)
                : _name(name)
                , _job(job)
                , _sale(sale)
    {
        cout << "Junior_prog()" << endl;
    }
    virtual void getSale()
    {
        cout << _name << " " << _job << " : " << _sale << endl;
    }
private:
    string _name;
    string _job;
    int _sale;
};

class ArcProg : public Porgrammer
{
public:
    ArcProg(string name, string job, int sale)
                : _name(name)
                , _job(job)
                , _sale(sale)
    {
        cout << "Junior_prog()" << endl;
    }
    virtual void getSale()
    {
        cout << _name << " " << _job << " : " << _sale << endl;
    }
private:
    string _name;
    string _job;
    int _sale;
};

void CalProgSal(Porgrammer * base)
{
    base->getSale();
}


int main()
{
    JuniorProg j1("momo" , "初级程序员", 4000);
    MidProg m1("mo", "中级程序员", 8900);
    AdvProg a1("m", "高级程序员", 15000);
    ArcProg e1("m", "架构师", 20000);

    CalProgSal(&j1);
    CalProgSal(&m1);
    CalProgSal(&a1);
    CalProgSal(&e1);
    return 0;
}
