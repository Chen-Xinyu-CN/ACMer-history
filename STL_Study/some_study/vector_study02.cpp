#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Person
{
public:
    Person();
    Person(string name,int age);
    ~Person();
public:
    string m_Name;int m_Age;
};
Person::Person(){//空实现
}
Person::Person(string name,int age)
{
    m_Name=name;m_Age=age;
}
Person::~Person(){//空实现
}
void test01()
{
    vector<Person> v01;
    //初始化与vector容器匹配的数据类型
    Person p1("陆诗雨",19);Person p2("张亦菲",19);Person p3("白神",20);
    Person p4("崔神",19);Person p5("铍神",19);
    //向容器内部尾插数据
    v01.push_back(p1);v01.push_back(p2);v01.push_back(p3);v01.push_back(p4);v01.push_back(p5);
    //遍历vector容器
    for(vector<Person>::iterator it=v01.begin();it!=v01.end();it++)
    {
        cout<<"姓名："<<it->m_Name<<" 年龄"<<it->m_Age<<endl;
    }
}
void test02()
{
    vector<Person*> v01;
    //初始化与vector容器匹配的数据类型
    Person p1("陆诗雨",19);Person p2("张亦菲",19);Person p3("白神",20);
    Person p4("崔神",19);Person p5("铍神",19);
    v01.push_back(&p1);v01.push_back(&p2);v01.push_back(&p3);v01.push_back(&p4);v01.push_back(&p5);
    for(vector<Person *>::iterator it=v01.begin();it!=v01.end();it++)
    {
        cout<<"姓名： "<<(*it)->m_Name<<" 年龄： "<<(*it)->m_Age<<endl;
    }
}
int main()
{
    test01();
    test02();
    system("pause");
    return 0;
}