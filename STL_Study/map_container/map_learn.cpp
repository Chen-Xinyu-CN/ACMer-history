#include <iostream>
#include <map>
using namespace std;
void PrintMap(const map<int,int>& m)
{
    for(map<int,int>::const_iterator it=m.begin();it!=m.end();it++)
    {
        cout<<" key = "<<it->first<<" value = "<<it->second<<endl;
    }
}
void test01()
{
    //map容器中会自动按照二元组中的key值进行排序,且不允许key值相同的键值对出现
    map<int,int> m;//亦称为键值对
    m.insert(pair<int,int>(1,10));m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));m.insert(pair<int,int>(4,40));
    PrintMap(m);
    map<int,int> m2(m);PrintMap(m2);
    map<int,int>m3;m3=m2;PrintMap(m3);
}
void test02()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));m.insert(pair<int,int>(4,40));
    PrintMap(m);
    if(m.empty()){
        cout<<"m为空"<<endl;
    }
    else{
        cout<<"m不为空"<<endl;
        cout<<"m的大小为:"<<m.size()<<endl;
    }
    map<int,int>m2;
    m2.insert(pair<int,int>(5,100));m2.insert(pair<int,int>(6,200));
    m2.insert(pair<int,int>(7,300));m2.insert(pair<int,int>(8,400));
    cout<<"交换前:"<<endl;
    PrintMap(m);PrintMap(m2);
    m2.swap(m);
    cout<<"交换后:"<<endl;
    PrintMap(m);PrintMap(m2);
}
void test03()//map插入和删除
{
    map<int,int> m;
    //第一种插入
    m.insert(pair<int,int>(1,10));m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));m.insert(pair<int,int>(4,40));
    //第二种
    m.insert(make_pair(5,50));
    //第三种
    m.insert(map<int,int>::value_type(6,60));
    //第四种
    m[7]=70;//[]在插入时不建议使用，可以利用[]搜索key来访问value
    //另外如果以这种方式cout的时候一开始的map容器中并没有该key元素，则会自动插入元素0
    PrintMap(m);
    cout<<"-------------------------------"<<endl;
    //删除
    m.erase(m.begin());
    m.erase(3);//按照key删除
    PrintMap(m);
    m.erase(m.begin(),m.end());
    PrintMap(m);
}
void test04()//map查找和统计
{
    map<int,int> m;
    m.insert(pair<int,int>(1,10));m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));m.insert(pair<int,int>(4,40));
    map<int,int>::iterator pos=m.find(3);
    if(pos!=m.end()){
        cout<<"找到了元素 key = "<<pos->first<<" value = "<<pos->second<<endl;
    }
    else{
        cout<<"没找到喵"<<endl;
    }
    int num=m.count(3);
    cout<<" num = "<<num<<endl;
}
class MyCompare
{
public:
    bool operator()(int v1,int v2) const;
};
bool MyCompare::operator()(int v1,int v2) const
{
    return v1>v2;
}
void test05()//map容器排序，利用仿函数
{
    map<int,int,MyCompare> m;
    m.insert(pair<int,int>(1,10));m.insert(pair<int,int>(2,20));
    m.insert(pair<int,int>(3,30));m.insert(pair<int,int>(4,40));
    m.insert(make_pair(5,50));
    for(map<int,int,MyCompare>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<" key = "<<it->first<<" value = "<<it->second<<endl;
    }
}
class Person
{
public:
    string m_Name;int m_Age;
public:
    Person(string name,int age);
};
Person::Person(string name,int age)
{
    m_Name=name;m_Age=age;
}
class MyCompare_Person
{
public:
    bool operator()(Person p1,Person p2) const;
};
bool MyCompare_Person::operator()(Person p1,Person p2) const
{
    return p1.m_Age<p2.m_Age;
}

void test06()
{
    Person p1("陆诗雨",19);Person p2("张亦菲",18);
    Person p3("白神",20);Person p4("崔神",21);
    map<Person,int,MyCompare_Person> m;
    m.insert(pair<Person,int>(p1,172));m.insert(pair<Person,int>(p2,164));
    m.insert(pair<Person,int>(p3,168));m.insert(pair<Person,int>(p4,167));
    for(map<Person,int,MyCompare_Person>::iterator it=m.begin();it!=m.end();it++)
    {
        cout<<" key_age = "<<(*it).first.m_Age<<" key_name = "<<(*it).first.m_Name<<" value = "<<it->second<<endl;
    }
}
int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    test06();
    system("pause");
    return 0;
}