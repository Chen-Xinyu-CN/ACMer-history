#include <iostream>
#include <vector>//每一个STL类型都要求引入头文件
#include <algorithm>//使用STL的算法，必须要引入算法头文件
using namespace std;
void MyPrint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    vector<int> v;
    //vector尾插入数据
    v.push_back(10);v.push_back(20);v.push_back(30);v.push_back(40);v.push_back(50);
    //使用迭代器
    vector<int>::iterator itBegin=v.begin();//v.begin()指向vector容器中的第一个数据位置
    vector<int>::iterator itEnd=v.end();//v.end()指向vector容器中的最后一个数据位置的后面一个位置
    //1.常规遍历方法
    while(itBegin!=itEnd)
    {
        cout<<*(itBegin)<<endl;
        itBegin++;
    }
    //2.STL提供的for_each遍历算法
    for_each(v.begin(),v.end(),MyPrint);
}
int main()
{
    test01();
    cout<<"中文输出测试！"<<endl;
    system("pause");//VsCode编程记得调用此程序函数
    return 0;
}