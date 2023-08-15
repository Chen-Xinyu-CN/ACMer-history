#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int>& v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void setelemVector(vector<int>&v)
{
    for(int i=0;i<10;i++) v.push_back(i+1);
}
void test01()//STL  vector容器的构造函数
{
    vector<int> v1;//默认构造
    setelemVector(v1);printVector(v1);
    //通过区间方式进行构造，使用其他的已经构造好的vector容器的v.begin(),v.end()信息
    vector<int> v2(v1.begin(),v1.end());
    printVector(v2);
    //n个elem方式构造
    vector<int>v3(10,100);//(int num,int elems)前者是个数，后者是元素
    printVector(v3);
    vector<int>v4(v3);
    printVector(v4);
}
void test02()//STL  vector容器赋值操作
{
    vector<int>v1;
    setelemVector(v1);printVector(v1);
    //1.赋值号=重载
    vector<int> v2;v2=v1;
    printVector(v2);
    //2.assign成员函数
    vector<int> v3;
    v3.assign(v2.begin(),v2.end());
    printVector(v3);
    //3.赋值n个elem元素,使用重载assign函数
    vector<int> v4;v4.assign(10,100);
    printVector(v4);
}
void test03()//STL vector容器的容量和大小
{
    vector<int> v1;
    setelemVector(v1);
    printVector(v1);
    if(v1.empty()) cout<<"容器v1为空."<<endl;
    else cout<<"容器v1不为空."<<endl;
    cout<<"v1的容量为:"<<v1.capacity()<<endl;
    cout<<"v1的大小为:"<<v1.size()<<endl;
    //重新指定大小
    v1.resize(15,11);
    printVector(v1);//如果重新指定的比原来长了，默认用0来填充
    v1.resize(5);
    printVector(v1);//如果重新指定的比原来的短了，那么超出部分会删除掉
}
void test04()//STL vector容器插入和删除,一些操作需要提供迭代器
{
    vector<int> v1;
    //尾插
    v1.push_back(10);v1.push_back(20);v1.push_back(30);v1.push_back(40);v1.push_back(50);
    printVector(v1);//迭代器遍历输出
    //尾删
    v1.pop_back();
    printVector(v1);
    //插入函数第一个参数是迭代器
    v1.insert(v1.begin(),100);
    printVector(v1);
    v1.insert(v1.begin(),2,1000);
    printVector(v1);
    v1.erase(v1.begin());
    printVector(v1);
    v1.erase(v1.begin(),v1.end());
    printVector(v1);
}
void test05()//STL vector容器数据存取
{
    vector<int> v1;
    setelemVector(v1);
    for(int i=0;i<v1.size();i++){
        cout<<v1[i]<<endl;
    }
    for(int i=0;i<v1.size();i++){
        cout<<v1.at(i)<<endl;
    }
    //获取第一个元素
    cout<<"第一个元素为:"<<v1.front()<<endl;
    //或许最后一个元素
    cout<<"第二个元素为:"<<v1.back()<<endl;
}
void test06()//STL vector互换容器
{
    vector<int> v1;
    setelemVector(v1);
    cout<<"v1容器与v2容器交换前:"<<endl;
    printVector(v1);
    vector<int> v2;
    for(int i=10;i>0;i--){
        v2.push_back(i);
    }
    printVector(v2);
    cout<<"v1容器与v2容器交换后:"<<endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
    //巧用swap函数可以实现内存收缩
    //例如
    vector<int> v3;
    for(int i=0;i<10000;i++){
        v3.push_back(i);
    }
    cout<<"v3容器的容量为:"<<v3.capacity()<<endl;
    cout<<"v3容器的大小为"<<v3.size()<<endl;
    v3.resize(3);
    printVector(v3);
    cout<<"v3容器的容量为:"<<v3.capacity()<<endl;
    cout<<"v3容器的大小为"<<v3.size()<<endl;
    vector<int>(v3).swap(v3);//使用匿名对象的技术
    printVector(v3);
    cout<<"v3容器的容量为:"<<v3.capacity()<<endl;
    cout<<"v3容器的大小为"<<v3.size()<<endl;
}
void test07()//STL vector容器预留空间，减少vector在动态扩展容量时的扩展次数
{
    vector<int> v1;v1.reserve(100000);
    int ct=0;int *p=NULL;
    for(int i=0;i<100000;i++){
        v1.push_back(i);
        if(p!=&v1[0]){
            p=&v1[0];ct++;
        }
    }
    cout<<"动态扩展次数为:"<<ct<<endl;
    //提前预留空间，利用reserve预留空间,适用数据量较大的情况
}
int main()
{
    //STL   vector容器是动态扩展的(找更大的内存空间,将原来的数据拷贝新空间，释放原空间)
    //vector容器的迭代器是支持随机访问的迭代器
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