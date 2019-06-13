/*************************************************************************
  @FileName:  12_multimap.cc
  @Author:    morey
  @Email:     zymorey@gmail.com
  @Time:      Tue 11 Jun 2019 11:40:56 PM CST
 ************************************************************************/
                                                                         
#include <iostream>
#include <string>
#include <map>


using namespace std;

//Multimap 案例:
////1个key值可以对应多个valude  =分组 
////公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人） 
////人员信息有：姓名，年龄，电话、工资等组成
////通过 multimap进行 信息的插入、保存、显示
////分部门显示员工信息 

class Person
{
public:
    string _name;
    int _age;
    string _tel;
    double _saly;
};

void test1()
{
    Person p1, p2, p3, p4, p5;
    p1._name = "p1";
    p1._age = 1;

    p2._name = "p2";
    p2._age = 2;
    p3._name = "p2";
    p3._age = 3;
    p4._name = "p4";
    p4._age = 4;
    p5._name = "p5";
    p5._age = 5;

    multimap<string, Person> map2;
    
    //saly部门
    map2.insert(make_pair("saly", p1));
    map2.insert(make_pair("saly", p2));
    
    //development部门
    map2.insert(make_pair("development", p3));
    map2.insert(make_pair("development", p4));
    
    //financial部门
    map2.insert(make_pair("financial", p5));

    //查看里面的元素
    //必须要看里面的原因，
    for(multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); ++it)
    {
        //必须具体化
        cout << it->first << " = " << it->second._age << endl;
    }

    int num2 = map2.count("development");
    cout << "deelopmenet 部门人数" << num2 << endl;

    cout << "development 部门员工信息" << endl;
    multimap<string, Person>::iterator it2 = map2.find("development");
    
    int tag = 0;
    while(it2 != map2.end() && tag < num2)
    {
        cout << it2->first << " = " << it2->second._name << endl;
        it2++;
        tag++;
    }

}

void test2()
{
    Person p1, p2, p3, p4, p5;
    p1._name = "p1";
    p1._age = 1;

    p2._name = "p2";
    p2._age = 2;
    p3._name = "p2";
    p3._age = 3;
    p4._name = "p4";
    p4._age = 4;
    p5._name = "p5";
    p5._age = 5;

    multimap<string, Person> map2;
    
    //saly部门
    map2.insert(make_pair("saly", p1));
    map2.insert(make_pair("saly", p2));
    
    //development部门
    map2.insert(make_pair("development", p3));
    map2.insert(make_pair("development", p4));
    
    //financial部门
    map2.insert(make_pair("financial", p5));

    cout << "\n 按照条件 检索数据 进行修改" << endl;
    for(multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); ++it)
    {
        //遍历所有信息，发现有_age == 2 
        //就把名字改为n2
        if(it->second._age == 2)
        {
            it->second._name = "n2";
        }
    }
    //打印所有信息
    for(multimap<string, Person>::iterator it = map2.begin(); it != map2.end(); ++it)
    {
        cout << it->first << " = " << it->second._name << endl;
    }

}
int main()
{
    test2();
    std::cout << "Hello world" << std::endl;
    return 0;
}

