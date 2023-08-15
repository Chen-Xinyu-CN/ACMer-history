#include <iostream>
#include <set>
using namespace std;
void PrintSet(const set<int>& s)
{
    for(set<int>::const_iterator it=s.begin();it!=s.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void test01()
{
    set<int> s1;
    //set插入数据只有insert方式
    s1.insert(10);s1.insert(40);s1.insert(30);s1.insert(20);
    s1.insert(30);
    //遍历容器
    //set容器特点：所有元素插入时候自动被排序
    //set容器不允许插入重复值
    PrintSet(s1);
    set<int> s2(s1);
    PrintSet(s2);
    set<int> s3;s3=s2;
    PrintSet(s3);
}
void test02()//set容器的大小和交换.set容器是不支持resize()操作的
{
    set<int> s1;
    //set插入数据只有insert方式
    s1.insert(10);s1.insert(40);s1.insert(30);s1.insert(20);
    s1.insert(30);
    PrintSet(s1);
    if(s1.empty()){
        cout<<"s1为空"<<endl;
    }
    else{
        cout<<"s1不为空"<<endl;
        cout<<"s1的大小为:"<<s1.size()<<endl;
    }
    set<int> s2;
    //set插入数据只有insert方式
    s2.insert(100);s2.insert(400);s2.insert(300);s2.insert(200);
    s2.insert(300);
    cout<<"交换前:"<<endl;
    PrintSet(s1);PrintSet(s2);
    cout<<"交换后:"<<endl;
    s1.swap(s2);
    PrintSet(s1);PrintSet(s2);
}
void test03()//set容器插入和删除
{
    set<int> s1;
    //set插入数据只有insert方式
    s1.insert(10);s1.insert(40);s1.insert(30);s1.insert(20);
    s1.insert(30);
    PrintSet(s1);
    //删除
    s1.erase(s1.begin());//给函数传入迭代器
    PrintSet(s1);
    //删除函数erase()重载版本
    s1.erase(30);
    PrintSet(s1);
    //s1.erase(s1.begin(),s1.end());
    s1.clear();
    PrintSet(s1);
}
void test04()//set容器的查找和统计
{
    set<int> s1;
    //set插入数据只有insert方式
    s1.insert(10);s1.insert(40);s1.insert(30);s1.insert(20);
    s1.insert(30);
    PrintSet(s1);
    //查找
    set<int>::iterator pos=s1.find(30);
    if(pos!=s1.end()){
        cout<<"找到了元素:"<<(*pos)<<endl;
    }
    else{
        cout<<"没找到"<<endl;
    }
    //统计个数 对于set而言，统计结果要么是0，要么是1
    int num=s1.count(200);
    cout<<"num = "<<num<<endl;
}
void test05()
{
    set<int> s;
    pair<set<int>::iterator,bool> ret=s.insert(10);
    if(ret.second){
        cout<<"第一次插入成功"<<endl;
    }
    else{
        cout<<"第一次插入失败"<<endl;
    }
    ret=s.insert(10);
    if(ret.second){
        cout<<"第二次插入成功"<<endl;
    }
    else{
        cout<<"第二次插入失败"<<endl;
    }
    multiset<int> ms;//允许重复插入
    ms.insert(10);ms.insert(10);ms.insert(10);ms.insert(10);
    for(multiset<int>::iterator it=ms.begin();it!=ms.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
//使用仿函数技术
class MyCompare
{
public:
    bool operator()(int v1,int v2) const//新版本编译器需要添加const
    {
        return v1>v2;
    }
};
void test06()//set容器排序，内置数据类型
{
    set<int,MyCompare> s2;
    s2.insert(10);s2.insert(20);s2.insert(30);
    s2.insert(40);s2.insert(50);
    for(set<int,MyCompare>::iterator it=s2.begin();it!=s2.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
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
class Compare
{
public:
    bool operator()(const Person&p1,const Person& p2) const;
};
bool Compare::operator()(const Person&p1,const Person& p2) const
{
    return p1.m_Age>p2.m_Age;
}
void test07()//set容器排序，存放自定义数据类型
{
    //对于自定义数据类型，需要指定排序规则,否则插入都无法插入
    Person p1("陆诗雨",19);Person p2("张亦菲",18);
    Person p3("白神",20);Person p4("崔神",21);
    set<Person,Compare> s;s.insert(p1);s.insert(p2);//运用仿函数
    s.insert(p3);s.insert(p4);
    for(set<Person,Compare>::iterator it=s.begin();it!=s.end();it++){
        cout<<"姓名: "<<it->m_Name<<" 年龄："<<it->m_Age<<endl;
    }
}
int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    test07();
    system("pause");
    return 0;
}