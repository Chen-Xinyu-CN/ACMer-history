#include <iostream>
#include <list>//STL中的链表是一个双向循环链表
//由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移
//和后移，属于双向迭代器
//list有一个重要的性质，插入和删除操作都不会造成原有的list迭代器失效
#include <algorithm>
using namespace std;
void PrintList(const list<int> L)
{
    for(list<int>::const_iterator it=L.begin();it!=L.end();it++){
        cout<<(*it)<<" ";
    }
    cout<<endl;
}
void test01()//list构造函数
{
    list<int>L1;
    L1.push_back(10);L1.push_back(20);
    L1.push_back(30);L1.push_back(40);L1.push_back(50);
    //遍历容器
    PrintList(L1);
    list<int>L2(L1.begin(),L1.end());
    PrintList(L2);
    list<int>L3(L2);
    PrintList(L3);
    list<int>L4(10,1000);
    PrintList(L4);
}
void test02()//list赋值和交换
{
    list<int> L1;
    L1.push_back(10);L1.push_back(20);
    L1.push_back(30);L1.push_back(40);L1.push_back(50);
    PrintList(L1);
    list<int>L2=L1;
    PrintList(L2);
    list<int>L3;L3.assign(L2.begin(),L2.end());
    PrintList(L3);
    list<int>L4;L4.assign(10,100);
    PrintList(L4);
    cout<<"交换前"<<endl;
    PrintList(L3);
    PrintList(L4);
    cout<<"交换后"<<endl;L3.swap(L4);
    PrintList(L3);PrintList(L4);
}
void test03()//list大小操作
{
    list<int> L1;
    L1.push_back(10);L1.push_back(20);
    L1.push_back(30);L1.push_back(40);L1.push_back(50);
    PrintList(L1);
    if(L1.empty()){
        cout<<"L1为空"<<endl;
    }
    else{
        cout<<"L1不为空"<<endl;
        cout<<"L1的元素个数为"<<L1.size()<<endl;
    }
    //重新指定大小
    L1.resize(10,100);PrintList(L1);
    L1.resize(2);PrintList(L1);
}
void test04()//list容器的插入和删除
{
    list<int> L1;
    L1.push_back(10);L1.push_back(20);
    L1.push_back(30);L1.push_back(40);L1.push_back(50);
    L1.push_front(100);L1.push_front(200);L1.push_front(300);
    L1.pop_back();L1.pop_front();
    //insert插入
    list<int>::iterator it=L1.begin();
    L1.insert(++it,1000);
    it=L1.begin();
    L1.erase(++it);
    L1.push_back(10000);L1.push_back(10000);L1.push_back(10000);
    PrintList(L1);
    L1.remove(10000);
    PrintList(L1);
    //清空
    L1.clear();
    PrintList(L1);
}
void test05()//list容器数据存取,只有front()和back()两种方式
{
    list<int> L1;
    L1.push_back(10);L1.push_back(20);
    L1.push_back(30);L1.push_back(40);L1.push_back(50);
    cout<<"该链表第一个元素为:"<<L1.front()<<endl;
    cout<<"该链表最后一个元素为:"<<L1.back()<<endl;
    //验证迭代器不支持随机访问
    list<int>::iterator it=L1.begin();
    it++;//支持双向
    it--;
    //it=it+1;//不支持随机访问
}
bool myCompare(int v1,int v2)
{
    //降序 就让第一个数>第二个数
    return v1>v2;
}
void test06()//list容器的反转和排序
{
    list<int> L1;
    L1.push_back(20);L1.push_back(10);
    L1.push_back(50);L1.push_back(40);L1.push_back(30);
    //反转算法
    cout<<"反转前："<<endl;
    PrintList(L1);
    L1.reverse();
    cout<<"反转后："<<endl;
    PrintList(L1);
    //排序算法
    cout<<"排序前:"<<endl;
    PrintList(L1);
    //所有不支持随机访问迭代器的容器，不可以用标准算法库中的算法
    //但是那些不支持随机访问迭代器的容器，内部会提供一些算法
    //sort(L1.begin(),L1.end());//错误示例
    cout<<"排序后:"<<endl;
    L1.sort(myCompare);//直接调用内部算法，默认排序规则，从小到大
    PrintList(L1);
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