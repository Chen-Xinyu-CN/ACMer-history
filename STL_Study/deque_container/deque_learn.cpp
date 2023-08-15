#include <iostream>
#include <deque>//双端数组
#include <algorithm>//标准算法头文件
using namespace std;
void SetElemDeque(deque<int>& d)
{
    for(int i=0;i<10;i++){
        d.push_back(i);
    }
}
void PrintDeque(const deque<int>& d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        //const引用的话，必须采用const_iterator只读迭代器
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void test01()//deque构造函数操作
{
    deque<int> d1;
    SetElemDeque(d1);
    PrintDeque(d1);
    deque<int> d2(d1.begin(),d1.end());
    PrintDeque(d2);
    deque<int> d3(10,100);
    PrintDeque(d3);
    deque<int> d4(d3);
    PrintDeque(d4);
}
void test02()   //deque赋值操作
{
    deque<int> d1;
    SetElemDeque(d1);
    PrintDeque(d1);
    deque<int> d2=d1;
    PrintDeque(d2);
    //assign赋值
    deque<int> d3;
    d3.assign(d2.begin(),d2.end());
    PrintDeque(d3);
    deque<int> d4;
    d4.assign(10,100);
    PrintDeque(d4);
}
void test03()   //deque容器大小操作
{
    //与vector容器操作类似，但是deque没有容量的概念
}
void test04()//deque容器插入和删除
{
    deque<int> d1;
    SetElemDeque(d1);
    d1.push_back(100);d1.push_back(200);
    d1.push_front(300);d1.push_front(400);
    PrintDeque(d1);
    d1.pop_back();
    PrintDeque(d1);
    d1.pop_front();
    PrintDeque(d1);
    d1.insert(d1.begin(),1000);
    PrintDeque(d1);
    d1.insert(d1.begin(),2,2000);
    PrintDeque(d1);
    //按照区间来插入
    deque<int> d2;
    d2.push_back(1);d2.push_back(2);d2.push_back(3);
    d2.insert(d2.begin(),d1.begin(),d1.end());
    PrintDeque(d2);
    //删除单个元素
    d1.erase(d1.begin());
    PrintDeque(d1);
    //删除一个区间上的元素
    d1.erase(d1.begin(),(d1.end()-1));
    PrintDeque(d1);
}
void test05()//deque数据存取
{
    deque<int> d1;
    SetElemDeque(d1);d1.push_front(100);d1.push_front(200);
    d1.push_front(300);
    //通过[]方式访问元素
    for(int i=0;i<d1.size();i++){
        cout<<d1[i]<<" ";
    }
    cout<<endl;
    //通过at方式访问元素
    for(int i=0;i<d1.size();i++){
        cout<<d1.at(i)<<" ";
    }
    cout<<endl;
    cout<<"第一个元素为:"<<d1.front()<<endl;
    cout<<"最后一个元素为:"<<d1.back()<<endl;
}
void test06()//deque容器的排序
{
    deque<int> d1;
    d1.push_back(1);d1.push_back(3);d1.push_back(2);d1.push_back(4);
    d1.push_back(5);
    cout<<"未排序之前:"<<endl;
    PrintDeque(d1);
    //对于支持随机访问的迭代器的容器，都可以利用sort算法直接对其进行排序
    sort(d1.begin(),d1.end());//默认排序规则从小到大
    cout<<"排序之后:"<<endl;
    PrintDeque(d1);
}
int main()
{
    //test01();
    //test02();
    //test04();
    //test05();
    test06();
    system("pause");
    return 0;
}