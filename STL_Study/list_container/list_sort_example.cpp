#include <iostream>
#include <list>
#include <string>
using namespace std;
//排序要求:按照年龄进行升序，如果年龄相同按照升高进行降序
class Person
{
public:
    string m_Name;int m_Age;int m_Height;
public:
    Person();
    Person(string name,int age,int height);
};
Person::Person()
{
    //空实现
}
Person::Person(string name,int age,int height)
{
    this->m_Name=name;this->m_Height=height;this->m_Age=age;
}
void PrintList(const list<Person>& l)
{
    for(list<Person>::const_iterator it=l.begin();it!=l.end();it++)
    {
        cout<<"姓名:"<<it->m_Name<<" 年龄:"<<it->m_Age<<" 身高:"
        <<it->m_Height<<"  ";
    }
    cout<<endl;
}
//高级排序只是在排序规则上再进行一次逻辑规则判定，并不复杂
bool myCompare(Person &p1,Person &p2)
{
    if(p1.m_Age==p2.m_Age)
    {
        return p1.m_Height>p2.m_Height;
    }
    return p1.m_Age<p2.m_Age;
}
void test01()
{
    list<Person>L1;//创建容器
    Person p1("陆诗雨",19,172);Person p2("张亦菲",19,164);
    Person p3("白神",20,168);Person p4("崔神",19,167);
    Person p5("young_dumb",17,171);
    L1.push_back(p1);L1.push_back(p2);L1.push_back(p3);
    L1.push_back(p4);L1.push_back(p5);
    cout<<"排序前:"<<endl;
    PrintList(L1);
    cout<<"------------------------------------------"<<endl;
    cout<<"排序后:"<<endl;
    //排序自定义数据类型需要指定排序规则
    L1.sort(myCompare);
    PrintList(L1);
}
int main()
{
    test01();
    system("pause");
    return 0;
}